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

#ifndef __CIRC_BUFFER_H
#define __CIRC_BUFFER_H

#include <cstring> // size_t, memmove

namespace csu{
   namespace base{
      namespace util{
         namespace circ_buffer{

            class circ_buffer
            {
               char *buffer_;
               size_t begin_, end_;
               size_t size_;

            public:
               circ_buffer();
               circ_buffer (size_t size);
               ~circ_buffer();

    // Actual buffer pos.
    char* pos() const;

               // Return a buffer that ensures at least "want" consecutive
               // chars. Once the client processes it, he or she must call "add"
               // with the actual ammount of data added to the buffer
               char* buffer_ensure (size_t want);

               // The client has added some data ("more" characters) to the
               // buffer previously given by buffer_ensure
               void add (size_t more);

               // Signal that the client is going to consume "want" bytes from
               // the buffer (he or she has already processed them)
               char* read (size_t want);

               // Actual size used in the buffer
               size_t size() const;

               // bytes left in the buffer
               size_t available() const;

            private:
               void _init (size_t size);
            };

         }//circ_buffer
      }//util
   }// lib
}//csu

#endif
