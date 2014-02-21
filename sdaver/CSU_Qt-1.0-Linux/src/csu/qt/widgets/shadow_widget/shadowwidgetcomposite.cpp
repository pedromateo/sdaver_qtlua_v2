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

#include "shadowwidgetcomposite.h"

namespace csu {
namespace qt {
namespace widgets {
namespace shadow_frame {

    ShadowWidgetComposite::ShadowWidgetComposite(ShadowFrame* parent, QWidget *decorated)
        :ShadowWidget(parent,decorated)
    {
        visibleShadowList_=new ShadowList();
        invisibleShadowList_=new ShadowList();
    }

    ShadowWidgetComposite::~ShadowWidgetComposite()
    {
        visibleShadowList_->clear();
        invisibleShadowList_->clear();
    }

    void ShadowWidgetComposite::paintEvent( QPaintEvent * event )
    {
        ShadowList::iterator it;

        //Set to visible all widgets in visibleShadowList
        for (it=visibleShadowList_->begin();it!=visibleShadowList_->end();it++)
        {            
            (*it)->setVisible(true);
        }

        //Set to invisible all widgets in invisibleShadowList
        for (it=invisibleShadowList_->begin();it!=invisibleShadowList_->end();it++)
        {            
            (*it)->setVisible(false);
        }

    }

    void ShadowWidgetComposite::setBackgroundColor(QColor color)
    {
        ShadowList::iterator it;

        for (it=visibleShadowList_->begin();it!=visibleShadowList_->end();it++)
        {
            (*it)->setBackgroundColor(color);
        }

        for (it=invisibleShadowList_->begin();it!=invisibleShadowList_->end();it++)
        {
            (*it)->setBackgroundColor(color);
        }
    }

} //shadow_frame
} //widgets
} //qt
} //csu
