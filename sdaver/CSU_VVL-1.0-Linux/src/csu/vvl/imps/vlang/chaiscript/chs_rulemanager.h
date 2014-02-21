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

#ifndef CHS_RULEMANAGER_H
#define CHS_RULEMANAGER_H

#include <csu/vvl/framework/vvl_rulemanager.h>
namespace csu {
namespace vvl {
namespace vlang {
namespace chs {

using namespace csu::vvl::framework;

class Chai_RuleManager : public RuleManager
{
//private:
//    typedef std::set<std::string> StringSet;

public:
    ///
      /// Constructor
      /// @param context is the verification context
      ///
    Chai_RuleManager(VerificationContextPtr context);
    virtual ~Chai_RuleManager();

    //std::string ruleCodePreprocessor(const std::string & funcName,const std::string & funcCode,const Rule::StringSet * widgets);
    std::string functionHeader(const std::string & funcName,const Rule::StringSet * widgets,const std::string & globalNamespace);
    std::string functionEnd();
};

} //chai
} //vlang
} //vvl
} //csu

#endif // CHS_RULEMANAGER_H
