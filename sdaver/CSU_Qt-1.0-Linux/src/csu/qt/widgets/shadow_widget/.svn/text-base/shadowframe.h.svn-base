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
#ifndef SHADOWFRAME_H
#define SHADOWFRAME_H

#include <QFrame>
#include <QPainter>
#include <QPaintEvent>

#include <map>
#include <csu/qt/painters/figure.h>


namespace csu {
namespace qt {
namespace widgets {
namespace shadow_frame {

    using namespace csu::qt::painters;

class ShadowFrame : public QFrame
{
    Q_OBJECT
public:
    ShadowFrame();

    /// Object Constructor with the following parameters:
    /// -- parent: widget that will be this objects'parent
    /// -- flags: like any other widget it can be created using Qt flags, according to requirements.
    ///    If this frame has to cover the main application window, this parameter must be 0.
    /// -- color: this parameter is used as the main color of the frame. Alpha channel is allowed, so you can
    /// have a semi-transparent frame. If this parameter is left blank, this object will be fully transparent
    /// -- startPainting: this parameter is used to enable painting inside this widget
    ShadowFrame(QWidget *parent=0, Qt::WindowFlags  flags=0,QColor * color=0,bool startPainting=false);
    virtual ~ShadowFrame();

    /// This method paint an object Figure into this frame. The figure must have a name in order to access it later.
    /// Usually the name used will be the one from the uppermost widget directly under the Figure in the application's widget hierarchy
    /// For example, if you want to surround a QLineEdit with a Rectangle Figure, the name used to access the figure will
    /// be the QLineEdit's name
    void paintFigure(const std::string & name,Figure *);
    void removeFigure(const std::string & name);

    void enablePainting(bool);
    bool enablePainting(void);

    /// Remove the figure list
    void clear(void);

protected:
    virtual void paintEvent(QPaintEvent *event);


private:
    QPainter* painter_;
    QWidget * parent_;

    /// This data structure contains the figures to be painted
    typedef std::map<std::string,Figure*> FigureMap;    
    FigureMap figureMap_;

    bool enablePainting_;
};

}
}
}
}

#endif // SHADOWFRAME_H
