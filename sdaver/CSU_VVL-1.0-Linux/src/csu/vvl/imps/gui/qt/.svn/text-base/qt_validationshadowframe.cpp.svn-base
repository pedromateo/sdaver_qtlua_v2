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
*   This file is part of the Aspect-Oriented GUI Verification Library,
*   http://sourceforge.net/projects/guiverification/
*
*/

#include "qt_validationshadowframe.h"

#include <QWidgetList>

#include <iostream>
#include <csu/qt/widgets/shadow_widget/sw_momessage.h>

namespace csu {
namespace vvl {
namespace gui {
namespace qt {

using namespace csu::vvl::framework;
using namespace csu::qt::painters;
using namespace csu::qt::widgets::shadow_frame;

Qt_ValidationShadowFrame::Qt_ValidationShadowFrame(QWidget *parent, Qt::WindowFlags  flags,QColor * color,bool startPainting)
:ShadowFrame(parent,flags,color,startPainting)
{}

void Qt_ValidationShadowFrame::paintShadowWidget(ShadowWidget * swidget,const QWidgetList *wlist)
{
    ShadowWidgetPtr index=ShadowWidgetPtr(swidget);

    //Insert an associate all related widget with the decorator widget itself
    foreach (QWidget *w,*wlist)
    {
         decorationMap_[index].insert(w);
    }
}

void Qt_ValidationShadowFrame::removeShadowWidget(const QWidget * widget)
{
    DecorationMap::iterator it=decorationMap_.begin();

    //Remove all decorators where the widget is present
    for (;it!=decorationMap_.end();it++)
    {
        foreach(QWidget * w,it->second)
        {
            if (w==widget)
            {
                decorationMap_.erase(it);
                break;
            }
        }
    }


}

void Qt_ValidationShadowFrame::addRelated(const ShadowWidget * sw,const QWidgetList * related)
{
    DecorationMap::iterator it=decorationMap_.begin();
    for (;it!=decorationMap_.end();it++)
    {
        if (it->first.get()==sw){
            foreach(QWidget * w,*related)
            {
                it->second.insert(w);
            }
        }
    }
}

void Qt_ValidationShadowFrame::addMessage(const QWidget * interacted,const Rule * failedRule,const QWidgetList * related)
{
    //If interacted widget has a Message, then the rule code is added to the existing content
    //else a new message widget is created
     if (messageMap_[const_cast<QWidget *>(interacted)]==NULL){
         //Creating the message widget
         MOMessage * mom=new MOMessage(const_cast<Rule *>(failedRule)->rawRule(),this,const_cast<QWidget *>(interacted));
         //Addding to the shadow layer
         this->paintShadowWidget(mom,related);
         //adding to the search structure
         messageMap_[const_cast<QWidget *>(interacted)]=mom;

     }else{

         MOMessage * mom=dynamic_cast<MOMessage *>(messageMap_[const_cast<QWidget *>(interacted)]);
         //adding the code to the existing content         
         mom->addMessage(const_cast<Rule *>(failedRule)->rawRule());
         //adding new related widgets
         this->addRelated(mom,related);
     }
}


void Qt_ValidationShadowFrame::removeMessages()
{
    //Cleaning the search structure
    messageMap_.clear();

    //Deleting all Message widgets from the shadow layer
    DecorationMap::iterator it=decorationMap_.begin();
    for (;it!=decorationMap_.end();it++)
    {
         MOMessage * mom=dynamic_cast<MOMessage *>(it->first.get());
         if (mom)
             decorationMap_.erase(it);
    }
}

//FIXME Auxiliar Function (Remove when not needed)
void Qt_ValidationShadowFrame::printDecorationMap()
{
    DecorationMap::iterator it=decorationMap_.begin();
    for (;it!=decorationMap_.end();it++)
    {
        std::cout<<" _______________________________________________ "<<std::endl;
        std::cout<<" | \t"<<it->first->objectName().toStdString()<<" \t|"<<std::endl;
        std::cout<<" _______________________________________________ "<<std::endl;
        foreach(QWidget *w,it->second){
            std::cout<<"  -- "<<w->objectName().toStdString()<<std::endl;
        }
        std::cout<<"--------------------------------------------------------------------"<<std::endl;
    }
}

} //qt
} //gui
} //vvl
} //csu
