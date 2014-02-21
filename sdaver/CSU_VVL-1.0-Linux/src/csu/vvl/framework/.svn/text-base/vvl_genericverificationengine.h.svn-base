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

#ifndef VVL_GENERICVERIFICATIONENGINE_H
#define VVL_GENERICVERIFICATIONENGINE_H

//log
#include <csu/vvl/config/log_config_internal.h>

#include "vvl_verificationcontext.h"
#include "vvl_forward.h"
#include "vvl_genericeventabstractionresult.h"

#include <iostream>

namespace csu {
namespace vvl {
namespace framework {

///
/// GenericVerificationEngine interface
///
class GenericVerificationEngine
{
public:
    ///
    /// Constructor
    /// @param context is the verification context
    ///
    GenericVerificationEngine(VerificationContextPtr context);
    virtual ~GenericVerificationEngine();
public:
  ///
  /// Initialization method
  ///
    virtual void initialize() = 0;

    ///
    /// Handle event method
    /// @param event is the received event
    /// @param element is the element that receives the event
    ///
    virtual bool handleEvent(const GenericEventAbstractionResult *) = 0;

    ///
    /// Finalization method
    ///
    virtual void finalize() = 0;

protected:

  ///
  /// Verification method
  /// @param rule is the rule to be verificated
  ///
  virtual bool verificate(const std::string& rule) = 0;

  ///
  /// Script-file loading method
  /// @param file is the file (input stream) to be loaded
  ///
  virtual bool loadScriptFile(std::istream& file) = 0;

  ///
  /// Engine-context clear method
  ///
  virtual bool resetEngine() = 0;

  protected:
    /// a reference to the context object
    VerificationContextPtr context_;
};

} //framework
} //validation
} //csu

#endif // VVL_GENERICVERIFICATIONENGINE_H
