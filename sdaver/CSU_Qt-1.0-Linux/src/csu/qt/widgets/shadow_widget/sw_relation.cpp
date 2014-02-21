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

#include "sw_relation.h"
#include <csu/qt/painters/figurepainter.h>
#include "sw_highlighter.h"

#include <assert.h>

namespace csu {
namespace qt {
namespace widgets {
namespace shadow_frame {

using namespace csu::qt::painters;

Relation::Relation(ShadowFrame * layer, QWidget *decorated,const ShadowMapRelated * related,bool visible)
:ShadowWidget(layer,decorated,visible)
{    
    this->setObjectName(decorated->objectName()+"_Relation");    

    //customize the painting context
    pcontext_.backColor = Qt::red;
    pcontext_.lineColor = Qt::red;
    pcontext_.transparency = 50;
    pcontext_.penStyle = Qt::SolidLine;
    pcontext_.capStyle = Qt::RoundCap;
    pcontext_.canvas = this;
    QPoint dpos=decorated_->mapTo(this->parentWidget()->parentWidget(),QPoint(0,0));
    pcontext_.region = QRect(dpos.x(),dpos.y(),decorated_->width(),decorated_->height());

    //Changing context to draw related widgets
    relatedcontext_.backColor = Qt::yellow;
    relatedcontext_.lineColor = Qt::yellow;
    relatedcontext_.transparency = 50;
    relatedcontext_.penStyle = Qt::SolidLine;
    relatedcontext_.capStyle = Qt::RoundCap;
    //Default related canvas
    relatedcontext_.canvas =this;

    this->resize(layer->width(),layer->height());

    //Extract the widget list from the shadow frame list    
    ShadowMapRelated::const_iterator it=related->begin();
    for (;it!=related->end();it++)
    {       
        relatedWidget_.push_back(it->first);
        relatedShadowFrames_[it->first]=it->second;
        if (it->first->topLevelWidget()!=decorated_->topLevelWidget()){
            Highlighter * aux=new Highlighter(it->second,it->first,false);
            aux->setBackgroundColor(Qt::yellow);
            externRelated_.push_back(ShadowWidgetPtr(aux));
        }
    }    
    locate();

}

void Relation::locate(void){
    //First we get the point (0,0) of the decorated widget
    QPoint p=this->parentWidget()->mapTo(this->parentWidget(),QPoint(0,0));
    //Then we move the decoration widget wherever we want, using the decorated widget
    //origins point as reference system
    this->move(p.x(),p.y());

}

Relation::~Relation(){
    externRelated_.clear();
}

///
/// paint event
///

void Relation::paintEvent(QPaintEvent * event)
{

    QPoint dpos=decorated_->mapTo(this->topLevelWidget(),QPoint(0,0));
    pcontext_.region = QRect(dpos.x(),dpos.y(),decorated_->width(),decorated_->height());


    FigurePainter::highlight(pcontext_);

    if (relatedWidget_.empty()){
        //FIXME TODO
        //Draw an arc to the decorated object

    }else{
        QPoint relpos;

        foreach(QWidget * w, relatedWidget_)
        {

            //Calculating the right position of the related object
            relpos=w->mapTo(w->topLevelWidget(),QPoint(0,0));

            if (w->topLevelWidget()==decorated_->topLevelWidget()){


                //Inserting the new region at the painting context                
                relatedcontext_.region = QRect(relpos.x(),relpos.y(),w->width(),w->height());

                //Painting
                FigurePainter::highlight(relatedcontext_);

                //We only paint the relation line if both widget are located at the same window
                if (w->topLevelWidget()!=decorated_->topLevelWidget())
                    continue;

                QPoint dest;
                QPoint orig;
                //Watching related widget position
                if (relpos.y()+w->height()<dpos.y()){
                    //Related Widget is above the decorated widget
                    dest.setX(relpos.x()+(w->width()/2));
                    dest.setY(relpos.y()+w->height());

                    orig.setX(dpos.x()+(decorated_->width()/2));
                    orig.setY(dpos.y());
                }else if (relpos.y()> (dpos.y()+decorated_->height()))
                {
                    //Related widget is below the decorated widget

                    dest.setX(relpos.x()+(w->width()/2));
                    dest.setY(relpos.y());

                    orig.setX(dpos.x()+(decorated_->width()/2));
                    orig.setY(dpos.y()+decorated_->height());
                }else if (relpos.x()> (dpos.x()+decorated_->width())){
                    //These two cases ocurr when the related widget and the decorated widget
                    //match in space along the Y axis

                    //Related widget is at right side of the decorated widge

                    dest.setX(relpos.x());
                    dest.setY(relpos.y()+(w->height()/2));

                    orig.setX(dpos.x()+decorated_->width());
                    orig.setY(dpos.y()+(decorated_->height()/2));
                }else if (relpos.x()+w->width()< dpos.x()){
                    //Related widget is at left side of the decorated widge
                    dest.setX(relpos.x()+w->width());
                    dest.setY(relpos.y()+(w->height()/2));

                    orig.setX(dpos.x());
                    orig.setY(dpos.y()+(decorated_->height()/2));

                }


                FigurePainter::PaintingContext lineContext;

                //Changing context to draw the line
                lineContext.lineColor = Qt::blue;
                lineContext.penStyle = Qt::SolidLine;

                lineContext.lineWidth=1;

                FigurePainter::drawLine(orig.x(),orig.y(),dest.x(),dest.y(),this,lineContext);

            }

        }
    }

}

void Relation::showEvent(QShowEvent * event){    
    ShadowList::iterator it=externRelated_.begin();
    for (;it!=externRelated_.end();it++)
    {
        (*it)->setVisible(true);
    }
}

void Relation::hideEvent ( QHideEvent * event )
{    
    ShadowList::iterator it=externRelated_.begin();
    for (;it!=externRelated_.end();it++)
    {
        (*it)->setVisible(false);
    }    
}

} //shadow_frame
} //widgets
} //qt
} //csu
