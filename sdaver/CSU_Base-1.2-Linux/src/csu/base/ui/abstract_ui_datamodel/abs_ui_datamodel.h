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
#ifndef AU_DATAMODEL_H
#define AU_DATAMODEL_H

#include <csu/base/datamodel/testbase/tb_datamodel.h>

#include <csu/base/uuid/uuid.h>
#include <map>
#include <boost/ptr_container/ptr_list.hpp>
#include <string>
#include <exception>

#define WANT_SERIALIZE

#ifdef WANT_SERIALIZE
#include <boost/serialization/utility.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/map.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <sstream>
#endif



namespace csu {
namespace base {
namespace ui {
namespace abstract_ui_datamodel {
namespace AUI {

using namespace csu::base::datamodel::testbase;
using namespace csu::base::uuid;

class AbstractUI;
class AbstractWidget;

///
/// typedefs
typedef std::list<std::string> StringList;
typedef std::list<AbstractWidget*> AbstractWidgetList;
typedef std::map<std::string,AbstractWidget*> AbstractWidgetMap;

/// /////////////////////////////////////////
/// abstract UI
/// /////////////////////////////////////////
class AbstractUI
{
public:
    AbstractUI(const std::string& uiname);
    AbstractUI(AbstractUI*);
    virtual ~AbstractUI();

    /// abstract ui properties
    const std::string& name();
    void name(const std::string&);

    /// widget list methods
    void addWidget(AbstractWidget*);
    AbstractWidgetList::const_iterator widgets() const;
    AbstractWidgetList& widgetList();
    AbstractWidgetMap& widgetMap();

private:
    AbstractWidgetList widgets_;
    AbstractWidgetMap widgetkeys_;

    //properties
    std::string uiName_;
};

/// /////////////////////////////////////////
/// abstract widget FIXME está más abajo
/// /////////////////////////////////////////
class AbstractWidget :
        public TB_DataModel::TestBase
{
public:
    // ID of this testitem
    uuid_t uuid_;
    enum concreteType
    {   ABSTRACTWIDGET = 0,                
        BUTTON,
        COMBOBOX,
        SLIDER,
        TEXTEDIT,
        SPINBOX,
        TEXT,
        CHECKBOX,
        RADIOBUTTON,
        CONTAINERBOX,
        FRAME,
        PANEL,
        TABPANEL,
        BAR,
        MENU,
        WINDOW,
        DIALOG
    };

public:
    AbstractWidget();
    AbstractWidget(AbstractWidget*);
    virtual ~AbstractWidget();

    /// roles
    template<class Role>
    void addRole()
    {
        Role::setRole(this);
    }

    /// properties
    uuid_t uuid() const;

    std::string const& name() const;
    void name(const std::string&);
    int x() const;
    void x(int);
    int y() const;
    void y(int);
    int height() const;
    void height(int);
    int width() const;
    void width(int);
    bool enabled() const;
    void enabled(bool);
    bool visible() const;
    void visible(bool);
    bool hidden() const;
    void hidden(bool);
    std::string const& tooltip() const;
    void tooltip(const std::string&);
    int concreteType(void);
    void concreteType(int);

#ifdef WANT_SERIALIZE
    //serialization
    friend class boost::serialization::access;
    template<class Archive>
            void serialize(Archive & ar, const unsigned int)
    {
        ar & dataMap_;
        ar & metadataMap_;

        ar & name_;
        ar & x_;
        ar & y_;
        ar & height_;
        ar & width_;
        ar & enabled_;
        ar & visible_;
        ar & hidden_;
        ar & tooltip_;
        ar & concreteType_;
    }

    /// ////////////////////////////
    /// serialization supporting methods
    /// ////////////////////////////

    std::string serialize()
    {
        std::ostringstream oss;
        boost::archive::text_oarchive oa(oss);
        oa << *this;
        return oss.str();
    }

    static void DeserializeItem(const std::string& s, AbstractWidget* aw)
    {
        std::istringstream iss (s);
        boost::archive::text_iarchive ia(iss);
        ia >> (*aw);
    }
#endif

protected:
    std::string name_;
    int x_;
    int y_;
    int height_;
    int width_;
    bool enabled_;
    bool visible_;
    bool hidden_;
    std::string tooltip_;
    int concreteType_;
};

} //
} //
} //
} //
} //csu


#endif // AU_DATAMODEL_H
