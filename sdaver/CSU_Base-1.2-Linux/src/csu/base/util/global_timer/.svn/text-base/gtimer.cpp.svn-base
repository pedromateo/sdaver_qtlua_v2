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
#include <csu/base/util/global_timer/gtimer.h>
#include <boost/thread.hpp>

#include <csu/base/conf/log/log_config.h>


namespace csu{
   namespace base{
      namespace util{
         namespace global_timer{

            ///
            /// reset the timer
            void GTimer::reset()
            {
               _log::time << "(GTimer::reset)" << std::endl;
               base_ = currentTime();
            }

            ///
            /// get the current time stamp
            unsigned long GTimer::getTimeStamp()
            {
               _log::time << "(GTimer::getTimeStamp)" << std::endl;
               return currentTime() - base_;
            }

            ///
            /// get the difference
            unsigned long GTimer::getTimeUntil(unsigned long until)
            {
               _log::time << "(GTimer::getTimeUntil)" << std::endl;
               unsigned long current = getTimeStamp();
               if (until <= current) return 0;
               return until - current;
            }

            ///
            /// sleep up to the given timestamp
            void GTimer::sleepUpTo(unsigned long upTo)
            {
               ///FIXME precision
               long timeToSleep = upTo - getTimeStamp();
               if (timeToSleep > /*0*/sleepThreshold_) boost::this_thread::sleep (boost::posix_time::milliseconds(timeToSleep));
               /*unsigned long timestamp = getTimeStamp();
   if (upTo > timestamp)
   {
      unsigned long timeToSleep = upTo - timestamp;
      _log::gtimer << "(GTimer::sleepUpTo) Sleeping " << timeToSleep << std::endl;
      boost::this_thread::sleep (boost::posix_time::milliseconds(timeToSleep));
   }*/
            }

            ///
            /// sleep threshold
            void GTimer::sleepThreshold(unsigned long st)
            {
               sleepThreshold_ = st;
            }

            ///
            /// sleep
            void GTimer::sleep(unsigned long msecs)
            {
               _log::time << "(GTimer::sleep)" << std::endl;
               if (msecs > 0)
               {
                  boost::this_thread::sleep (boost::posix_time::milliseconds(msecs));
               }
            }



            ///
            /// get the current time
            unsigned long GTimer::currentTime()
            {
               _log::time << "(GTimer::currentTime)" << std::endl;
               gettimeofday(&aux_,NULL);
               //_log::gtimer << "(GTimer::currentTime) " << (unsigned long)(aux_.tv_sec * 1000 + aux_.tv_usec / 1000) << std::endl;
               return (unsigned long)(aux_.tv_sec * 1000 + aux_.tv_usec / 1000);
            }

         }//global_timer
      }//util
   }//lib
}//csu
