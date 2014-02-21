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
 *   http://sourceforge.net/projects/ohtplus/
 *
 */

#include "abs_ui_datamodel.h"
#include <boost/lexical_cast.hpp>

namespace csu{
namespace base{
namespace ui{
namespace abstract_ui_datamodel{
namespace AUI{

/// /////////////////////////////////////////
/// abstract UI
/// /////////////////////////////////////////

AbstractUI::AbstractUI(const std::string& uiname)
{
    //TODO
}

AbstractUI::AbstractUI(AbstractUI* aui)
{
    uiName_ = aui->name();
    widgets_ = aui->widgetList();
}

AbstractUI::~AbstractUI()
{
    //TODO
}


/// abstract ui properties
const std::string& AbstractUI::name()
{
    return uiName_;
}

void AbstractUI::name(const std::string& v)
{
    uiName_ = v;
}


/// widget list methods
void AbstractUI::addWidget(AbstractWidget* aw)
{
    widgets_.push_back(aw);
    // FIXME: what about duplicated entries?
    widgetkeys_[aw->name()] = aw;
}

AbstractWidgetList::const_iterator AbstractUI::widgets() const
{
    return widgets_.begin();
}

AbstractWidgetList& AbstractUI::widgetList()
{
    return widgets_;
}


AbstractWidgetMap& AbstractUI::widgetMap()
{
    return widgetkeys_;
}

/// /////////////////////////////////////////
/// abstract widget
/// /////////////////////////////////////////
AbstractWidget::AbstractWidget()
    : uuid_ (U.uuid_new()), name_("emptyname"),
      x_(0), y_(0), height_(0), width_(0),
      enabled_(false), visible_(false), hidden_(false), tooltip_(""), concreteType_(AbstractWidget::ABSTRACTWIDGET)
{
}

AbstractWidget::AbstractWidget(AbstractWidget* aw)
{
    /// Deep copy constructor

    // values
    name(aw->name_);
    x(aw->x_);
    y(aw->y_);
    height(aw->height_);
    width(aw->width_);
    enabled(aw->enabled_);
    visible(aw->visible_);
    hidden(aw->hidden_);
    tooltip(aw->tooltip_);
    concreteType(aw->concreteType_);
    ///
    ///data and metadata maps

    TB_DataModel::KeyValueMap::const_iterator it;
    const TB_DataModel::KeyValueMap& kv1 = aw->dataMap();
    //data map
    for(it= kv1.begin(); it != kv1.end(); ++it)
    {
        addData(it->first, it->second);
    }

    const TB_DataModel::KeyValueMap& kv2 = aw->metadataMap();
    //metadata map
    for(it= kv2.begin(); it != kv2.end(); ++it)
    {
        addMetadata(it->first, it->second);
    }
}

AbstractWidget::~AbstractWidget()
{
}


uuid_t AbstractWidget::uuid() const
{
    return uuid_;
}

const std::string& AbstractWidget::name() const
{
    return name_;
}

void AbstractWidget::name(const std::string& v)
{
    name_ = v;
}


int AbstractWidget::x() const
{
    return x_;
}

void AbstractWidget::x(int v)
{
    x_ = v;
}

int AbstractWidget::y() const
{
    return y_;
}

void AbstractWidget::y(int v)
{
    y_ = v;
}

int AbstractWidget::height() const
{
    return height_;
}

void AbstractWidget::height(int v)
{
    height_ = v;
}

int AbstractWidget::width() const
{
    return width_;
}

void AbstractWidget::width(int v)
{
    width_ = v;
}

bool AbstractWidget::enabled() const
{
    return enabled_;
}

void AbstractWidget::enabled(bool v)
{
    enabled_ = v;
}

bool AbstractWidget::visible() const
{
    return visible_;
}

void AbstractWidget::visible(bool v)
{
    visible_ = v;
}

bool AbstractWidget::hidden() const
{
    return hidden_;
}

void AbstractWidget::hidden(bool v)
{
    hidden_ = v;
}

const std::string& AbstractWidget::tooltip() const
{
    return tooltip_;
}

void AbstractWidget::tooltip(const std::string& v)
{
    tooltip_ = v;
}

void AbstractWidget::concreteType(int v){
    concreteType_=v;
}

int AbstractWidget::concreteType(void)
{
    return concreteType_;
}

} //
} //
} //
} //
} //csu

