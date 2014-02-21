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
#ifndef GTIMER_H
#define GTIMER_H

#include <sys/time.h>

namespace csu{
   namespace base{
      namespace util{
         namespace global_timer{

            typedef struct timeval Time;

            class GTimer
            {
            public:

               GTimer() : sleepThreshold_(0), base_(0)
               {
               }
               ~GTimer(){}

               ///
               /// reset the timer
               void reset();

               ///
               /// get the current time stamp
               unsigned long getTimeStamp();

               ///
               /// get the difference
               unsigned long getTimeUntil(unsigned long);

               ///
               /// sleep up to the given timestamp
               void sleepUpTo(unsigned long);

               ///
               /// sleep threshold
               void sleepThreshold(unsigned long);

               ///
               /// sleep
               static void sleep(unsigned long);

            private:
               ///
               /// get the current time
               unsigned long currentTime();

               //base time
               unsigned long base_;
               unsigned long sleepThreshold_;
               Time aux_;
            };

         }//global_timer
      }//util
   }//lib
}//csu

#endif // GTIMER_H
