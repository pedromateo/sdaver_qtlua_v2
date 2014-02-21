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

#include "sw_mouseovershadow.h"

namespace csu {
namespace qt {
namespace widgets {
namespace shadow_frame {


    using namespace csu::qt::painters;
    ///
    /// constructors
    ///
    MouseOverShadow::MouseOverShadow(ShadowFrame* parent, QWidget *decorated)
        : ShadowWidgetComposite(parent,decorated)
    {
        onMouseOver_ = false;
        ///mouse over lists
        mouseOverList_ = new ShadowList();
        mouseOutList_ = new ShadowList();
        ///composite lists
        visibleShadowList_ = mouseOutList_;
        invisibleShadowList_ = mouseOverList_;
    }

    MouseOverShadow::~MouseOverShadow()
    {
        mouseOverList_->clear();
        mouseOutList_->clear();
        //FIXME TODO delete both list?        

    }

    ///
    /// handle the events received on the decorated widget
    ///
    /// FIXME los comentarios para el doxygen se ponene en el .h
    /// porque así luego es más fácil echarle un vistazo a la doc
    bool MouseOverShadow::eventFilter(QObject *obj, QEvent *e)
    {
        /// call the parent filter
        ShadowWidget::eventFilter(obj,e);

        /// implement our own filter
        if (e->type() == QEvent::Enter)
        {
            //turn visible the over widgets
            onMouseOver_ = true;
            visibleShadowList_=mouseOverList_;
            invisibleShadowList_=mouseOutList_;            
        }
        else if (e->type() == QEvent::Leave)
        {
            //turn visible the out widgets
            onMouseOver_ = false;
            this->visibleShadowList_=mouseOutList_;
            this->invisibleShadowList_=mouseOverList_;

        }

        //return false for not to handle the message
        return false;
    }

    void MouseOverShadow::addMouseOverWidget(const ShadowWidget * shadowWidget)
    {
        mouseOverList_->push_back(ShadowWidgetPtr(const_cast<ShadowWidget *>(shadowWidget)));
    }

    void MouseOverShadow::addMouseOutWidget(const ShadowWidget * shadowWidget)
    {
        mouseOutList_->push_back(ShadowWidgetPtr(const_cast<ShadowWidget *>(shadowWidget)));
    }

} //shadow_frame
} //widgets
} //qt
} //csu
