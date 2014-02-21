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
 */

#ifndef SW_MOMESSAGE_H
#define SW_MOMESSAGE_H

#include "sw_highlighter.h"
#include "sw_message.h"
#include "sw_mouseovershadow.h"

namespace csu {
namespace qt {
namespace widgets {
namespace shadow_frame {

class MOMessage : public MouseOverShadow
{

public:
        MOMessage(const std::string& message, ShadowFrame* parent, QWidget *decorated);


        void clearMessage();
        void addMessage(const std::string & message);
        void removeMessage(const std::string & message);
private:
        Message * message_;
};


} //shadow_frame
} //widgets
} //qt
} //csu

#endif // SW_MOMESSAGE_H
