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

#ifndef QT_VALIDATIONSHADOWFRAME_H
#define QT_VALIDATIONSHADOWFRAME_H

#include <csu/qt/widgets/shadow_widget/shadowframe.h>
#include <csu/vvl/framework/vvl_rule.h>
#include <csu/vvl/framework/vvl_forward.h>
#include <csu/qt/painters/figure.h>
#include <csu/qt/painters/rectangle.h>
#include <csu/qt/widgets/shadow_widget/shadowwidget.h>


#include <QWidget>
#include <QFrame>

#include <boost/shared_ptr.hpp>

namespace csu {
namespace vvl {
namespace gui {
namespace qt {

using namespace csu::qt::widgets::shadow_frame;
using namespace csu::vvl::framework;

class Qt_ValidationShadowFrame : public csu::qt::widgets::shadow_frame::ShadowFrame
{
public:
    Qt_ValidationShadowFrame(QWidget *parent, Qt::WindowFlags  flags,QColor * color,bool startPainting);


    void paintShadowWidget(ShadowWidget * widget,const QWidgetList *wlist);
    void removeShadowWidget(const QWidget * widget);    
    void addRelated(const ShadowWidget * sw,const QWidgetList * related);

    //Functions to work with messages
    void addMessage(const QWidget * interacted,const Rule * failedRule,const QWidgetList * related);
    void removeMessages();

    //FIXME Internal Function (Remove when not needed)
    void printDecorationMap();    

private:
    typedef boost::shared_ptr<ShadowWidget> ShadowWidgetPtr;
    typedef std::list<ShadowWidgetPtr> ShadowList;        
    typedef std::set<QWidget * > WidgetSet;
    typedef std::map<ShadowWidgetPtr,WidgetSet> DecorationMap;

    //This structure is used only for a better performance with some operations
    typedef std::map<QWidget *,ShadowWidget *> MessageMap;



private:
    DecorationMap decorationMap_;    
    MessageMap messageMap_;    

};

} //qt
} //gui
} //vvl
} //csu
#endif // QT_VALIDATIONSHADOWFRAME_H
