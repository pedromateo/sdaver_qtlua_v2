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

#include "qtchs_adapters.h"

// QTimeEdit
int QtChai_Adapters::QTimeEdit_hour(const QTimeEdit * qte){
return qte->time().hour();
}
int QtChai_Adapters::QTimeEdit_minute(const QTimeEdit * qte){
return qte->time().minute();
}
int QtChai_Adapters::QTimeEdit_second(const QTimeEdit * qte){
return qte->time().second();
}

// QDateEdit
int QtChai_Adapters::QDateEdit_day(const QDateEdit * qde){
return qde->date().day();
}
int QtChai_Adapters::QDateEdit_month(const QDateEdit * qde){
return qde->date().month();
}
int QtChai_Adapters::QDateEdit_year(const QDateEdit * qde){
return qde->date().year();
}

// QDateTimeEdit
int QtChai_Adapters::QDateTimeEdit_hour(const QDateTimeEdit * qdte){
return qdte->time().hour();
}
int QtChai_Adapters::QDateTimeEdit_minute(const QDateTimeEdit * qdte){
return qdte->time().minute();
}
int QtChai_Adapters::QDateTimeEdit_second(const QDateTimeEdit * qdte){
return qdte->time().second();
}
int QtChai_Adapters::QDateTimeEdit_day(const QDateTimeEdit * qdte){
return qdte->date().day();
}
int QtChai_Adapters::QDateTimeEdit_month(const QDateTimeEdit * qdte){
return qdte->date().month();
}
int QtChai_Adapters::QDateTimeEdit_year(const QDateTimeEdit * qdte){
return qdte->date().year();
}

// QComboBox
std::string QtChai_Adapters::QComboBox_currentText(const QComboBox * qcb){
return qcb->currentText().toStdString();
}

// QFontComboBox
std::string QtChai_Adapters::QFontComboBox_currentText(const QFontComboBox * qfcb){
return qfcb->currentText().toStdString();
}

// QLineEdit
std::string QtChai_Adapters::QLineEdit_text(const QLineEdit * qle)
{
return qle->text().toStdString();
}

std::string QtChai_Adapters::QLineEdit_selectedText(const QLineEdit * qle)
{
return qle->selectedText().toStdString();
}

// QTextEdit
std::string QtChai_Adapters::QTextEdit_plainText(const QTextEdit * qte)
{
return qte->toPlainText().toStdString();
}

// QPlainTextEdit
std::string QtChai_Adapters::QPlainTextEdit_plainText(const QPlainTextEdit * qpte)
{
return qpte->toPlainText().toStdString();
}

// QLabel
std::string QtChai_Adapters::QLabel_text(const QLabel * ql)
{
return ql->text().toStdString();
}

// QPushButton
std::string QtChai_Adapters::QPushButton_text(const QPushButton * qpb)
{
return qpb->text().toStdString();
}

// QRadioButton
std::string QtChai_Adapters::QRadioButton_text(const QRadioButton * qrb)
{
return qrb->text().toStdString();
}

// QCheckBox
std::string QtChai_Adapters::QCheckBox_text(const QCheckBox * qcb)
{
return qcb->text().toStdString();
}

// QGroupBox
std::string QtChai_Adapters::QGroupBox_title(const QGroupBox * qgb)
{
return qgb->title().toStdString();
}


