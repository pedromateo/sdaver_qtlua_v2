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

#ifndef GTSM_H
#define GTSM_H

///
/// a GUI thread safe method is called using a qt signal,
/// so it is thread safe within the thread of the GUI
///

#define QT_GUI_METHOD_HEADER(name, parameters)  \
public:                                         \
void name(parameters);                          \
private slots:                                  \
void g_name(parameters);                        \
signals:                                        \
void s_name(parameters);


#define QT_GUI_METHOD_IMPLEMENTATION(className, methodName, parametersType, namedParameters, parametersName)    \
void className::methodName(namedParameters)             \
{                                                       \
connect(this, SIGNAL(s_methodName(parametersType)), \
this, SLOT(g_methodName(parametersType)));          \
emit s_methodName(parametersName);                      \
}                                                       \
void className::g_methodName(namedParameters)



#endif //








