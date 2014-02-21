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

#ifndef SW_MOUSEOVERSHADOWVANISH_H
#define SW_MOUSEOVERSHADOWVANISH_H

#include "sw_mouseovershadow.h"
#include <QThread>



//FIXME UNDER DEVELOPMENT

namespace csu {
namespace qt {
namespace widgets {
namespace shadow_frame {


class MouseOverShadowVanish : public MouseOverShadow
{
private:
    class VanishThread : public QThread
     {      
     public:        
        VanishThread(const MouseOverShadowVanish * shadowWidget);
        void stopVanish();
        void startVanish();
        bool vanishing();
        int transparency();
        void updateTrans();

     private:
        int transparency_;
        bool stop_;
        const MouseOverShadowVanish * mov_;     
//     signals:
//        void updateTrans();
     };

public:
    MouseOverShadowVanish(ShadowFrame* parent, QWidget *decorated);
    ~MouseOverShadowVanish();

protected:
    bool eventFilter(QObject *obj, QEvent *e);
    virtual void paintEvent( QPaintEvent * event );

private:
        ShadowList * mouseTransitionList_;
        VanishThread * vanishThread_;

};

} //shadow_frame
} //widgets
} //qt
} //csu

#endif // SW_MOUSEOVERSHADOWVANISH_H
