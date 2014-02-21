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

#ifndef QT_ELEMENTABSTRACTOR_H
#define QT_ELEMENTABSTRACTOR_H

#include <csu/vvl/framework/vvl_genericelementabstractor.h>

#include <QWidget>

namespace csu {
namespace vvl {
namespace gui {
namespace qt {

using namespace csu::vvl::framework;


class QtElementAbstractor : public GenericElementAbstractor
{
public:

    ///
    /// Constructor
    /// @param context is the verification context
    ///

   QtElementAbstractor(VerificationContextPtr context);

   void updateElements(void);
   const GenericAbstractionResult * getElementAbstraction(const boost::any &);


public:
   bool filterWidget(QWidget *w);
   static QString getNameSpaceName(QWidget * w);
   static void listElementsName();


};

} //qt
} //gui
} //vvl
} //csu

#endif // QT_ELEMENTABSTRACTOR_H
