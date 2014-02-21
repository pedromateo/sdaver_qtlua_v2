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

#include "shadowwidget.h"

namespace csu {
namespace qt {
namespace widgets {
namespace shadow_frame {


using namespace csu::qt::painters;

ShadowWidget::ShadowWidget(ShadowFrame* parent, QWidget *decorated,bool visible) :
    QWidget(parent), decorated_(decorated)
{

   locate();

   this->resize(decorated_->width(),decorated_->height());

   this->setVisible(visible);

   decorated_->installEventFilter(this);

   decoratedName_=decorated_->objectName().toStdString();
}

ShadowWidget::~ShadowWidget(){    
    this->setVisible(false);
}

void ShadowWidget::locate()
{
    this->move(decorated_->mapTo(this->parentWidget()->parentWidget(),QPoint(0,0)));
}

bool ShadowWidget::eventFilter(QObject *obj, QEvent *e)
{

    if (e->type()==QEvent::Move)
        locate();

    return false;
}

void ShadowWidget::setBackgroundColor(QColor color){
    int transparency=color.alpha();
    pcontext_.backColor=color;
    pcontext_.lineColor=color;
    if (transparency!=255)
        pcontext_.transparency=transparency;

}

void ShadowWidget::setPaintingContext(const FigurePainter::PaintingContext & pcontext)
{
    pcontext_.backColor = pcontext.backColor;
    pcontext_.lineColor = pcontext.lineColor;
    pcontext_.transparency = pcontext.transparency;
    pcontext_.penStyle = pcontext.penStyle;
    pcontext_.capStyle = pcontext.capStyle;
}

const std::string & ShadowWidget::decoratedName()
{    
    return decoratedName_;
}

} //shadow_frame
} //widgets
} //qt
} //csu
