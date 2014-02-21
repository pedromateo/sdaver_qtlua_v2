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

#ifndef CHSBIND_QTADAPTERS_H
#define CHSBIND_QTADAPTERS_H


#include <iostream>

// Widgets to adapt
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QTimeEdit>
#include <QDateEdit>
#include <QDateTimeEdit>
#include <QComboBox>
#include <QFontComboBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QDial>
#include <QSlider>
#include <QScrollBar>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>
#include <QGroupBox>

#include <chaiscript/chaiscript.hpp>

/// //////////////////////////////////
/// Qt value adapters
/// //////////////////////////////////

class QtChai_Adapters
{
public:
    ///
    /// supporting methods
    ///
    /// it is necessary to adapt return types not supported
    /// by Luabind
    ///

     // QTimeEdit
    static int QTimeEdit_hour(const QTimeEdit * qte);
    static int QTimeEdit_minute(const QTimeEdit * qte);
    static int QTimeEdit_second(const QTimeEdit * qte);

    // QDateEdit
    static int QDateEdit_day(const QDateEdit * qde);
    static int QDateEdit_month(const QDateEdit * qde);
    static int QDateEdit_year(const QDateEdit * qde);

    // QDateTimeEdit
    static int QDateTimeEdit_hour(const QDateTimeEdit * qdte);
    static int QDateTimeEdit_minute(const QDateTimeEdit * qdte);
    static int QDateTimeEdit_second(const QDateTimeEdit * qdte);
    static int QDateTimeEdit_day(const QDateTimeEdit * qdte);
    static int QDateTimeEdit_month(const QDateTimeEdit * qdte);
    static int QDateTimeEdit_year(const QDateTimeEdit * qdte);

    // QComboBox
    static std::string QComboBox_currentText(const QComboBox * qcb);

    // QFontComboBox
    static std::string QFontComboBox_currentText(const QFontComboBox * qfcb);

    // QLineEdit
    static std::string QLineEdit_text(const QLineEdit * qle);
    static std::string QLineEdit_selectedText(const QLineEdit * qle);

    // QTextEdit
    static std::string QTextEdit_plainText(const QTextEdit * qte);

    // QPlainTextEdit
    static std::string QPlainTextEdit_plainText(const QPlainTextEdit * qpte);

    // QLabel
    static std::string QLabel_text(const QLabel * ql);

    // QPushButton
    static std::string QPushButton_text(const QPushButton * qpb);

    // QRadioButton
    static std::string QRadioButton_text(const QRadioButton * qrb);

    // QCheckBox
    static std::string QCheckBox_text(const QCheckBox * qcb);

    // QGroupBox
    static std::string QGroupBox_title(const QGroupBox * qgb);

    static void LoadAdapters(chaiscript::ChaiScript * chai);

};

#endif // CHSBIND_QTADAPTERS_H
