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

#ifndef VVL_LOGMANAGER_H
#define VVL_LOGMANAGER_H

//log
#include <csu/vvl/config/log_config_internal.h>

#include "vvl_forward.h"

#include <boost/ptr_container/ptr_set.hpp>

namespace csu {
namespace vvl {
namespace framework {

#include <csu/base/log/log.hpp>

    ///
    /// LogManager class
    ///
class LogManager
{
public:
    ///
      /// Constructor
      /// @param context is the verification context
      ///
    LogManager(VerificationContextPtr context);
    virtual ~LogManager();

    ///
    /// installation methods
    ///
    void install();
    void uninstall();

    ///
    /// adds a new entry in the log
    ///
    std::string doLog(const VerificationResult&);

protected:
    ///
    /// prints the result in all the log outputs
    ///
    void dispatchResult(const std::string& r);

private:
    /// verification context
    VerificationContextPtr context_;
    /// log object
    csu::base::log::logger<true> log_;
    /// log files streams
    typedef boost::ptr_set<std::ofstream> StreamSet;
    StreamSet files_;
};

} //framework
} //validation
} //csu

#endif // VVL_LOGMANAGER_H
