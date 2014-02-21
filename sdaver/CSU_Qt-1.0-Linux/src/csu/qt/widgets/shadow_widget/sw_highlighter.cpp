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

#include "sw_highlighter.h"
#include <QPainter>
#include <QPen>
#include <QTime>
#include <QPainter>


namespace csu {
namespace qt {
namespace widgets {
namespace shadow_frame {

using namespace csu::qt::painters;

///
/// constructor
///
Highlighter::Highlighter(ShadowFrame* parent, QWidget *decorated,bool visible)
    : ShadowWidget(parent, decorated,visible)
{
    this->setObjectName(decorated->objectName()+"_Highlighter");
    //customize the painting context
    pcontext_.backColor = QColor(112,179,248);
    pcontext_.lineColor = QColor(9,95,184);
    pcontext_.transparency = 44;
    pcontext_.penStyle = Qt::SolidLine;
    pcontext_.capStyle = Qt::RoundCap;
    pcontext_.canvas = this;
    pcontext_.region = QRect(0,0,this->width()-1,this->height()-1);

}

///
/// paint event
///

void Highlighter::paintEvent( QPaintEvent * event )
{
    //update geometry according to the parent geometry
     this->resize(decorated_->width(),decorated_->height());
     pcontext_.region = QRect(0,0,this->width()-1,this->height()-1);

     //do painting
     FigurePainter::highlight(pcontext_);
}


} //shadow_frame
} //widgets
} //qt
} //csu
