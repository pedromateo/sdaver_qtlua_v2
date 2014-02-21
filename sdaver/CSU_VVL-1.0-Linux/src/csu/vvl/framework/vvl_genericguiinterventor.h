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

#ifndef VVL_GENERICGUIINTERVENTOR_H
#define VVL_GENERICGUIINTERVENTOR_H

//log
#include <csu/vvl/config/log_config_internal.h>
#include "vvl_verificationresult.h"
#include "vvl_verificationcontext.h"
#include "vvl_forward.h"

namespace csu {
namespace vvl {
namespace framework {

    ///
    /// GUI Decoration flags
    ///
    typedef enum
    {
        VVL_GUI_RED = 1,
        VVL_GUI_BLUE = 2,
        VVL_GUI_GREEN = 4,
        VVL_GUI_YELLOW = 8
    } GUIDecorationColor;

    typedef enum
    {
        VVL_GUI_CLEAR = 1,
        VVL_GUI_HIGHLIGHT_ERROR = 2,
        VVL_GUI_HIGHLIGHT_RELATED = 4,
        VVL_GUI_SHOW_SUCCESS_RULES = 8,
        VVL_GUI_SHOW_ERROR_RULES = 16
    } GUIDecorationAction;

    ///
    /// GenericGuiInterventor interface
    ///
class GenericGuiInterventor
{
public:
    ///
      /// Constructor
      /// @param context is the verification context
      ///
    GenericGuiInterventor(VerificationContextPtr context);
    virtual ~GenericGuiInterventor();

    // Methods
    virtual void doAction(const VerificationResult& vr) = 0;
    virtual void doException(const std::string & str) = 0;
    virtual void install()=0;
    virtual void updateGUI(const std::string & windowName)=0;

protected:
  /// a reference to the context object
  VerificationContextPtr context_;

};

} //framework
} //validation
} //csu

#endif // VVL_GENERICGUIINTERVENTOR_H
