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

#include "chs_rulemanager.h"

namespace csu {
namespace vvl {
namespace vlang {
namespace chs {

using namespace csu::vvl::framework;

Chai_RuleManager::Chai_RuleManager(VerificationContextPtr context)
:RuleManager(context)
{
    leftDels_.push_back("@");
    rightDels_.push_back(".");
    createWidgetRegex();
    functionDefs_.push_back("rule( )+([a-zA-Z0-9_-]+)(.*?)end( )+rule");
    comment_ = "//";
    suffix_ = ".chai";
}

Chai_RuleManager::~Chai_RuleManager(){}

std::string Chai_RuleManager::functionHeader(const std::string & funcName,const Rule::StringSet * widgets,const std::string & globalNamespace)
{
    //In Chaiscript, it is not possible to register global variables, you can only register global const
    // To avoid this behavior, all functions are parsed to receive all widgets they interact, as parameters
    //Due to that fact also the return command must include those parameters in the call

    std::string parameters="(";
    Rule::StringSet::const_iterator it=widgets->begin();

    for (;it!=widgets->end();it++)
    {
        if (it!=widgets->begin()){
            parameters+=",";
        }
        parameters+=(*it);
    }
    parameters+=")";

    return "def "+funcName+parameters+" {\n";
}
std::string Chai_RuleManager::functionEnd()
{
    return "\n}";
}

} //chs
} //vlang
} //vvl
} //csu
