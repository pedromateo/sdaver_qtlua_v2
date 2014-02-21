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

#include "vvl_verificationlayer.h"


#include <cassert>

namespace csu {
namespace vvl {
namespace framework {

VerificationLayer::VerificationLayer(VerificationContextPtr context)
{
    context_=context;
}

void VerificationLayer::init()
{
    //Fixed creation order
    createRuleManager();
    assert(context_->ruleManager.get());

    createElementAbstractor();
    assert(context_->elementAbstractor.get());

    createRuleLinker();
    assert(context_->ruleLinker.get());

    createLogManager();
    assert(context_->logManager.get());

    createInterventor();
    assert(context_->guiInterventor.get());

    createElementRegistrar();
    assert(context_->elementRegistrar.get());

    createVerificationEngine();
    assert(context_->verificationEngine.get());

    createEventAbstractor();
    assert(context_->eventAbstractor.get());    

    //Loading rules from files
    context_->ruleManager->updateRules();

    //Extracting and filtering existing gui elements
    context_->elementAbstractor->updateElements();

    //Linking loaded rules to existing widgets
    context_->ruleLinker->updateRuleLinkMap();

    //Installing the Event Abstractor
    context_->eventAbstractor->install();

    //Initializing the Verification Engine
    context_->verificationEngine->initialize();

    //Installing the painting shadow frame
    context_->guiInterventor->install();

    //Installing the Log Manager
    context_->logManager->install();

    //Registering rule and event observers
    context_->ruleManager->registerObserver(this);
    context_->eventAbstractor->registerObserver(this);

}

void VerificationLayer::updateRules()
{    
    _ilog::verif <<"(VerificationLayer::updateRules) Updating rules"<<std::endl;

    //Linking loaded rules to existing widgets
    context_->ruleLinker->updateRuleLinkMap();

}

void VerificationLayer::updateElements(const std::string & windowName)
{

    _ilog::verif <<"(VerificationLayer::updateRules) Updatings Elements"<<std::endl;
    //This function is called whenever is needed to reload the gui elements
    //First: call the event abstractor in order to reload the gui elements
    context_->elementAbstractor->updateElements();
    //Second: call the rule linker to update the rule map to the new elements
    context_->ruleLinker->updateRuleLinkMap();
    //Third: register the new element map
    context_->elementRegistrar->updateGUIElementRegister();
    context_->guiInterventor->updateGUI(windowName);



}

} //framework
} //validation
} //csu
