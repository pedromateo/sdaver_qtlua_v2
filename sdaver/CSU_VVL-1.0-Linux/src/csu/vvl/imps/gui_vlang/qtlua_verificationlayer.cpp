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

#include "qtlua_verificationlayer.h"

namespace csu {
namespace vvl {
namespace gui_vlang {
namespace qt_lua {


QtLua_VerificationLayer::QtLua_VerificationLayer(VerificationContextPtr vc) : VerificationLayer(vc)
{}

QtLua_VerificationLayer::QtLua_VerificationLayer(VerificationContext& vc) : VerificationLayer(vc)
{}

QtLua_VerificationLayer::~QtLua_VerificationLayer(){}

void QtLua_VerificationLayer::createRuleManager(void)
{
    _ilog::verif <<"QtLua_VerificationLayer: Creating the Lua Rule Manager"<<std::endl;
    context_->ruleManager.reset(new csu::vvl::vlang::lua::Lua_RuleManager(context_));
}

void QtLua_VerificationLayer::createElementAbstractor(void)
{
    _ilog::verif <<"QtLua_VerificationLayer: Creating the Qt Element Abstractor"<<std::endl;
    context_->elementAbstractor.reset(new csu::vvl::gui::qt::QtElementAbstractor(context_));
}

void QtLua_VerificationLayer::createRuleLinker(void)
{
    _ilog::verif <<"QtLua_VerificationLayer: Creating the RuleLinker"<<std::endl;
    context_->ruleLinker.reset(new RuleLinker(context_));
}

void QtLua_VerificationLayer::createElementRegistrar(void)
{
    _ilog::verif <<"QtLua_VerificationLayer: Creating the QTLUAElement Registrar"<<std::endl;
    context_->elementRegistrar.reset(new csu::vvl::gui_vlang::qt_lua::QtLua_ElementRegistrar(context_));
}

void QtLua_VerificationLayer::createVerificationEngine(void)
{
    _ilog::verif <<"QtLua_VerificationLayer: Creating the LUA Validation Engine"<<std::endl;
    context_->verificationEngine.reset(new csu::vvl::vlang::lua::Lua_VerificationEngine(context_));
}

void QtLua_VerificationLayer::createInterventor(void)
{
    _ilog::verif <<"QtLua_VerificationLayer: Creating the Qt Gui Interventor"<<std::endl;
    context_->guiInterventor.reset(new csu::vvl::gui::qt::Qt_GuiInterventor(context_));
}

void QtLua_VerificationLayer::createEventAbstractor(void)
{
    _ilog::verif <<"QtLua_VerificationLayer: Creating the Qt Event Abstractor"<<std::endl;
    context_->eventAbstractor.reset(new csu::vvl::gui::qt::Qt_EventAbstractor(context_));
}

void QtLua_VerificationLayer::createLogManager(void)
{
    _ilog::verif <<"QtLua_VerificationLayer: Creating the Log Manager"<<std::endl;
    context_->logManager.reset(new LogManager(context_));
}

void QtLua_VerificationLayer::updateElements(const std::string & windowName)
{

    //This function is called whenever is needed to reload the gui elements
    //First: call the event abstractor in order to reload the gui elements
    context_->elementAbstractor->updateElements();
    //Second: call the rule linker to update the rule map to the new elements
    context_->ruleLinker->updateRuleLinkMap();

    //some times in Lua the stack and the global table of the lua state become corrupt
    //whith this change, whenever the dynamic widget list change, maybe due to a new dialog creation,
    //the present lua state at the verification engine is closed and and a new one is created.
    context_->verificationEngine->finalize();

    //Third: register the new element map (Inside the initalize function there is a call
    // to the element registrar)
    context_->verificationEngine->initialize();

    context_->guiInterventor->updateGUI(windowName);
}

} //qt_lua
} //gui_vlang
} //vvl
} //csu
