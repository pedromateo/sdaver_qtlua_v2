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
#ifndef DYNAMIC_MENU_H
#define DYNAMIC_MENU_H

#include <QMenu>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/ptr_container/ptr_list.hpp>

#include <iostream>

namespace csu{
namespace qt{
namespace dynamic_menu{

/// handler_t
//typedef void (*f_handler_t)();
typedef boost::function<void()> handler_t;

struct callback_t
{
public:
    callback_t();

    callback_t(boost::function<void()> f_handler);

    void operator()();

private:
    boost::function<void()> handler_;
};

///
/// MenuItem
///
struct MenuItem
{
    int id;
    std::string name;
    boost::ptr_list<MenuItem> subitems;
    callback_t handler;

    MenuItem(int _id, std::string _name, handler_t _f);
};

///
/// Handled_Item
///
#if 0
class Handled_Item : public QObject
{
    Q_OBJECT
    public:
    Handled_Item()
    {
    }

    void handler(handler_t h)
    {
        handler_ = h;
    }

public slots:
    void handleMenu()
    {
        if (handler_ != 0)
        {
            handler_();
        }
    }

private:
    handler_t handler_;
};
#endif

///
/// Handled_QMenu
/// Special version of QMenu with a handler method
///
class Handled_QMenu : public QMenu//, public Handled_Item
{
    Q_OBJECT

    public:
    Handled_QMenu(const QString & title, QWidget * parent = 0);

    void handler(handler_t h);

public slots:
    void handleMenu();

private:
    callback_t handler_;
};

///
/// Handled_QAction
/// Special version of QAction with a handler method
///
class Handled_QAction : public QAction//, public Handled_Item
{
    Q_OBJECT

    public:
    Handled_QAction(const QString & title, QWidget * parent = 0);

    void handler(handler_t h);

public slots:
    void handleMenu();

private:
    callback_t handler_;
};

} // dynamic_menu
} // qt
} // csu


#endif //DYNAMIC_MENU_HPP
