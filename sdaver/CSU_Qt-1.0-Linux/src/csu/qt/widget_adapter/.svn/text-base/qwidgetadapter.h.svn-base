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
 *
 */

#ifndef QWIDGETADAPTER_H
#define QWIDGETADAPTER_H


#include <csu/base/ui/abstract_ui_datamodel/abs_ui_datamodel.h>

#include <QWidget>
#include <boost/ptr_container/ptr_map.hpp>


namespace csu {
namespace qt {
namespace widget_adapter {
namespace QWA
{

///
/// Adapter manager
///
class QWidgetAdapterManager
{
    typedef void (*apply_f)(QWidget*, const std::string&);
    typedef std::string (*get_f)(QWidget*);
    typedef csu::base::ui::abstract_ui_datamodel::AUI::AbstractWidget* (*abstract_rep_f)(QWidget*);

    struct funcs
    {
        apply_f af;
        get_f gf;
        abstract_rep_f arf;
    };
    static bool inited;

    static void init();

public:
    typedef std::map<std::string, funcs> AdapterSet;

    //add adapter
    static void register_class (const std::string&,
                                apply_f,
                                get_f,
                                abstract_rep_f);

    //check if sensitive and returns an
    //adapter if true (null if not)
    static bool isAdaptable(QWidget*);

    // Implementation for the default value
    static std::string sensitiveValue(QWidget* w);

    // Application of the sensible value (default)
    static void applySensitiveValue(QWidget* w, const std::string& s);

    // Default implementation
    static csu::base::ui::abstract_ui_datamodel::AUI::AbstractWidget*
    abstractRepresentation(QWidget* w);

    ///
    /// supporting methods
public:
    static void FillWidgetBasicValues(
        csu::base::ui::abstract_ui_datamodel::AUI::AbstractWidget*,
        QWidget*);

private:
    static AdapterSet adapters;
};


} // QWA

} // widget_adapter
} // qt
} // csu

#endif // QWIDGETADAPTER_H
