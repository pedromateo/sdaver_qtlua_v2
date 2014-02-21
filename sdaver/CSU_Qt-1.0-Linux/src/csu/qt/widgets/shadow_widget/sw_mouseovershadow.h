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

#ifndef MOUSEOVERSHADOW_H
#define MOUSEOVERSHADOW_H

#include "shadowwidgetcomposite.h"
#include <csu/qt/painters/figurepainter.h>


namespace csu {
namespace qt {
namespace widgets {
namespace shadow_frame {


class MouseOverShadow : public ShadowWidgetComposite
{
    Q_OBJECT
    public:
        MouseOverShadow(ShadowFrame* parent, QWidget *decorated);
        ~MouseOverShadow();

    protected:

        ///
        ///handle the events received on the decorated widget
        bool eventFilter(QObject *obj, QEvent *e);


        void addMouseOverWidget(const ShadowWidget * shadowWidget);
        void addMouseOutWidget(const ShadowWidget * shadowWidget);

protected:
        bool onMouseOver_;

protected:
        ShadowList * mouseOverList_;
        ShadowList * mouseOutList_;

};

} //shadow_frame
} //widgets
} //qt
} //csu

#endif // MOUSEOVERSHADOW_H