///
/// adapters loading method
///
void QtChai_Adapters::LoadAdapters(chaiscript::ChaiScript * chai)
{


///
/// QSpinBox adapter
///
    chai->add(chaiscript::fun<int (QSpinBox *)>(&QSpinBox::maximum), "maximum");
    chai->add(chaiscript::fun<int (QSpinBox *)>(&QSpinBox::minimum), "minimum");
    chai->add(chaiscript::fun<int (QSpinBox *)>(&QSpinBox::value), "value");
    chai->add(chaiscript::fun<bool (QSpinBox *)>(&QSpinBox::isReadOnly), "isReadOnly");
    chai->add(chaiscript::fun<bool (QSpinBox *)>(&QSpinBox::isEnabled), "isEnabled");
    chai->add(chaiscript::fun<bool (QSpinBox *)>(&QSpinBox::isVisible), "isVisisble");


///
/// QDoubleSpinBox adapter
///

    chai->add(chaiscript::fun<int (QDoubleSpinBox *)>(&QDoubleSpinBox::maximum), "maximum");
    chai->add(chaiscript::fun<int (QDoubleSpinBox *)>(&QDoubleSpinBox::minimum), "minimum");
    chai->add(chaiscript::fun<int (QDoubleSpinBox *)>(&QDoubleSpinBox::value), "value");
    chai->add(chaiscript::fun<int (QDoubleSpinBox *)>(&QDoubleSpinBox::decimals), "decimals");
    chai->add(chaiscript::fun<bool (QDoubleSpinBox *)>(&QDoubleSpinBox::isReadOnly), "isReadOnly");
    chai->add(chaiscript::fun<bool (QDoubleSpinBox *)>(&QDoubleSpinBox::isEnabled), "isEnabled");
    chai->add(chaiscript::fun<bool (QDoubleSpinBox *)>(&QDoubleSpinBox::isVisible), "isVisisble");


///
/// QTimeEdit adapter
///

    chai->add(chaiscript::fun<int (const QTimeEdit *)>(&QtChai_Adapters::QTimeEdit_hour), "hour");
    chai->add(chaiscript::fun<int (const QTimeEdit *)>(&QtChai_Adapters::QTimeEdit_minute), "minute");
    chai->add(chaiscript::fun<int (const QTimeEdit *)>(&QtChai_Adapters::QTimeEdit_second), "second");
    chai->add(chaiscript::fun<bool (QTimeEdit *)>(&QTimeEdit::isReadOnly), "isReadOnly");
    chai->add(chaiscript::fun<bool (QTimeEdit *)>(&QTimeEdit::isEnabled), "isEnabled");
    chai->add(chaiscript::fun<bool (QTimeEdit *)>(&QTimeEdit::isVisible), "isVisisble");

///
/// QDateEdit adapter
///

    chai->add(chaiscript::fun<int (const QDateEdit *)>(&QtChai_Adapters::QDateEdit_day), "day");
    chai->add(chaiscript::fun<int (const QDateEdit *)>(&QtChai_Adapters::QDateEdit_month), "month");
    chai->add(chaiscript::fun<int (const QDateEdit *)>(&QtChai_Adapters::QDateEdit_year), "year");
    chai->add(chaiscript::fun<bool (QDateEdit *)>(&QDateEdit::isReadOnly), "isReadOnly");
    chai->add(chaiscript::fun<bool (QDateEdit *)>(&QDateEdit::isEnabled), "isEnabled");
    chai->add(chaiscript::fun<bool (QDateEdit *)>(&QDateEdit::isVisible), "isVisisble");

///
/// QDateTimeEdit adapter
///

    chai->add(chaiscript::fun<int (const QDateTimeEdit *)>(&QtChai_Adapters::QDateTimeEdit_hour), "hour");
    chai->add(chaiscript::fun<int (const QDateTimeEdit *)>(&QtChai_Adapters::QDateTimeEdit_minute), "minute");
    chai->add(chaiscript::fun<int (const QDateTimeEdit *)>(&QtChai_Adapters::QDateTimeEdit_second), "seond");
    chai->add(chaiscript::fun<int (const QDateTimeEdit *)>(&QtChai_Adapters::QDateTimeEdit_day), "day");
    chai->add(chaiscript::fun<int (const QDateTimeEdit *)>(&QtChai_Adapters::QDateTimeEdit_month), "month");
    chai->add(chaiscript::fun<int (const QDateTimeEdit *)>(&QtChai_Adapters::QDateTimeEdit_year), "year");
    chai->add(chaiscript::fun<bool (QDateTimeEdit *)>(&QDateTimeEdit::isReadOnly), "isReadOnly");
    chai->add(chaiscript::fun<bool (QDateTimeEdit *)>(&QDateTimeEdit::isEnabled), "isEnabled");
    chai->add(chaiscript::fun<bool (QDateTimeEdit *)>(&QDateTimeEdit::isVisible), "isVisisble");


/////
///// QComboBox adapter
/////

    chai->add(chaiscript::fun<int (QComboBox *)>(&QComboBox::count), "count");
    chai->add(chaiscript::fun<int (QComboBox *)>(&QComboBox::currentIndex), "currentIndex");
    chai->add(chaiscript::fun<std::string (const QComboBox *)>(&QtChai_Adapters::QComboBox_currentText), "currentText");
    chai->add(chaiscript::fun<bool (QComboBox *)>(&QComboBox::isEnabled), "isEnabled");
    chai->add(chaiscript::fun<bool (QComboBox *)>(&QComboBox::isVisible), "isVisisble");


///
/// QFontComboBox adapter
///

    chai->add(chaiscript::fun<int (QFontComboBox *)>(&QFontComboBox::count), "count");
    chai->add(chaiscript::fun<int (QFontComboBox *)>(&QFontComboBox::currentIndex), "currentIndex");
    chai->add(chaiscript::fun<std::string (const QFontComboBox *)>(&QtChai_Adapters::QFontComboBox_currentText), "currentText");
    chai->add(chaiscript::fun<bool (QFontComboBox *)>(&QFontComboBox::isEnabled), "isEnabled");
    chai->add(chaiscript::fun<bool (QFontComboBox *)>(&QFontComboBox::isVisible), "isVisisble");

///
/// QLineEdit adapter
///

    chai->add(chaiscript::fun<std::string (const QLineEdit *)>(&QtChai_Adapters::QLineEdit_selectedText), "selectedText");
    chai->add(chaiscript::fun<std::string (const QLineEdit *)>(&QtChai_Adapters::QLineEdit_text), "text");
    chai->add(chaiscript::fun<int (QLineEdit *)>(&QLineEdit::maxLength), "maxLength");
    chai->add(chaiscript::fun<int (QLineEdit *)>(&QLineEdit::cursorPosition), "cursorPosition");
    chai->add(chaiscript::fun<bool (QLineEdit *)>(&QLineEdit::isModified), "isModified");
    chai->add(chaiscript::fun<bool (QLineEdit *)>(&QLineEdit::hasSelectedText), "hasSelectedText");
    chai->add(chaiscript::fun<bool (QLineEdit *)>(&QLineEdit::isReadOnly), "isReadOnly");
    chai->add(chaiscript::fun<bool (QLineEdit *)>(&QLineEdit::isEnabled), "isEnabled");
    chai->add(chaiscript::fun<bool (QLineEdit *)>(&QLineEdit::isVisible), "isVisisble");


///
/// QTextEdit adapter
///
    chai->add(chaiscript::fun<std::string (const QTextEdit *)>(&QtChai_Adapters::QTextEdit_plainText), "plainText");
    chai->add(chaiscript::fun<bool (QTextEdit *)>(&QTextEdit::isReadOnly), "isReadOnly");
    chai->add(chaiscript::fun<bool (QTextEdit *)>(&QTextEdit::isEnabled), "isEnabled");
    chai->add(chaiscript::fun<bool (QTextEdit *)>(&QTextEdit::isVisible), "isVisisble");


///
/// QPlainTextEdit adapter
///
    chai->add(chaiscript::fun<std::string (const QPlainTextEdit *)>(&QtChai_Adapters::QPlainTextEdit_plainText), "plainText");
    chai->add(chaiscript::fun<bool (QPlainTextEdit *)>(&QPlainTextEdit::isReadOnly), "isReadOnly");
    chai->add(chaiscript::fun<bool (QPlainTextEdit *)>(&QPlainTextEdit::isEnabled), "isEnabled");
    chai->add(chaiscript::fun<bool (QPlainTextEdit *)>(&QPlainTextEdit::isVisible), "isVisisble");

///
/// QDial adapter
///
    chai->add(chaiscript::fun<int (QDial *)>(&QDial::maximum), "maximum");
    chai->add(chaiscript::fun<int (QDial *)>(&QDial::minimum), "minimum");
    chai->add(chaiscript::fun<int (QDial *)>(&QDial::value), "value");
    chai->add(chaiscript::fun<bool (QDial *)>(&QDial::isEnabled), "isEnabled");
    chai->add(chaiscript::fun<bool (QDial *)>(&QDial::isVisible), "isVisisble");


///
/// QSlider adapter
///

    chai->add(chaiscript::fun<int (QSlider *)>(&QSlider::maximum), "maximum");
    chai->add(chaiscript::fun<int (QSlider *)>(&QSlider::minimum), "minimum");
    chai->add(chaiscript::fun<int (QSlider *)>(&QSlider::value), "value");
    chai->add(chaiscript::fun<bool (QSlider *)>(&QSlider::isEnabled), "isEnabled");
    chai->add(chaiscript::fun<bool (QSlider *)>(&QSlider::isVisible), "isVisisble");

///
/// QScrollBar adapter
///

    chai->add(chaiscript::fun<int (QScrollBar *)>(&QScrollBar::maximum), "maximum");
    chai->add(chaiscript::fun<int (QScrollBar *)>(&QScrollBar::minimum), "minimum");
    chai->add(chaiscript::fun<int (QScrollBar *)>(&QScrollBar::value), "value");
    chai->add(chaiscript::fun<bool (QScrollBar *)>(&QScrollBar::isEnabled), "isEnabled");
    chai->add(chaiscript::fun<bool (QScrollBar *)>(&QScrollBar::isVisible), "isVisisble");

///
/// QLabel adapter
///

    chai->add(chaiscript::fun<std::string (const QLabel *)>(&QtChai_Adapters::QLabel_text), "text");
    chai->add(chaiscript::fun<bool (QLabel *)>(&QLabel::isEnabled), "isEnabled");
    chai->add(chaiscript::fun<bool (QLabel *)>(&QLabel::isVisible), "isVisisble");

///
/// QPushButton adapter
///
    chai->add(chaiscript::fun<std::string (const QPushButton *)>(&QtChai_Adapters::QPushButton_text), "text");

    chai->add(chaiscript::fun<bool (QPushButton *)>(&QPushButton::isDefault), "isDefault");
    chai->add(chaiscript::fun<bool (QPushButton *)>(&QPushButton::isCheckable), "isCheckable");
    chai->add(chaiscript::fun<bool (QPushButton *)>(&QPushButton::isChecked), "isChecked");
    chai->add(chaiscript::fun<bool (QPushButton *)>(&QPushButton::isDown), "isDown");
    chai->add(chaiscript::fun<bool (QPushButton *)>(&QPushButton::isEnabled), "isEnabled");
    chai->add(chaiscript::fun<bool (QPushButton *)>(&QPushButton::isVisible), "isVisisble");

///
/// QRadioButton adapter
///

    chai->add(chaiscript::fun<std::string (const QRadioButton *)>(&QtChai_Adapters::QRadioButton_text), "text");
    chai->add(chaiscript::fun<bool (QRadioButton *)>(&QRadioButton::isCheckable), "isCheckable");
    chai->add(chaiscript::fun<bool (QRadioButton *)>(&QRadioButton::isChecked), "isChecked");
    chai->add(chaiscript::fun<bool (QRadioButton *)>(&QRadioButton::isDown), "isDown");
    chai->add(chaiscript::fun<bool (QRadioButton *)>(&QRadioButton::isEnabled), "isEnabled");
    chai->add(chaiscript::fun<bool (QRadioButton *)>(&QRadioButton::isVisible), "isVisisble");

///
/// QCheckBox adapter
///

    chai->add(chaiscript::fun<std::string (const QCheckBox *)>(&QtChai_Adapters::QCheckBox_text), "text");
    chai->add(chaiscript::fun<bool (QCheckBox *)>(&QCheckBox::isCheckable), "isCheckable");
    chai->add(chaiscript::fun<bool (QCheckBox *)>(&QCheckBox::isChecked), "isChecked");
    chai->add(chaiscript::fun<bool (QCheckBox *)>(&QCheckBox::isDown), "isDown");
    chai->add(chaiscript::fun<bool (QCheckBox *)>(&QCheckBox::isEnabled), "isEnabled");
    chai->add(chaiscript::fun<bool (QCheckBox *)>(&QCheckBox::isVisible), "isVisisble");
    chai->add(chaiscript::fun<bool (QCheckBox *)>(&QCheckBox::isTristate), "isTristate");

///
/// QGroupkBox adapter
///

    chai->add(chaiscript::fun<std::string (const QGroupBox *)>(&QtChai_Adapters::QGroupBox_title), "title");
    chai->add(chaiscript::fun<bool (QGroupBox *)>(&QGroupBox::isCheckable), "isCheckable");
    chai->add(chaiscript::fun<bool (QGroupBox *)>(&QGroupBox::isChecked), "isChecked");
    chai->add(chaiscript::fun<bool (QGroupBox *)>(&QGroupBox::isEnabled), "isEnabled");
    chai->add(chaiscript::fun<bool (QGroupBox *)>(&QGroupBox::isVisible), "isVisisble");

}
