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

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QPainter>
#include <csu/qt/painters/figure.h>

namespace csu{
namespace qt{
namespace painters {


class Rectangle : public Figure
{
public:

    Rectangle(QRect,PaintingContext * = 0);
    Rectangle(int x1,int y1,int x2,int y2,PaintingContext * =0);
    virtual ~Rectangle();


    //I set this method as virtual in case future implementations use this class as base class
    virtual void draw(QPainter *,PaintingContext *);

private:
    QRect * vertexs_;
};

}
}
}

#endif // RECTANGLE_H
