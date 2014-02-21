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

#ifndef SW_MESSAGE_H
#define SW_MESSAGE_H

#include "shadowwidget.h"
#include <QTextEdit>
#include <boost/shared_ptr.hpp>

namespace csu {
namespace qt {
namespace widgets {
namespace shadow_frame {

    ///
    /// Message ShadowWidget class
    ///
    /// This class creates a message box and locates
    /// it at an appropriate place relative to the
    /// the decorated widget.
    ///
    class Message : public ShadowWidget
    {
        Q_OBJECT
    public:
        ///
        /// constructor
        ///
        explicit Message(const std::string& message,
                         ShadowFrame* parent,
                         QWidget *decorated = 0);

        void clearMessage();
        void addMessage(const std::string &);
        void removeMessage(const std::string & message);

        std::string toStdString();

    protected:
        ///
        /// painting method
        ///
        virtual void paintEvent( QPaintEvent * event );

        ///
        /// locating method
        ///
        virtual void locate(void);

        ///
        /// method for adjusting the size of the
        /// text box to the size of the text
        ///
        //void adjustTextEdit(QTextEdit*);

    protected:
        typedef std::list<std::string> StringList;
        /// contained message
        StringList message_;
        /// text box shared pointer
        boost::shared_ptr<QTextEdit> textBox_;
        /// create the text box only the first time
        bool textboxInited_;

    };

} //shadow_frame
} //widgets
} //qt
} //csu
#endif // SW_MESSAGE_H
