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

#include "sw_mouseovershadowvanish.h"

//FIXME UNDER DEVELOPMENT
namespace csu {
namespace qt {
namespace widgets {
namespace shadow_frame {

MouseOverShadowVanish::VanishThread::VanishThread(const MouseOverShadowVanish * mov)
:mov_(mov)
{
    transparency_=100;
    stop_=true;

}

void MouseOverShadowVanish::VanishThread::startVanish()
{
    transparency_=100;
    stop_=false;
    while ((transparency_!=0) && (stop_==false)){
        transparency_-=20;
        //((MouseOverShadowVanish *)mov_)->updateTransparency();
        ((ShadowWidget *)mov_)->repaint();        
        sleep(1);
    }

}


int MouseOverShadowVanish::VanishThread::transparency()
{
    return transparency_;
}

void MouseOverShadowVanish::VanishThread::stopVanish()
{
    stop_=true;
}
bool MouseOverShadowVanish::VanishThread::vanishing()
{
    return !stop_;
}
void MouseOverShadowVanish::VanishThread::updateTrans()
{

}

MouseOverShadowVanish::MouseOverShadowVanish(ShadowFrame* parent, QWidget *decorated)
:MouseOverShadow(parent,decorated)
{
    vanishThread_=new MouseOverShadowVanish::VanishThread(this);    
//    connect(this,SIGNAL(udpateTransparency()),this,SLOT(repaint()));
}

MouseOverShadowVanish::~MouseOverShadowVanish()
{
    mouseOverList_->clear();
    mouseOutList_->clear();
}

//void MouseOverShadowVanish::updateTransparency(){
//    repaint();
//}

bool MouseOverShadowVanish::eventFilter(QObject *obj, QEvent *e)
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
        vanishThread_->stopVanish();
    }
    else if (e->type() == QEvent::Leave)
    {
        vanishThread_->startVanish();
        //turn visible the out widgets
        onMouseOver_ = false;
//        if (vanishThread_->transparency()==0){
//            this->visibleShadowList_=mouseOutList_;
//            this->invisibleShadowList_=mouseOverList_;
//        }else{
//
//        }
    }

    //return false for not to handle the message
    return false;
}

void MouseOverShadowVanish::paintEvent( QPaintEvent * event )
{
    MouseOverShadow::paintEvent(event);    

    if (vanishThread_->vanishing())
    {
        if (vanishThread_->transparency()==0){
            this->visibleShadowList_=mouseOutList_;
            this->invisibleShadowList_=mouseOverList_;
        }else{
            ShadowWidget * sw=mouseOverList_->front().get();            

            //Setting Color and stylesheet
            QPalette orig=sw->palette();
            QPalette mod;

            QColor backColor=orig.base().color();
            backColor.setAlpha(vanishThread_->transparency());
            orig.setColor(QPalette::Base,backColor);
            sw->setPalette(orig);
//            backColor=pcontext_.backColor;
//            backColor.setAlpha(pcontext_.transparency);

        }
    }

}

} //shadow_frame
} //widgets
} //qt
} //csu
