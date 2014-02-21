// -*- mode: c++; c-basic-offset: 4; c-basic-style: bsd; -*-
/*
*   This program is free software; you can redistribute it and/or
*   modify
*   it under the terms of the GNU Lesser General Public License as
*   published by the Free Software Foundation; either version 3.0 of
*   the License, or (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU Lesser General Public License for more details.
*
*   You should have received a copy of the GNU Lesser General Public
*   License along with this library; if not, write to the Free Software
*   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
*   02111-1307 USA
*
*   This file is part of the Aspect-Oriented GUI Verification Library,
*   http://sourceforge.net/projects/guiverification/
*
*/

#include "lua_verificationengine.h"
#include <boost/regex.hpp>

namespace csu {
namespace vvl {
namespace vlang {
namespace lua {


Lua_VerificationEngine::Lua_VerificationEngine(VerificationContextPtr context)
:GenericVerificationEngine(context)
{
    luaInited_ = false;    
}

///
/// interface implementation
///

void Lua_VerificationEngine::initialize()
{
    ///
    /// Init Lua interpeter
    ///    
    state_ = lua_open();
    luaL_openlibs(state_);
    luabind::open(state_);  // extra for luabind

    /// call the registrar (it needs the lua state pointer)
    boost::any state_p_obj = state_;
    boost::any result = context_->elementRegistrar->registerGUIElements(state_p_obj);

    _ilog::verif << "(Lua_ValidationEngine::initialize) Finished." << std::endl;

}


bool Lua_VerificationEngine::handleEvent(const GenericEventAbstractionResult * ear)
{
    _ilog::verif <<"(Lua_VerificationEngine::handleEvent)"<<std::endl;

    GenericEventAbstractionResult * aux=const_cast<GenericEventAbstractionResult *>(ear);

    std::string element=aux->id();
    unsigned long event=aux->event();
    boost::any obj=aux->object();

    // Obtain rules for element
    RuleList * rl = ((RuleList *)context_->ruleLinker->getLinkedRules(element));

    if (!rl)
    {
        //context_->logManager->addToLog(event,element,*it,result);
        //FIXME this case represents the situation when the element is inside the elements list that
        //we want to examine but there is no rule associated to it. This situation allow us to
        //detect this and alert the srs expert        
        _ilog::verif <<"(Lua_VerificationEngine::handleEvent) No rules for " << element <<std::endl;
        return true;
    }

    RuleList::iterator it;
    bool result;
    bool verificationRes=true;
    RuleList * failedRules = new RuleList();
    RuleList * successRules = new RuleList();

    _ilog::verif <<"(Lua_VerificationEngine::handleEvent) Interacted Widget "<<element<<std::endl;

    // Verificate the rules and take actions with the result
    for(it = rl->begin() ; it != rl->end() ; it++){

        std::string code= (*it)->code();
        code= code + "\n return "+ (*it)->id()+"()";

        _ilog::verif <<"(Lua_VerificationEngine::handleEvent) Checking Rule: \n "<<code<<std::endl;        

        try
        {
            result = verificate(code);
            verificationRes=verificationRes && result;

            if (result)
                successRules->push_back((*it));
            else{
                failedRules->push_back((*it));
            }

        }catch(std::string e){

            // FIXME CHECK LOG THE EXCEPTION
            //context_->logManager->doLog(vr);

            std::string err;
            err="Syntax Error: \n";
            err+=" -- File: "+(*it)->file()+"\n";
            err+=" -- Rule: "+(*it)->id()+"\n";
            err+=" -- Error: "+e;
            context_->guiInterventor->doException(err);
            return false;
        }
    }


    VerificationResult vr(event,element,obj,successRules,failedRules);
    // Actions with the result
    context_->logManager->doLog(vr);    
    context_->guiInterventor->doAction(vr);


    if (verificationRes)
        _ilog::verif <<"Verification Successfull!!"<<std::endl;
    else
        _ilog::verif <<"Verification Unsuccessfull!!"<<std::endl;    

    return verificationRes;
}

void Lua_VerificationEngine::finalize()
{
    resetEngine();
}

bool Lua_VerificationEngine::verificate(const std::string& rule) throw(std::string)
{
    // rule preprocessing
    std::string aux = rule;

    _ilog::verif << "Validating [" << aux << "]" << std::endl;

    // validation process
    int error = -1;

    //Number of elements inside the stack before execution
    int stackElements=lua_gettop(state_);

    try
    {
        error = luaL_dostring(state_,aux.c_str());
    }
    catch (std::exception e)
    {
        _ilog::verif << "Exception: " << e.what() << std::endl;
    }

    if(error)
    {
        //_log::error << "C++: Error while evaluating: " << lua_tostring(state_, -1) << std::endl;
        std::string errMess=lua_tostring(state_, -1);
        lua_pop(state_, 1);  // pop error message from the stack
        throw (errMess);
        return false;
    }else
    {
        bool globalresult=true;

        //Number of elements inside the stack after execution which are the function results
        stackElements=lua_gettop(state_)-stackElements;

        for (int i=0;i<stackElements;i++){
            /// get the result
            bool result = false;
            if (lua_isboolean(state_, -1))
            {
                result = lua_toboolean(state_, -1);
            }
            // let other ways to return the result
            else
            {
                if (lua_isnumber(state_, -1) &&
                    lua_tointeger(state_,-1) == 1)
                {
                    result = true;
                }
                else if (lua_isstring(state_, -1) &&
                     strcmp(lua_tostring(state_,-1),"true")==0)
                {
                    result = true;
                }
            }
            globalresult=globalresult && result;
            ///
            /// lua puts the result value in the top of the
            /// stack. So, the -1 value has to be checked.
            ///
            // erase value
            lua_pop(state_, 1);


        }
        return globalresult;
    }

}

///
/// Script-file loading method
bool Lua_VerificationEngine::loadScriptFile(std::istream& file)
{
    /// TODO
    /// TODO
}

///
/// Engine-context clear method
bool Lua_VerificationEngine::resetEngine()
{
    /// Close interpeter
    /// It closes the application
    lua_close(state_);
}


} //lua
} //vlang
} //vvl
} //csu
