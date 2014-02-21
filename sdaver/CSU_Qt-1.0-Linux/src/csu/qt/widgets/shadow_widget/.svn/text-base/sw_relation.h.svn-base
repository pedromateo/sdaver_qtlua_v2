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

#ifndef SW_RELATION_H
#define SW_RELATION_H

#include "shadowwidget.h"
#include <QWidgetList>
#include <boost/shared_ptr.hpp>

namespace csu {
namespace qt {
namespace widgets {
namespace shadow_frame {

typedef std::map<QWidget *,ShadowFrame *> ShadowMapRelated;

class Relation : public virtual ShadowWidget
{
public:
//    struct ShadowFrameRecord{
//        ShadowFrame * parent;
//        QWidget * widget;
//
//        ShadowFrameRecord(ShadowFrame * p,QWidget * w):parent(p),widget(w){}
//    };
//
//    typedef boost::shared_ptr<ShadowFrameRecord> ShadowFrameRecordPtr;

    //typedef std::map<ShadowFrameRecordPtr> ShadowFrameMapRelated;
    //
    //typedef std::map<std::string,std::string> ShadowMapRelated;

public:
    Relation(ShadowFrame *, QWidget *decorated,const ShadowMapRelated * related=0,bool visible=true);
    virtual ~Relation();

protected:
    void hideEvent ( QHideEvent * event );
    void showEvent(QShowEvent * event);    

protected:
    virtual void paintEvent( QPaintEvent * event );
    virtual void locate(void);



private:
    QWidgetList relatedWidget_;
    ShadowMapRelated relatedShadowFrames_;
    ShadowList externRelated_;
    csu::qt::painters::FigurePainter::PaintingContext relatedcontext_;
};

} //shadow_frame
} //widgets
} //qt
} //csu
#endif // SW_RELATION_H
