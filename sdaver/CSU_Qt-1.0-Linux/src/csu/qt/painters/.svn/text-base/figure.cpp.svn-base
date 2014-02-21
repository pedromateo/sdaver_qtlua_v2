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

#include "figure.h"

namespace csu{
namespace qt{
namespace painters {


Figure::Figure(PaintingContext * pc)
{
        context_=new Figure::PaintingContext();
    if (pc){

        context_->lineColor=pc->lineColor;
        context_->lineWidth=pc->lineWidth;
        context_->backColor=pc->backColor;
        context_->textColor=pc->textColor;
        context_->sizeRatio=pc->sizeRatio;
        context_->transparency=pc->transparency;
        context_->gridSize=pc->gridSize;
        context_->maskScope=pc->maskScope;
    }else{
        //Default context
        context_->lineColor=Qt::black;
        context_->lineWidth=1;
        context_->backColor=Qt::white;
        context_->textColor=Qt::black;
        context_->sizeRatio=1;
        context_->transparency=0;
        context_->gridSize=0;
        context_->maskScope=0;
    }
}

Figure::~Figure(){}

const Figure::PaintingContext * Figure::context()
{
    return context_;
}

void Figure::context(const PaintingContext * pc)
{
    context_->lineColor=pc->lineColor;
    context_->lineWidth=pc->lineWidth;
    context_->backColor=pc->backColor;
    context_->textColor=pc->textColor;
    context_->sizeRatio=pc->sizeRatio;
    context_->transparency=pc->transparency;
    context_->gridSize=pc->gridSize;
    context_->maskScope=pc->maskScope;
}

void Figure::draw(QPainter *, PaintingContext *){}

}
}
}
