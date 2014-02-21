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

#include "shadowframe.h"
#include <csu/qt/painters/figurepainter.h>

namespace csu {
namespace qt {
namespace widgets {
namespace shadow_frame {

//ShadowFrame::ShadowFrame(){
//    ShadowFrame(0,0,false);
//}

ShadowFrame::ShadowFrame(QWidget *parent, Qt::WindowFlags  flags,
                         QColor * color,bool startPainting):QFrame(parent,flags)
{
    this->setObjectName(parent->objectName()+"_ShadowFrame");

    if (parent){
        parent_=parent;

        //Overlap the shadow frame with its parent visible area
        this->setGeometry(0,0,parent->width(),parent->height());
    }

    if (color){
        QPalette p;
        p.setColor(this->backgroundRole(),*color);

        this->setPalette(p);
        this->setAutoFillBackground(true);
    }else{
        //Set the shadowframe fully transparent
        this->setAttribute(Qt::WA_TranslucentBackground);
    }


    this->setAttribute(Qt::WA_TransparentForMouseEvents);

    this->show();

    enablePainting_=startPainting;

    figureMap_.clear();

}

ShadowFrame::~ShadowFrame(){}

void ShadowFrame::enablePainting(bool v)
{
    this->clear();
    enablePainting_=v;
    this->update();
}

bool ShadowFrame::enablePainting(void)
{
    return enablePainting_;
}

void ShadowFrame::paintFigure(const std::string & name,Figure * figure)
{
    //FigureMap::iterator it;
    if (figureMap_.find(name)==figureMap_.end()){
        figureMap_[name]=figure;
    }else{
        figureMap_[name]->context(figure->context());
    }

    this->update();
}

void ShadowFrame::removeFigure(const std::string & name)
{
    FigureMap::iterator it;

    if ((it=figureMap_.find(name))!=figureMap_.end()){
        figureMap_.erase(it);
    }
    this->update();
}

void ShadowFrame::paintEvent(QPaintEvent *event)
{
    using namespace csu::qt::painters;

    if (enablePainting_==false)
        return;

    painter_ = new QPainter(this);

    //Paint the whole figure list

    FigureMap::iterator itFig=figureMap_.begin();

    for (;itFig!=figureMap_.end();itFig++){
        itFig->second->draw(painter_);
    }

    painter_->end();

}

void ShadowFrame::clear()
{
    figureMap_.clear();
    this->update();
}



}
}
}
}
