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

#ifndef SHADOWWIDGET_H
#define SHADOWWIDGET_H

#include <QWidget>
#include "shadowframe.h"
#include <csu/qt/painters/figurepainter.h>
#include <boost/shared_ptr.hpp>

namespace csu {
namespace qt {
namespace widgets {
namespace shadow_frame {

class ShadowWidget;

typedef boost::shared_ptr<ShadowWidget> ShadowWidgetPtr;
typedef std::list<ShadowWidgetPtr> ShadowList;

class ShadowWidget : public QWidget
{
Q_OBJECT
public:
    ShadowWidget(ShadowFrame* parent, QWidget *decorated,bool visible=true);
    virtual ~ShadowWidget();

    void setPaintingContext(const csu::qt::painters::FigurePainter::PaintingContext & pcontext);
    const std::string & decoratedName();    
    virtual void setBackgroundColor(QColor color);

protected:
    QWidget* decorated_;
    bool eventFilter(QObject *obj, QEvent *e);
    //Not all widget locate at the same place, redefine this function in order
    //to place the shadow widget wherever you want from the decorated widget area
    //Also you have to remember to adjust the canvas region inside the widget painting context
    virtual void locate();

protected:
    csu::qt::painters::FigurePainter::PaintingContext pcontext_;

private:
    std::string decoratedName_;

};

} //shadow_frame
} //widgets
} //qt
} //csu

#endif // SHADOWWIDGET_H
