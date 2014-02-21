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

#include "chs_verificationengine.h"
#include <boost/regex.hpp>

namespace csu {
namespace vvl {
namespace vlang {
namespace chs {

using namespace csu::vvl::framework;

Chai_VerificationEngine::Chai_VerificationEngine(VerificationContextPtr context)
    :GenericVerificationEngine(context)
{
    CHS_RESULT_VAR = "chai_result_variable";
}

///
/// interface implementation
///
void Chai_VerificationEngine::initialize()
{
    ///
    /// Init Lua interpeter
    ///

    chai_=new chaiscript::ChaiScript();


    /// call the registrar (it needs the chai interpreter pointer)
    boost::any chsInterpreter = chai_;
    boost::any result = context_->elementRegistrar->registerGUIElements(chsInterpreter);

    _ilog::verif << "(Chai_ValidationEngine::initialize) Finished." << std::endl;

}

bool Chai_VerificationEngine::handleEvent(const GenericEventAbstractionResult * ear)
{
    _ilog::verif <<"(Chai_VerificationEngine::handleEvent)"<<std::endl;

    GenericEventAbstractionResult * aux
            = const_cast<GenericEventAbstractionResult *>(ear);

    std::string element = aux->id();
    unsigned long event = aux->event();
    boost::any obj = aux->object();

    // Obtain rules for element
    RuleList * rl = ((RuleList *)context_->ruleLinker->getLinkedRules(element));

    if (!rl)
    {
        //context_->logManager->addToLog(event,element,*it,result);
        //FIXME this case represents the situation when the element is inside the elements list that
        //we want to examine but there is no rule associated to it. This situation allow us to
        //detect this and alert the srs expert
        _ilog::verif <<"(Chai_VerificationEngine::handleEvent) No rules for " << element <<std::endl;
        return true;
    }

    RuleList::iterator it;
    bool result;
    bool verificationRes=true;
    RuleList * failedRules = new RuleList();
    RuleList * successRules = new RuleList();


    _ilog::verif <<"(Chai_VerificationEngine::handleEvent) Interacted Widget "<<element<<std::endl;

    ///
    /// Verificate the rules and take actions with the result
    ///
    Rule::StringSet::const_iterator itWidgets;
    for(it = rl->begin() ; it != rl->end() ; it++){

        std::string code= (*it)->code();

        //In Chaiscript, it is not possible to register global variables, you can only register glboal const
        // To avoid this behavior, all functions are parsed to receive all widgets they interact, as parameters
        //Due to that fact also the return command must include those parameters in the call
        std::string parameters="(";

        itWidgets=(*it)->widgetNames().begin();
        for (;itWidgets!=(*it)->widgetNames().end();itWidgets++)
        {
            if (itWidgets!=(*it)->widgetNames().begin()){
                parameters+=",";
            }
            parameters+=*itWidgets;
        }
        parameters+=")";

        code= code + "\n return "+ (*it)->id()+parameters+";";

        _ilog::verif <<"(Chai_VerificationEngine::handleEvent) Checking Rule: \n "<<code<<std::endl;

        try
        {
            result = verificate(code);

            verificationRes=verificationRes && result;

            if (result)
                successRules->push_back((*it));
            else
                failedRules->push_back((*it));
        }
        catch(std::string e){

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

void Chai_VerificationEngine::finalize()
{
    resetEngine();
}

bool Chai_VerificationEngine::verificate(const std::string& rule) throw(std::string)
{
    // rule preprocessing
    std::string aux = rule;

    _ilog::verif << "Validating [" << aux << "]" << std::endl;

    // validation process

    bool result=true;

    try
    {
        result = chai_->eval<bool>(aux.c_str());
    }
    catch (const chaiscript::Eval_Error &e)
    {
        _ilog::verif << "Exception: " << e.what() << std::endl;
        throw (*(new std::string (e.what())));
    }

    return result;

}

///
/// Script-file loading method
bool Chai_VerificationEngine::loadScriptFile(std::istream& file)
{
    /// TODO
    /// TODO
}

///
/// Engine-context clear method
bool Chai_VerificationEngine::resetEngine()
{
    /// Close interpeter
    delete chai_;
}


} //chs
} //vlang
} //vvl
} //csu
