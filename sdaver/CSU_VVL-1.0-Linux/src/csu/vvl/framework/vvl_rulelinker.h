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
#ifndef VVL_RULELINKER_H
#define VVL_RULELINKER_H

//log
#include <csu/vvl/config/log_config_internal.h>

#include "vvl_genericelementabstractor.h"
#include "vvl_rulemanager.h"
#include "vvl_verificationcontext.h"
#include "vvl_forward.h"
#include "vvl_rule.h"

#include <boost/unordered_map.hpp>


namespace csu {
namespace vvl {
namespace framework {

class RuleLinker
{
public:
    ///
    /// Constructor
    /// @param context is the verification context
    ///
    RuleLinker(VerificationContextPtr context);

    ///
    /// provides the linked rules of an element
    /// @param TODO
    ///
    const RuleList * getLinkedRules(const std::string &);

    ///
    /// update process method
    ///
    void updateRuleLinkMap();

private:
    ///
    /// variables
    ///
    typedef boost::shared_ptr<RuleList> RuleListPtr;
    typedef boost::unordered_map<std::string,RuleListPtr> RuleLinkMap;
    RuleLinkMap ruleLinkMap_;
    VerificationContextPtr context_;

private:
    ///
    /// debug method for printing the rules
    ///
    void printLinkedRules();

};

} //framework
} //validation
} //csu

#endif //VVL_RULELINKER_H
