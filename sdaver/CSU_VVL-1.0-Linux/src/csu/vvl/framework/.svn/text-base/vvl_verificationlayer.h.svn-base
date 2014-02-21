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

#ifndef VVL_VERIFICATIONLAYER_H
#define VVL_VERIFICATIONLAYER_H

//log
#include <csu/vvl/config/log_config_internal.h>


#include "vvl_forward.h"
#include "vvl_verificationcontext.h"
#include "vvl_eventobserver.h"
#include "vvl_ruleobserver.h"

namespace csu {
namespace vvl {
namespace framework {

class VerificationLayer : public RuleObserver, public EventObserver
{
public:

    ///
      /// Constructor
      /// @param context is the verification context
      ///
    VerificationLayer(VerificationContextPtr context);

    virtual void updateRules();
    virtual void updateElements(const std::string & windowName);
    virtual void updateCreateElements(const std::string & windowName){}
    virtual void updateDeleteElements(const std::string & windowName){}
    void init();

protected:

   virtual void createRuleManager(void) = 0;
   virtual void createElementAbstractor(void) = 0;
   virtual void createRuleLinker(void) = 0;
   virtual void createElementRegistrar(void) = 0;
   virtual void createVerificationEngine(void) = 0;
   virtual void createLogManager(void) = 0;
   virtual void createInterventor(void) = 0;
   virtual void createEventAbstractor(void) = 0;

protected:
    VerificationContextPtr context_;

};

} //framework
} //validation
} //csu

#endif // VVL_VERIFICATIONLAYER_H
