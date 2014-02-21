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
#include "rectangle.h"

namespace csu{
namespace qt{
namespace painters {

Rectangle::Rectangle(QRect coord,PaintingContext * pc) : Figure(pc)
{
    vertexs_=new QRect(coord.x(),coord.y(),coord.width(),coord.height());
}

Rectangle::Rectangle(int x1,int y1,int x2,int y2,PaintingContext * pc) : Figure(pc)
{
    vertexs_=new QRect(x1,y1,x2,y2);
}

Rectangle::~Rectangle(){}

void Rectangle::draw(QPainter * painter,PaintingContext * pc)
{

    QPen pen;

    if (pc)
    {        
        pen.setWidth(pc->lineWidth);
        pen.setBrush(pc->lineColor);

    }else{
        pen.setWidth(context_->lineWidth);
        pen.setBrush(context_->lineColor);

    }

    painter->setPen(pen);

    painter->drawRect(*vertexs_);

}

}
}
}
