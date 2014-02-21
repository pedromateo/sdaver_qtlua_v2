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
 *   This file is part of the OHTu-Open Usability Evaluation Framework,
 *   http://sourceforge.net/projects/ohtu/
 *
 */

#ifndef APP_UTILS_H
#define APP_UTILS_H

#include <string>

/// for directory methods
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#define PATH_SEPARATOR '\\'
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#define PATH_SEPARATOR '/'
#endif

namespace csu {
   namespace base {
      namespace util {

         ///
         /// app_utils
         /// Several utils related to applications.
         ///
         class app_utils{
         public:
            ///
            /// checks if a file is executable
            ///
            static bool isExecutable(const std::string& file);


            ///
            /// returns the current directory
            ///
            static std::string getCurrentDir();

         };//app_utils

      }//util
   }//lib
}//csu

#endif //APP_UTILS_H

