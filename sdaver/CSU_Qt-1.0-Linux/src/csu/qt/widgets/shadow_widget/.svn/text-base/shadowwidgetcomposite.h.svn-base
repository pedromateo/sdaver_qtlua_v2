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

#ifndef SHADOWWIDGETCOMPOSITE_H
#define SHADOWWIDGETCOMPOSITE_H

#include "shadowwidget.h"
#include <boost/shared_ptr.hpp>
#include <boost/ptr_container/ptr_list.hpp>

namespace csu {
namespace qt {
namespace widgets {
namespace shadow_frame {


class ShadowWidgetComposite : public ShadowWidget
{
public:
    ShadowWidgetComposite(ShadowFrame * parent, QWidget *decorated);
    ~ShadowWidgetComposite();

    void setBackgroundColor(QColor color);

protected:    
    virtual void paintEvent( QPaintEvent * event );

protected:

    ShadowList * visibleShadowList_;
    ShadowList * invisibleShadowList_;

};

} //shadow_frame
} //widgets
} //qt
} //csu
#endif // SHADOWWIDGETCOMPOSITE_H
