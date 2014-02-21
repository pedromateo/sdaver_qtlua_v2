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

#include "app_utils.h"
#include <iostream>
#include <fstream>
#include <cassert>

namespace csu {
    namespace base {
        namespace util {

            ///
            /// app_utils
            /// Several utils related to applications.
            ///

            ///
            /// checks if a file is executable
            ///
            bool app_utils::isExecutable(const std::string& file)
            {
                std::ifstream inp;

                inp.open(file.c_str(), std::ifstream::in);
                inp.close();

                //if it does not exists...
                if(inp.fail())
                {
                    return false;
                }
                //if it exists, check if the file is a valid executable
                else
                {
                    //if it is executable return true
                    if (true)//TODO
                    {
                        return true;
                    }
                    //else, return false
                    return false;
                }
                return false;
            }


            ///
            /// returns the current directory
            ///
            std::string app_utils::getCurrentDir()
            {
                char cCurrentPath[FILENAME_MAX];

                if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
                {
                    std::cout << "(app_utils::getCurrentDir) ERROR while retrieving currant directory." << std::endl;
                    assert(0);
                }

                cCurrentPath[sizeof(cCurrentPath) - 1] = '\x0'; /* not really required */

                std::string path(cCurrentPath);
                return path;
            }

        }//util
    }//lib
}//csu


