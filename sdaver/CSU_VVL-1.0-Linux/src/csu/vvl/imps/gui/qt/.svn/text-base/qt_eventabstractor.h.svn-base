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

#ifndef QT_EVENTABSTRACTOR_H
#define QT_EVENTABSTRACTOR_H

#include <csu/vvl/framework/vvl_genericeventabstractor.h>

#include <QWidget>
#include <QEvent>
#include <map>

namespace csu {
namespace vvl {
namespace gui {
namespace qt {

    using namespace csu::vvl::framework;

    class Qt_EventAbstractor : public QObject,public GenericEventAbstractor
    {
    public:
        ///
        /// Constructor
        /// @param context is the verification context
        ///

        Qt_EventAbstractor(VerificationContextPtr context);
        virtual ~Qt_EventAbstractor();

        void mapEvents();
        virtual void install();
        virtual void uninstall();

    protected:
        bool eventFilter(QObject *obj, QEvent *event);
    private:
        //FIXME not sure to store this data structure here, it depends on which data
        //structure has events in different windows frameworks. If it is also an enum
        //this structures can be stored in the GenericEventAbstractor class
        typedef std::map<unsigned int,unsigned long> EventMap;
        EventMap eventMap_;
        bool winIdChange_;

    //FIXME DELETE
    private:
        typedef std::list<unsigned long int> TimeList;
        TimeList timeList_,timeListQt_;

    };

} //qt
} //gui
} //vvl
} //csu

#endif // QT_EVENTABSTRACTOR_H
