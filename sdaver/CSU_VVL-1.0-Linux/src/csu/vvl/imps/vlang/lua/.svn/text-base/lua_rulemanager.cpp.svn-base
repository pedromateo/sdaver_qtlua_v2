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

#include "lua_rulemanager.h"

namespace csu {
namespace vvl {
namespace vlang {
namespace lua {

using namespace csu::vvl::framework;

Lua_RuleManager::Lua_RuleManager(VerificationContextPtr context)
    :RuleManager(context)
{
    widgetLeftDels_.push_back("@");
    widgetRightDels_.push_back(":");
    createWidgetRegex();
    //functionDefs_.push_back("\S([a-zA-Z0-9_-]+)(\s)=(\s)([a-zA-Z0-9_-]+)(\s)$");
    functionDefs_.push_back("function( )+([a-zA-Z0-9_\(\)]+)(.*?)end");
    functionDefs_.push_back("rule( )+([a-zA-Z0-9_-]+)(.*?)end( )+rule");
    comment_ = "--";
    suffix_ = ".lua";
}

Lua_RuleManager::~Lua_RuleManager(){}

std::string Lua_RuleManager::functionHeader(const std::string & funcName,
                                            const Rule::StringSet * widgets,
                                            const std::string & globalNamespace)
{
    if (funcName.find('(') != std::string::npos
            && funcName.find(')') != std::string::npos)
        return "function "+funcName;
    else
        return "function "+funcName+"()";
}

std::string Lua_RuleManager::functionEnd()
{
    return "end";
}
} //lua
} //vlang
} //vvl
} //csu
