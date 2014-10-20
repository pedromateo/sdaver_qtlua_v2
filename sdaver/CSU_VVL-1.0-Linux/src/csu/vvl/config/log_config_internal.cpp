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
*
*/

#include "log_config_internal.h"

namespace csu {
namespace vvl {
namespace config {
namespace log {

    ///
    /// vvl logs
    ///


    rules_log_type rules("rules");
    verif_log_type verif("verif");

    ///
    /// Internal log configuration
    ///
    void LogConfigInternal::initialize()
    {
        ///
        /// csu_lib logs
        ///

        //we'll use
//        _log::misc << csu::base::log::on;
        _log::error << csu::base::log::on;
        _log::perf << csu::base::log::on;
//        _log::gui << csu::base::log::on;
//        //we won't use
//        _log::comm << csu::base::log::off;
//        _log::time << csu::base::log::off;
//        _log::control << csu::base::log::off;
//
//        ///
//        /// internal logs
//        ///

        _ilog::rules.add_stream (std::cout);
        _ilog::rules << csu::base::log::on;
//        _ilog::verif.add_stream (std::cout);
//        _ilog::verif << csu::base::log::on;
    }

}//log
}//config
}//vvl
}//csu
