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

#include <csu/base/util/circ_buffer/circ_buffer.h>

namespace csu {
   namespace base {
      namespace util {
         namespace circ_buffer{

            // NOTE: using the ensure and add methods together, this circular
            // buffer always ensures begin_ <= end_.

            circ_buffer::circ_buffer()
            {
               _init (16384); // default 16K
            }

            circ_buffer::circ_buffer(size_t sss)
            {
               _init (sss);
            }

            circ_buffer::~circ_buffer()
            {
               delete[] buffer_;
            }

            void circ_buffer::_init (size_t size)
            {
               size_ = 2*size;
               buffer_ = new char[size_];
               begin_ = end_ = 0;
            }

            /// Return a pointer that has at least size bytes
            char* circ_buffer::buffer_ensure (size_t want)
            {
               // First fast check. Enough space in the buffer?
               if (available() < want)
                  return NULL;

               // Easy case: end_ + want < size_. Return the buffer at the end
               if (end_ + want >= size_)
               {
                  // This is the worst case. There is space, but
                  // we have to move buffers to the beginning to make enough
                  // room
                  size_t actual_size = size();

                  // memmove allows memory overlapping
                  memmove (static_cast<void*>(buffer_),
                           static_cast<void*>(buffer_ + begin_),
                           actual_size);

                  // Buffer starts at 0 again. end_ = previous size.
                  end_ = actual_size;
                  begin_ = 0;
               }
               return buffer_ + end_;
            }

char* circ_buffer::pos() const
{
    return buffer_ + begin_;
}

            /// This is always called after a buffer_ensure, so we can safely
            /// add "more" to end_
            void circ_buffer::add (size_t more)
            {
               // TODO: check that this always holds
               // available() >= more
               end_ += more;
               // NOTE that we don't have to ensure that end_ < size_ too...
            }

            /// Read a buffer available
            char* circ_buffer::read (size_t want)
            {
               if (want > size())
                  return NULL;

               char* to_return = buffer_ + begin_;

               begin_ += want;
               // NOTE: again, no modulus
               return to_return;
            }

            size_t circ_buffer::size() const
            {
               return end_ - begin_;
            }

            size_t circ_buffer::available() const
            {
               return size_ - size();
            }

         } // circ_buffer
      } // util
   } // lib
} // csu
