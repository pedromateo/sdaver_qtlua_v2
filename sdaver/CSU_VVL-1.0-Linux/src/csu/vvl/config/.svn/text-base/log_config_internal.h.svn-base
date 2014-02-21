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

#ifndef LOG_CONFIG_INTERNAL_H
#define LOG_CONFIG_INTERNAL_H

#include <csu/base/conf/log/log_config.h>

namespace csu {
namespace vvl {
namespace config {
namespace log {

    ///
    /// vvl logs
    ///

    /// Debug abs
    typedef csu::base::log::logger<true> abs_log_type;
    extern abs_log_type abs;

    /// Debug rules
    typedef csu::base::log::logger<true> rules_log_type;
    extern rules_log_type rules;

    /// Debug verif
    typedef csu::base::log::logger<true> verif_log_type;
    extern verif_log_type verif;

    ///
    /// Internal log configuration
    ///
    class  LogConfigInternal
    {
    public:
        /// initialization method
        static void initialize();
    };

}//log
}//config
}//vvl
}//csu

// Convenient alias
namespace _ilog = csu::vvl::config::log;

#endif // LOG_CONFIG_INTERNAL_H
