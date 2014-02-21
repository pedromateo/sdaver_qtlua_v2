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

#ifndef VVL_GENERICEVENTABSTRACTOR_H
#define VVL_GENERICEVENTABSTRACTOR_H

//log
#include <csu/vvl/config/log_config_internal.h>

#include "vvl_verificationcontext.h"
#include "vvl_eventobservable.h"

#include "vvl_forward.h"

namespace csu {
namespace vvl {
namespace framework {

    ///
    /// Event flags
    ///
    typedef enum
    {
        VVL_EVENT_FOCUSOUT = 1,
        VVL_EVENT_FOCUSIN = 2,
        VVL_EVENT_MOUSEPRESS = 4,
        VVL_EVENT_MOUSECLICK = 8,
    } TriggerEvents;

    ///
    /// GenericEventAbstractor interface
    ///
    class GenericEventAbstractor : public EventObservable
    {
    public:
        ///
        /// Constructor
        /// @param context is the verification context
        ///
        GenericEventAbstractor(VerificationContextPtr context);
        virtual ~GenericEventAbstractor();

        ///
        /// Method for installing processes
        ///
        virtual void install() = 0;

        ///
        /// Method for uninstalling processes
        ///
        virtual void uninstall() = 0;

    protected:
        /// a reference to the context object
        VerificationContextPtr context_;
    };

} //framework
} //validation
} //csu

#endif // VVL_GENERICEVENTABSTRACTOR_H
