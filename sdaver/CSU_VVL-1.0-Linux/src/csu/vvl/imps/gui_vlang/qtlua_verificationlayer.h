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

#ifndef QTLUA_VERIFICATIONLAYER_H
#define QTLUA_VERIFICATIONLAYER_H

#include <csu/vvl/framework/vvl_verificationlayer.h>
#include <csu/vvl/imps/gui/qt/qt_elementabstractor.h>
#include <csu/vvl/imps/gui_vlang/qtlua_elementregistrar.h>
#include <csu/vvl/imps/vlang/lua/lua_verificationengine.h>
#include <csu/vvl/imps/gui/qt/qt_guiinterventor.h>
#include <csu/vvl/imps/gui/qt/qt_eventabstractor.h>
#include <csu/vvl/imps/vlang/lua/lua_rulemanager.h>

namespace csu {
namespace vvl {
namespace gui_vlang {
namespace qt_lua {

using namespace csu::vvl::framework;

class QtLua_VerificationLayer : public VerificationLayer
{
public:

    ///
    /// Constructor
    /// @param context is the verification context
    ///

    QtLua_VerificationLayer(VerificationContextPtr);
    QtLua_VerificationLayer(VerificationContext&);
    virtual ~QtLua_VerificationLayer();

    virtual void updateElements(const std::string & windowName);

    virtual void createRuleManager(void);
    virtual void createElementAbstractor(void);
    virtual void createRuleLinker(void);
    virtual void createElementRegistrar(void);
    virtual void createVerificationEngine(void);
    virtual void createInterventor(void);
    virtual void createEventAbstractor(void);
    virtual void createLogManager(void);
};

} //qt_lua
} //gui_vlang
} //vvl
} //csu

#endif // QTLUA_VERIFICATIONLAYER_H
