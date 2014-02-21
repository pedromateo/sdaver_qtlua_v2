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

#ifndef LUA_VERIFICATIONENGINE_H
#define LUA_VERIFICATIONENGINE_H

#include <csu/vvl/framework/vvl_verificationcontext.h>
#include <csu/vvl/framework/vvl_verificationresult.h>

#include <lua.hpp>
#include <luabind/luabind.hpp>

#include <boost/algorithm/string/find.hpp>
#include <boost/any.hpp>

namespace csu {
namespace vvl {
namespace vlang {
namespace lua {

using namespace csu::vvl::framework;

class Lua_VerificationEngine : public GenericVerificationEngine
{
public:
      ///
      /// Constructor
      /// @param context is the verification context
      ///
    Lua_VerificationEngine(VerificationContextPtr context);
    virtual void initialize();
    virtual bool handleEvent(const GenericEventAbstractionResult * ear);
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
    bool luaInited_;
    lua_State *state_;    

};

} //lua
} //vlang
} //vvl
} //csu

#endif // LUA_VERIFICATIONENGINE_H
