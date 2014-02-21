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

#ifndef CHS_VERIFICATIONENGINE_H
#define CHS_VERIFICATIONENGINE_H

#include <csu/vvl/framework/vvl_verificationcontext.h>
#include <csu/vvl/framework/vvl_verificationresult.h>
#include <csu/vvl/framework/vvl_genericeventabstractionresult.h>

#include <chaiscript/chaiscript.hpp>
#include <boost/algorithm/string/find.hpp>
#include <boost/any.hpp>

namespace csu {
namespace vvl {
namespace vlang {
namespace chs {

using namespace csu::vvl::framework;

class Chai_VerificationEngine : public GenericVerificationEngine
{
public:
      ///
      /// Constructor
      /// @param context is the verification context
      ///
    Chai_VerificationEngine(VerificationContextPtr context);
    virtual void initialize();
    virtual bool handleEvent(const GenericEventAbstractionResult *);
    virtual void finalize();

protected:
    virtual bool verificate(const std::string& rule) throw(std::string);

    ///
    /// Script-file loading method
    virtual bool loadScriptFile(std::istream& file);

    ///
    /// Engine-context clear method
    virtual bool resetEngine();

    /// variables
private:   
    chaiscript::ChaiScript *chai_;
    std::string CHS_RESULT_VAR;

};

} //chs
} //vlang
} //vvl
} //csu

#endif // CHS_VERIFICATIONENGINE_H
