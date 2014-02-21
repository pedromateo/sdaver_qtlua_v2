// -*- mode: c++; c-basic-offset: 4; c-file-style: bsd; -*-
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
 *
 */

#include "dynamicmenu.h"

#include <iostream>

namespace csu{
    namespace qt{
        namespace dynamic_menu{

            /// handler_t
            callback_t::callback_t()
            {
            }

            callback_t::callback_t(boost::function<void()> f_handler)
            {
                handler_ = f_handler;
            }

            void callback_t::operator()()
            {
                if (handler_ != 0) handler_();
            }

            ///
            /// MenuItem
            ///

            MenuItem::MenuItem(int _id, std::string _name, handler_t _f)
            {
                id = _id;
                name = _name;
                handler = callback_t(_f);
                subitems.clear();
            }



            ///
            /// Handled_QMenu
            /// Special version of QMenu with a handler method
            ///

            Handled_QMenu::Handled_QMenu(const QString & title, QWidget * parent)
                    : QMenu(title,parent)
            {
                connect(this, SIGNAL(triggered(QAction*)),
                        this, SLOT(handleMenu()));
            }

            void Handled_QMenu::handler(handler_t h)
            {
                handler_ = callback_t(h);
            }


            void Handled_QMenu::handleMenu()
            {
                handler_();
            }

            ///
            /// Handled_QAction
            /// Special version of QAction with a handler method
            ///

            Handled_QAction::Handled_QAction(const QString & title, QWidget * parent)
                    : QAction(title,parent)
            {
                connect(this, SIGNAL(triggered(bool)),
                        this, SLOT(handleMenu()));
            }

            void Handled_QAction::handler(handler_t h)
            {
                handler_ = callback_t(h);
            }

            void Handled_QAction::handleMenu()
            {
                handler_();
            }

        } // dynamic_menu
    } // qt
} // csu

