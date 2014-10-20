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

#include "qwidgetadapter.h"
#include <csu/base/ui/abstract_ui_roles/abs_ui_roles.h>

#include <cassert>
#include <boost/lexical_cast.hpp>

#include <QFontComboBox>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QDial>
#include <QTimeEdit>
#include <QDateEdit>
#include <QLineEdit>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QScrollBar>
#include <QSlider>
#include <QProgressBar>
#include <QLabel>
#include <QTextBrowser>
#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>
#include <QGroupBox>
#include <QFrame>
#include <QTabWidget>
#include <QMenuBar>
#include <QMenu>
#include <QMainWindow>
#include <QDialog>


#include <csu/qt/utils/qt_widget_utils.h>

namespace csu {
namespace qt {
namespace widget_adapter {
namespace QWA {

using namespace csu::base::ui::abstract_ui_datamodel;
using namespace csu::base::ui::abstract_ui_roles;

///
/// Adapter base class
///

template <typename T>
struct class_registrar
{
    static void register_class(QWidgetAdapterManager::AdapterSet& as)
    {
        QWidgetAdapterManager::AdapterSet::value_type::second_type& f =
            as[T::className()];
        f.af = T::applySensitiveValue;
        f.gf = T::sensitiveValue;
        f.arf = T::abstractRepresentation;
    }
};



///
/// Adapter manager
///


//check if sensitive and returns an
//adapter if true (null if not)
bool QWidgetAdapterManager::isAdaptable(QWidget* w)
{
    //if not inited, do it
    if (!inited) init();
    //get the name of the class
    std::string wclass = w->metaObject()->className();

    //QT BUG Overcoming
    //In QT, the className of QMainWindow objects return "MainWindow" instead of "QMainWindow",
    //therefore in order to override this behaviour we implement this adaption
    if (wclass=="MainWindow")
        wclass="QMainWindow";
    return adapters.find (wclass) != adapters.end();
}


template <typename W, typename ValueType = int>
struct sensitive_traits
{
    // Implementation for the default value
    static std::string sensitiveValue(QWidget* w)
    {
        return boost::lexical_cast<std::string>(
            dynamic_cast<W*>(w)->value());
    }

    // Application of the sensible value (default)
    static void applySensitiveValue(QWidget* w, const std::string& s)
    {
        dynamic_cast<W*>(w)->setValue(
            boost::lexical_cast<ValueType>(s));
    }

    // Default implementation
    static AUI::AbstractWidget* abstractRepresentation(QWidget* w)
    {
        return 0;//FIXME check this
    }
};

template <>
struct sensitive_traits<QComboBox>
{
    // Empty implementation for the default value
    static std::string sensitiveValue(QWidget* w)
    {
        return boost::lexical_cast<std::string>(
            dynamic_cast<QComboBox*>(w)->currentIndex());
    }

    // Empty application of the sensitive value
    static void applySensitiveValue(QWidget* w, const std::string& s)
    {
        dynamic_cast<QComboBox*>(w)->setCurrentIndex(
            boost::lexical_cast<int>(s));
    }

    // Default implementation
    static AUI::AbstractWidget* abstractRepresentation(QWidget* w)
    {
        //abstract widget (always)
        AUI::AbstractWidget* aw = new AUI::AbstractWidget();

        QComboBox* w_ = dynamic_cast<QComboBox*>(w);
        assert(w_);

        // widget basic properties
        QWidgetAdapterManager::FillWidgetBasicValues(aw,w);

        //Select the correct type of abstract widget
        aw->concreteType(AUI::AbstractWidget::COMBOBOX);

        // accessibe
        AUR::AccessibleRole ar(aw);
        aw->addRole<AUR::AccessibleRole>();
        ar.accessibleName(w_->accessibleName().toStdString());
        ar.accessibleDescription(w_->accessibleDescription().toStdString());

        // textual
        AUR::TextualRole tr(aw);
        aw->addRole<AUR::TextualRole>();
        tr.fontName(w_->font().family().toStdString());
        tr.fontSize(w_->font().pointSize());
        tr.backgroundColor(csu::qt::QWidgetUtils::getWidgetBackgroundColor(w_).toStdString());
        tr.textColor(csu::qt::QWidgetUtils::getWidgetForegroundColor(w_).toStdString());
        tr.text(w_->currentText().toStdString());

        // editable
        AUR::EditableRole er(aw);
        aw->addRole<AUR::EditableRole>();
        er.editableDefaultText(w_->currentText().toStdString());
        er.editableReadOnly(!w_->isEditable());
        er.editableLength(5);//fixed length

        return aw;
    }
};

template <>
struct sensitive_traits<QFontComboBox>
{
    // Empty implementation for the default value
    static std::string sensitiveValue(QWidget* w)
    {
        return boost::lexical_cast<std::string>(
            dynamic_cast<QFontComboBox*>(w)->currentIndex());
    }

    // Empty application of the sensitive value
    static void applySensitiveValue(QWidget* w, const std::string& s)
    {
        dynamic_cast<QFontComboBox*>(w)->setCurrentIndex(
            boost::lexical_cast<int>(s));
    }

    // Default implementation
    static AUI::AbstractWidget* abstractRepresentation(QWidget* w)
    {
        AUI::AbstractWidget* aw = new AUI::AbstractWidget();
        //abstract widget (always)
        QFontComboBox* w_ = dynamic_cast<QFontComboBox*>(w);
        assert(w_);

        // widget basic properties
        QWidgetAdapterManager::FillWidgetBasicValues(aw,w);

        //Select the correct type of abstract widget
        aw->concreteType(AUI::AbstractWidget::COMBOBOX);

        // accessibe
        AUR::AccessibleRole ar(aw);
        aw->addRole<AUR::AccessibleRole>();
        ar.accessibleName(w_->accessibleName().toStdString());
        ar.accessibleDescription(w_->accessibleDescription().toStdString());

        // textual
        AUR::TextualRole tr(aw);
        aw->addRole<AUR::TextualRole>();
        tr.fontName(w_->font().family().toStdString());
        tr.fontSize(w_->font().pointSize());
        tr.backgroundColor(csu::qt::QWidgetUtils::getWidgetBackgroundColor(w_).toStdString());
        tr.textColor(csu::qt::QWidgetUtils::getWidgetForegroundColor(w_).toStdString());
        tr.text(w_->currentText().toStdString());

        // editable
        AUR::EditableRole er(aw);
        aw->addRole<AUR::EditableRole>();
        er.editableDefaultText(w_->currentText().toStdString());
        er.editableReadOnly(!w_->isEditable());
        er.editableLength(5);//fixed length

        return aw;
    }
};

template <>
struct sensitive_traits<QDateTimeEdit>
{
    // Empty implementation for the default value
    static std::string sensitiveValue(QWidget* w)
    {
        return dynamic_cast<QDateTimeEdit*>(w)->dateTime().toString(Qt::ISODate).toStdString();
    }

    // Empty application of the sensitive value
    static void applySensitiveValue(QWidget* w, const std::string& s)
    {
        dynamic_cast<QDateTimeEdit*>(w)->dateTime().fromString(QString(s.c_str()),Qt::ISODate);
    }

    // Default implementation
    static AUI::AbstractWidget* abstractRepresentation(QWidget* w)
    {
        AUI::AbstractWidget* aw = new AUI::AbstractWidget();
        //abstract widget (always)
        QDateTimeEdit* w_ = dynamic_cast<QDateTimeEdit*>(w);
        assert(w_);

        // widget basic properties
        QWidgetAdapterManager::FillWidgetBasicValues(aw,w);

        //Select the correct type of abstract widget
        aw->concreteType(AUI::AbstractWidget::TEXTEDIT);

        // accessibe
        AUR::AccessibleRole ar(aw);
        aw->addRole<AUR::AccessibleRole>();
        ar.accessibleName(w_->accessibleName().toStdString());
        ar.accessibleDescription(w_->accessibleDescription().toStdString());

        // textual
        AUR::TextualRole tr(aw);
        aw->addRole<AUR::TextualRole>();
        tr.fontName(w_->font().family().toStdString());
        tr.fontSize(w_->font().pointSize());
        tr.backgroundColor(csu::qt::QWidgetUtils::getWidgetBackgroundColor(w_).toStdString());
        tr.textColor(csu::qt::QWidgetUtils::getWidgetForegroundColor(w_).toStdString());
        tr.text(w_->time().toString().toStdString());

        // editable
        AUR::EditableRole er(aw);
        aw->addRole<AUR::EditableRole>();
        er.editableDefaultText(w_->time().toString().toStdString());
        er.editableReadOnly(w_->isReadOnly());
        er.editableLength(5);//fixed length



        return aw;
    }
};

template <>
struct sensitive_traits<QDateEdit>
{
    // Empty implementation for the default value
    static std::string sensitiveValue(QWidget* w)
    {
        return dynamic_cast<QDateEdit*>(w)->date().toString(Qt::ISODate).toStdString();
    }

    // Empty application of the sensitive value
    static void applySensitiveValue(QWidget* w, const std::string& s)
    {
        dynamic_cast<QDateEdit*>(w)->date().fromString(QString(s.c_str()),Qt::ISODate);
    }

    // Default implementation
    static AUI::AbstractWidget* abstractRepresentation(QWidget* w)
    {
        AUI::AbstractWidget* aw = new AUI::AbstractWidget();
        //abstract widget (always)
        QDateEdit* w_ = dynamic_cast<QDateEdit*>(w);
        assert(w_);

        // widget basic properties
        QWidgetAdapterManager::FillWidgetBasicValues(aw,w);
        //Select the correct type of abstract widget
        aw->concreteType(AUI::AbstractWidget::TEXTEDIT);

        // accessibe
        AUR::AccessibleRole ar(aw);
        aw->addRole<AUR::AccessibleRole>();
        ar.accessibleName(w_->accessibleName().toStdString());
        ar.accessibleDescription(w_->accessibleDescription().toStdString());

        // textual
        AUR::TextualRole tr(aw);
        aw->addRole<AUR::TextualRole>();
        tr.fontName(w_->font().family().toStdString());
        tr.fontSize(w_->font().pointSize());
        tr.backgroundColor(csu::qt::QWidgetUtils::getWidgetBackgroundColor(w_).toStdString());
        tr.textColor(csu::qt::QWidgetUtils::getWidgetForegroundColor(w_).toStdString());
        tr.text(w_->time().toString().toStdString());

        // editable
        AUR::EditableRole er(aw);
        aw->addRole<AUR::EditableRole>();
        er.editableDefaultText(w_->time().toString().toStdString());
        er.editableReadOnly(w_->isReadOnly());
        er.editableLength(5);//fixed length


        return aw;
    }
};

template <>
struct sensitive_traits<QTimeEdit>
{
    // Empty implementation for the default value
    static std::string sensitiveValue(QWidget* w)
    {
        return dynamic_cast<QTimeEdit*>(w)->time().toString(Qt::ISODate).toStdString();
    }

    // Empty application of the sensitive value
    static void applySensitiveValue(QWidget* w, const std::string& s)
    {
        dynamic_cast<QTimeEdit*>(w)->time().fromString(QString(s.c_str()),Qt::ISODate);
    }

    // Default implementation
    static AUI::AbstractWidget* abstractRepresentation(QWidget* w)
    {
        AUI::AbstractWidget* aw = new AUI::AbstractWidget();
        //abstract widget (always)
        QTimeEdit* w_ = dynamic_cast<QTimeEdit*>(w);
        assert(w_);

        // widget basic properties
        QWidgetAdapterManager::FillWidgetBasicValues(aw,w);
        //Select the correct type of abstract widget
        aw->concreteType(AUI::AbstractWidget::TEXTEDIT);

        // accessibe
        AUR::AccessibleRole ar(aw);
        aw->addRole<AUR::AccessibleRole>();
        ar.accessibleName(w_->accessibleName().toStdString());
        ar.accessibleDescription(w_->accessibleDescription().toStdString());

        // textual
        AUR::TextualRole tr(aw);
        aw->addRole<AUR::TextualRole>();
        tr.fontName(w_->font().family().toStdString());
        tr.fontSize(w_->font().pointSize());
        tr.backgroundColor(csu::qt::QWidgetUtils::getWidgetBackgroundColor(w_).toStdString());
        tr.textColor(csu::qt::QWidgetUtils::getWidgetForegroundColor(w_).toStdString());
        tr.text(w_->time().toString().toStdString());

        // editable
        AUR::EditableRole er(aw);
        aw->addRole<AUR::EditableRole>();
        er.editableDefaultText(w_->time().toString().toStdString());
        er.editableReadOnly(w_->isReadOnly());
        er.editableLength(5);//fixed length


        return aw;
    }
};

template <>
struct sensitive_traits<QSpinBox>
{
    // Empty implementation for the default value
    static std::string sensitiveValue(QWidget* w)
    {
        //FIXME
        return boost::lexical_cast<std::string>(dynamic_cast<QSpinBox*>(w)->value());
    }

    // Empty application of the sensitive value
    static void applySensitiveValue(QWidget* w, const std::string& s)
    {
        //FIXME
        dynamic_cast<QSpinBox*>(w)->setValue(boost::lexical_cast<int>(s));
    }

    // Default implementation
    static AUI::AbstractWidget* abstractRepresentation(QWidget* w)
    {

        AUI::AbstractWidget* aw = new AUI::AbstractWidget();
        //abstract widget (always)
        QSpinBox* w_ = dynamic_cast<QSpinBox*>(w);
        assert(w_);

        // widget basic properties
        QWidgetAdapterManager::FillWidgetBasicValues(aw,w);
        //Select the correct type of abstract widget
        aw->concreteType(AUI::AbstractWidget::SPINBOX);


        // accessibe
        AUR::AccessibleRole ar(aw);
        aw->addRole<AUR::AccessibleRole>();
        ar.accessibleName(w_->accessibleName().toStdString());
        ar.accessibleDescription(w_->accessibleDescription().toStdString());



        // textual
        AUR::TextualRole tr(aw);
        aw->addRole<AUR::TextualRole>();
        tr.fontName(w_->font().family().toStdString());
        tr.fontSize(w_->font().pointSize());
        tr.backgroundColor(csu::qt::QWidgetUtils::getWidgetBackgroundColor(w_).toStdString());
        tr.textColor(csu::qt::QWidgetUtils::getWidgetForegroundColor(w_).toStdString());
        tr.text(boost::lexical_cast<std::string>(w_->value()));


        // editable
        AUR::EditableRole er(aw);
        aw->addRole<AUR::EditableRole>();
        er.editableDefaultText(boost::lexical_cast<std::string>(w_->value()));
        er.editableReadOnly(w_->isReadOnly());
        //FIXME: not sure about this value
        er.editableLength(5);//fixed length

        return aw;

    }
};

template <>
struct sensitive_traits<QDoubleSpinBox>
{
    // Empty implementation for the default value
    static std::string sensitiveValue(QWidget* w)
    {
        //FIXME
        return boost::lexical_cast<std::string>(dynamic_cast<QDoubleSpinBox*>(w)->value());
    }

    // Empty application of the sensitive value
    static void applySensitiveValue(QWidget* w, const std::string& s)
    {
        //FIXME
        dynamic_cast<QDoubleSpinBox*>(w)->setValue(boost::lexical_cast<double>(s));
    }

    // Default implementation
    static AUI::AbstractWidget* abstractRepresentation(QWidget* w)
    {
        AUI::AbstractWidget* aw = new AUI::AbstractWidget();
        //abstract widget (always)
        QDoubleSpinBox* w_ = dynamic_cast<QDoubleSpinBox*>(w);
        assert(w_);

        // widget basic properties
        QWidgetAdapterManager::FillWidgetBasicValues(aw,w);
        //Select the correct type of abstract widget
        aw->concreteType(AUI::AbstractWidget::SPINBOX);

        // accessibe
        AUR::AccessibleRole ar(aw);
        aw->addRole<AUR::AccessibleRole>();
        ar.accessibleName(w_->accessibleName().toStdString());
        ar.accessibleDescription(w_->accessibleDescription().toStdString());

        // textual
        AUR::TextualRole tr(aw);
        aw->addRole<AUR::TextualRole>();
        tr.fontName(w_->font().family().toStdString());
        tr.fontSize(w_->font().pointSize());
        tr.backgroundColor(csu::qt::QWidgetUtils::getWidgetBackgroundColor(w_).toStdString());
        tr.textColor(csu::qt::QWidgetUtils::getWidgetForegroundColor(w_).toStdString());
        tr.text(boost::lexical_cast<std::string>(w_->value()));

        // editable
        AUR::EditableRole er(aw);
        aw->addRole<AUR::EditableRole>();
        er.editableDefaultText(boost::lexical_cast<std::string>(w_->value()));
        er.editableReadOnly(w_->isReadOnly());
        //FIXME: not sure about this value
        er.editableLength(5);//fixed length



        return aw;

    }
};

template <>
struct sensitive_traits<QDial>
{
    // Empty implementation for the default value
    static std::string sensitiveValue(QWidget* w)
    {
        //FIXME
        return boost::lexical_cast<std::string>(dynamic_cast<QDial*>(w)->value());
    }

    // Empty application of the sensitive value
    static void applySensitiveValue(QWidget* w, const std::string& s)
    {
        //FIXME
        dynamic_cast<QDial*>(w)->setValue(boost::lexical_cast<int>(s));
    }

    // Default implementation
    static AUI::AbstractWidget* abstractRepresentation(QWidget* w)
    {
        AUI::AbstractWidget* aw = new AUI::AbstractWidget();
        //abstract widget (always)
        QDial* w_ = dynamic_cast<QDial*>(w);
        assert(w_);

        // widget basic properties
        QWidgetAdapterManager::FillWidgetBasicValues(aw,w);

        //Select the correct type of abstract widget
        aw->concreteType(AUI::AbstractWidget::SLIDER);

        // accessibe
        AUR::AccessibleRole ar(aw);
        aw->addRole<AUR::AccessibleRole>();
        ar.accessibleName(w_->accessibleName().toStdString());
        ar.accessibleDescription(w_->accessibleDescription().toStdString());

        //slider
        AUR::SliderRole sr(aw);
        aw->addRole<AUR::SliderRole>();
        sr.sliderMinValue(w_->minimum());
        sr.sliderMaxValue(w_->maximum());
        sr.sliderDefaultValue(w_->value());
        sr.sliderStep(w_->singleStep());
        return aw;

    }
};

template <>
struct sensitive_traits<QLineEdit>
{
    // Empty implementation for the default value
    static std::string sensitiveValue(QWidget* w)
    {
        return dynamic_cast<QLineEdit*>(w)->text().toStdString();
    }

    // Empty application of the sensitive value
    static void applySensitiveValue(QWidget* w, const std::string& s)
    {
        (dynamic_cast<QLineEdit*>(w))->setText(s.c_str());
    }

    // Default implementation
    static AUI::AbstractWidget* abstractRepresentation(QWidget* w)
    {
        AUI::AbstractWidget* aw = new AUI::AbstractWidget();
        //abstract widget (always)
        QLineEdit* w_ = dynamic_cast<QLineEdit*>(w);
        assert(w_);

        // widget basic properties
        QWidgetAdapterManager::FillWidgetBasicValues(aw,w);
        //Select the correct type of abstract widget
        aw->concreteType(AUI::AbstractWidget::TEXTEDIT);

        // accessibe
        AUR::AccessibleRole ar(aw);
        aw->addRole<AUR::AccessibleRole>();
        ar.accessibleName(w_->accessibleName().toStdString());
        ar.accessibleDescription(w_->accessibleDescription().toStdString());

        // textual
        AUR::TextualRole tr(aw);
        aw->addRole<AUR::TextualRole>();
        tr.fontName(w_->font().family().toStdString());
        tr.fontSize(w_->font().pointSize());
        tr.backgroundColor(csu::qt::QWidgetUtils::getWidgetBackgroundColor(w_).toStdString());
        tr.textColor(csu::qt::QWidgetUtils::getWidgetForegroundColor(w_).toStdString());
        tr.text(w_->text().toStdString());

        // editable
        AUR::EditableRole er(aw);
        aw->addRole<AUR::EditableRole>();
        er.editableDefaultText(w_->text().toStdString());
        er.editableReadOnly(w_->isReadOnly());
        er.editableLength(w_->maxLength());


        return aw;
    }
};

template <>
struct sensitive_traits<QTextEdit>
{
    // Empty implementation for the default value
    static std::string sensitiveValue(QWidget* w)
    {
        return dynamic_cast<QTextEdit*>(w)->toPlainText().toStdString();
    }

    // Empty application of the sensitive value
    static void applySensitiveValue(QWidget* w, const std::string& s)
    {
        (dynamic_cast<QTextEdit*>(w))->setText(s.c_str());
    }

    // Default implementation
    static AUI::AbstractWidget* abstractRepresentation(QWidget* w)
    {
        AUI::AbstractWidget* aw = new AUI::AbstractWidget();
        //abstract widget (always)
        QTextEdit* w_ = dynamic_cast<QTextEdit*>(w);
        assert(w_);

        // widget basic properties
        QWidgetAdapterManager::FillWidgetBasicValues(aw,w);
        //Select the correct type of abstract widget
        aw->concreteType(AUI::AbstractWidget::TEXTEDIT);

        // accessibe
        AUR::AccessibleRole ar(aw);
        aw->addRole<AUR::AccessibleRole>();
        ar.accessibleName(w_->accessibleName().toStdString());
        ar.accessibleDescription(w_->accessibleDescription().toStdString());

        // textual
        AUR::TextualRole tr(aw);
        aw->addRole<AUR::TextualRole>();
        tr.fontName(w_->font().family().toStdString());
        tr.fontSize(w_->font().pointSize());
        //FIXME: This widget has its own methods to work with color, compare if they are
        //better than these ones.
        tr.backgroundColor(csu::qt::QWidgetUtils::getWidgetBackgroundColor(w_).toStdString());
        tr.textColor(csu::qt::QWidgetUtils::getWidgetForegroundColor(w_).toStdString());
        tr.text(w_->toPlainText().toStdString());

        // editable
        AUR::EditableRole er(aw);
        aw->addRole<AUR::EditableRole>();
        er.editableDefaultText(w_->toPlainText().toStdString());
        er.editableReadOnly(w_->isReadOnly());
        //FIXME: I dont know wich property to get, fixed lenght now
        er.editableLength(5);


        return aw;
    }
};

template <>
struct sensitive_traits<QPlainTextEdit>
{
    // Empty implementation for the default value
    static std::string sensitiveValue(QWidget* w)
    {
        return dynamic_cast<QPlainTextEdit*>(w)->toPlainText().toStdString();
    }

    // Empty application of the sensitive value
    static void applySensitiveValue(QWidget* w, const std::string& s)
    {
        (dynamic_cast<QPlainTextEdit*>(w))->setPlainText(s.c_str());
    }

    // Default implementation
    static AUI::AbstractWidget* abstractRepresentation(QWidget* w)
    {
        AUI::AbstractWidget* aw = new AUI::AbstractWidget();
        //abstract widget (always)
        QPlainTextEdit* w_ = dynamic_cast<QPlainTextEdit*>(w);
        assert(w_);

        // widget basic properties
        QWidgetAdapterManager::FillWidgetBasicValues(aw,w);

        //Select the correct type of abstract widget
        aw->concreteType(AUI::AbstractWidget::TEXTEDIT);

        // accessibe
        AUR::AccessibleRole ar(aw);
        aw->addRole<AUR::AccessibleRole>();
        ar.accessibleName(w_->accessibleName().toStdString());
        ar.accessibleDescription(w_->accessibleDescription().toStdString());

        // textual
        AUR::TextualRole tr(aw);
        aw->addRole<AUR::TextualRole>();
        tr.fontName(w_->font().family().toStdString());
        tr.fontSize(w_->font().pointSize());
        tr.backgroundColor(csu::qt::QWidgetUtils::getWidgetBackgroundColor(w_).toStdString());
        tr.textColor(csu::qt::QWidgetUtils::getWidgetForegroundColor(w_).toStdString());
        tr.text(w_->toPlainText().toStdString());

        // editable
        AUR::EditableRole er(aw);
        aw->addRole<AUR::EditableRole>();
        er.editableDefaultText(w_->toPlainText().toStdString());
        er.editableReadOnly(w_->isReadOnly());
        //FIXME: I dont know wich property to get, fixed lenght now
        er.editableLength(5);


        return aw;
    }
};

template <>
struct sensitive_traits<QSlider>
{
    // Empty implementation for the default value
    static std::string sensitiveValue(QWidget* w)
    {
        return boost::lexical_cast<std::string>(dynamic_cast<QSlider*>(w)->value());
    }

    // Empty application of the sensitive value
    static void applySensitiveValue(QWidget* w, const std::string& s)
    {
        dynamic_cast<QSlider*>(w)->setValue(boost::lexical_cast<int>(s));
    }

    // Default implementation
    static AUI::AbstractWidget* abstractRepresentation(QWidget* w)
    {
        AUI::AbstractWidget* aw = new AUI::AbstractWidget();
        //abstract widget (always)
        QSlider* w_ = dynamic_cast<QSlider*>(w);
        assert(w_);

        // widget basic properties
        QWidgetAdapterManager::FillWidgetBasicValues(aw,w);
        //Select the correct type of abstract widget
        aw->concreteType(AUI::AbstractWidget::SLIDER);

        // accessibe
        AUR::AccessibleRole ar(aw);
        aw->addRole<AUR::AccessibleRole>();
        ar.accessibleName(w_->accessibleName().toStdString());
        ar.accessibleDescription(w_->accessibleDescription().toStdString());

        //slider
        AUR::SliderRole sr(aw);
        aw->addRole<AUR::SliderRole>();
        sr.sliderMinValue(w_->minimum());
        sr.sliderMaxValue(w_->maximum());
        sr.sliderDefaultValue(w_->value());
        sr.sliderStep(w_->singleStep());

        return aw;

    }
};

template <>
struct sensitive_traits<QScrollBar>
{
    // Empty implementation for the default value
    static std::string sensitiveValue(QWidget* w)
    {
        return boost::lexical_cast<std::string>(dynamic_cast<QScrollBar*>(w)->value());
    }

    // Empty application of the sensitive value
    static void applySensitiveValue(QWidget* w, const std::string& s)
    {
        dynamic_cast<QScrollBar*>(w)->setValue(boost::lexical_cast<int>(s));
    }

    // Default implementation
    static AUI::AbstractWidget* abstractRepresentation(QWidget* w)
    {
        AUI::AbstractWidget* aw = new AUI::AbstractWidget();
        //abstract widget (always)
        QScrollBar* w_ = dynamic_cast<QScrollBar*>(w);
        assert(w_);

        // widget basic properties
        QWidgetAdapterManager::FillWidgetBasicValues(aw,w);
        //Select the correct type of abstract widget
        aw->concreteType(AUI::AbstractWidget::SLIDER);

        // accessibe
        AUR::AccessibleRole ar(aw);
        aw->addRole<AUR::AccessibleRole>();
        ar.accessibleName(w_->accessibleName().toStdString());
        ar.accessibleDescription(w_->accessibleDescription().toStdString());

        //slider
        AUR::SliderRole sr(aw);
        aw->addRole<AUR::SliderRole>();
        sr.sliderMinValue(w_->minimum());
        sr.sliderMaxValue(w_->maximum());
        sr.sliderDefaultValue(w_->value());
        sr.sliderStep(w_->singleStep());

        return aw;

    }
};

template <>
struct sensitive_traits<QProgressBar>
{
    // Empty implementation for the default value
    static std::string sensitiveValue(QWidget* w)
    {
        return boost::lexical_cast<std::string>(dynamic_cast<QProgressBar*>(w)->value());
    }

    // Empty application of the sensitive value
    static void applySensitiveValue(QWidget* w, const std::string& s)
    {
        dynamic_cast<QProgressBar*>(w)->setValue(boost::lexical_cast<int>(s));
    }

    // Default implementation
    static AUI::AbstractWidget* abstractRepresentation(QWidget* w)
    {
        AUI::AbstractWidget* aw = new AUI::AbstractWidget();
        //abstract widget (always)
        QProgressBar* w_ = dynamic_cast<QProgressBar*>(w);
        assert(w_);

        // widget basic properties
        QWidgetAdapterManager::FillWidgetBasicValues(aw,w);

        //Select the correct type of abstract widget
        aw->concreteType(AUI::AbstractWidget::SLIDER);

        // accessibe
        AUR::AccessibleRole ar(aw);
        aw->addRole<AUR::AccessibleRole>();
        ar.accessibleName(w_->accessibleName().toStdString());
        ar.accessibleDescription(w_->accessibleDescription().toStdString());

        // textual
        AUR::TextualRole tr(aw);
        aw->addRole<AUR::TextualRole>();
        tr.fontName(w_->font().family().toStdString());
        tr.fontSize(w_->font().pointSize());
        tr.backgroundColor(csu::qt::QWidgetUtils::getWidgetBackgroundColor(w_).toStdString());
        tr.textColor(csu::qt::QWidgetUtils::getWidgetForegroundColor(w_).toStdString());
        tr.text(w_->text().toStdString());

        //slider
        AUR::SliderRole sr(aw);
        aw->addRole<AUR::SliderRole>();
        sr.sliderMinValue(w_->minimum());
        sr.sliderMaxValue(w_->maximum());
        sr.sliderDefaultValue(w_->value());
        sr.sliderStep(w_->value());

        return aw;

    }
};

template <>
struct sensitive_traits<QLabel>
{
    // Empty implementation for the default value
    static std::string sensitiveValue(QWidget* w)
    {
        return dynamic_cast<QLabel*>(w)->text().toStdString();
    }

    // Empty application of the sensitive value
    static void applySensitiveValue(QWidget* w, const std::string& s)
    {
        (dynamic_cast<QLabel*>(w))->setText(s.c_str());
    }

    // Default implementation
    static AUI::AbstractWidget* abstractRepresentation(QWidget* w)
    {
        AUI::AbstractWidget* aw = new AUI::AbstractWidget();
        //abstract widget (always)
        QLabel* w_ = dynamic_cast<QLabel*>(w);
        assert(w_);

        // widget basic properties
        QWidgetAdapterManager::FillWidgetBasicValues(aw,w);
        //Select the correct type of abstract widget
        aw->concreteType(AUI::AbstractWidget::TEXT);

        // accessibe
        AUR::AccessibleRole ar(aw);
        aw->addRole<AUR::AccessibleRole>();
        ar.accessibleName(w_->accessibleName().toStdString());
        ar.accessibleDescription(w_->accessibleDescription().toStdString());


        // textual
        AUR::TextualRole tr(aw);
        aw->addRole<AUR::TextualRole>();
        tr.fontName(w_->font().family().toStdString());
        tr.fontSize(w_->font().pointSize());
        tr.backgroundColor(csu::qt::QWidgetUtils::getWidgetBackgroundColor(w_).toStdString());
        tr.textColor(csu::qt::QWidgetUtils::getWidgetForegroundColor(w_).toStdString());
        tr.text(w_->text().toStdString());

        return aw;
    }
};

template <>
struct sensitive_traits<QTextBrowser>
{
    // Empty implementation for the default value
    static std::string sensitiveValue(QWidget* w)
    {
        return dynamic_cast<QTextBrowser*>(w)->toPlainText().toStdString();
    }

    // Empty application of the sensitive value
    static void applySensitiveValue(QWidget* w, const std::string& s)
    {
        (dynamic_cast<QTextBrowser*>(w))->setPlainText(s.c_str());
    }

    // Default implementation
    static AUI::AbstractWidget* abstractRepresentation(QWidget* w)
    {
        AUI::AbstractWidget* aw = new AUI::AbstractWidget();
        //abstract widget (always)
        QTextBrowser* w_ = dynamic_cast<QTextBrowser*>(w);
        assert(w_);

        // widget basic properties
        QWidgetAdapterManager::FillWidgetBasicValues(aw,w);
        //Select the correct type of abstract widget
        aw->concreteType(AUI::AbstractWidget::TEXT);

        // accessibe
        AUR::AccessibleRole ar(aw);
        aw->addRole<AUR::AccessibleRole>();
        ar.accessibleName(w_->accessibleName().toStdString());
        ar.accessibleDescription(w_->accessibleDescription().toStdString());

        // textual
        AUR::TextualRole tr(aw);
        aw->addRole<AUR::TextualRole>();
        tr.fontName(w_->font().family().toStdString());
        tr.fontSize(w_->font().pointSize());
        tr.backgroundColor(csu::qt::QWidgetUtils::getWidgetBackgroundColor(w_).toStdString());
        tr.textColor(csu::qt::QWidgetUtils::getWidgetForegroundColor(w_).toStdString());
        tr.text(w_->toPlainText().toStdString());

        return aw;
    }
};

template <>
struct sensitive_traits<QPushButton>
{
    // Empty implementation for the default value
    static std::string sensitiveValue(QWidget* w)
    {
        return dynamic_cast<QPushButton*>(w)->text().toStdString();
    }

    // Empty application of the sensitive value
    static void applySensitiveValue(QWidget* w, const std::string& s)
    {
        (dynamic_cast<QPushButton*>(w))->setText(s.c_str());
    }

    // Default implementation
    static AUI::AbstractWidget* abstractRepresentation(QWidget* w)
    {
        AUI::AbstractWidget* aw = new AUI::AbstractWidget();
        //abstract widget (always)
        QPushButton* w_ = dynamic_cast<QPushButton*>(w);
        assert(w_);

        // widget basic properties
        QWidgetAdapterManager::FillWidgetBasicValues(aw,w);

        //Select the correct type of abstract widget
        aw->concreteType(AUI::AbstractWidget::BUTTON);

        // accessibe
        AUR::AccessibleRole ar(aw);
        aw->addRole<AUR::AccessibleRole>();
        ar.accessibleName(w_->accessibleName().toStdString());
        ar.accessibleDescription(w_->accessibleDescription().toStdString());

        // textual
        AUR::TextualRole tr(aw);

        aw->addRole<AUR::TextualRole>();

        tr.fontName(w_->font().family().toStdString());
        tr.fontSize(w_->font().pointSize());
        tr.backgroundColor(csu::qt::QWidgetUtils::getWidgetBackgroundColor(w_).toStdString());
        tr.textColor(csu::qt::QWidgetUtils::getWidgetForegroundColor(w_).toStdString());
        tr.text(w_->text().toStdString());

        //Checkable
        AUR::CheckableRole cr(aw);
        aw->addRole<AUR::CheckableRole>();
        cr.checkableChecked(w_->isChecked());

        return aw;
    }
};

template <>
struct sensitive_traits<QCheckBox>
{
    // Empty implementation for the default value
    static std::string sensitiveValue(QWidget* w)
    {
        return dynamic_cast<QCheckBox*>(w)->text().toStdString();
    }

    // Empty application of the sensitive value
    static void applySensitiveValue(QWidget* w, const std::string& s)
    {
        (dynamic_cast<QCheckBox*>(w))->setText(s.c_str());
    }

    // Default implementation
    static AUI::AbstractWidget* abstractRepresentation(QWidget* w)
    {
        AUI::AbstractWidget* aw = new AUI::AbstractWidget();
        //abstract widget (always)
        QCheckBox* w_ = dynamic_cast<QCheckBox*>(w);
        assert(w_);

        // widget basic properties
        QWidgetAdapterManager::FillWidgetBasicValues(aw,w);

        //Select the correct type of abstract widget
        aw->concreteType(AUI::AbstractWidget::CHECKBOX);

        // accessibe
        AUR::AccessibleRole ar(aw);
        aw->addRole<AUR::AccessibleRole>();
        ar.accessibleName(w_->accessibleName().toStdString());
        ar.accessibleDescription(w_->accessibleDescription().toStdString());

        // textual
        AUR::TextualRole tr(aw);
        aw->addRole<AUR::TextualRole>();
        tr.fontName(w_->font().family().toStdString());
        tr.fontSize(w_->font().pointSize());
        tr.backgroundColor(csu::qt::QWidgetUtils::getWidgetBackgroundColor(w_).toStdString());
        tr.textColor(csu::qt::QWidgetUtils::getWidgetForegroundColor(w_).toStdString());
        tr.text(w_->text().toStdString());

        //Checkable
        AUR::CheckableRole cr(aw);
        aw->addRole<AUR::CheckableRole>();
        cr.checkableChecked(w_->isChecked());


        return aw;
    }
};

template <>
struct sensitive_traits<QRadioButton>
{
    // Empty implementation for the default value
    static std::string sensitiveValue(QWidget* w)
    {
        return dynamic_cast<QRadioButton*>(w)->text().toStdString();
    }

    // Empty application of the sensitive value
    static void applySensitiveValue(QWidget* w, const std::string& s)
    {
        (dynamic_cast<QRadioButton*>(w))->setText(s.c_str());
    }

    // Default implementation
    static AUI::AbstractWidget* abstractRepresentation(QWidget* w)
    {
        AUI::AbstractWidget* aw = new AUI::AbstractWidget();
        //abstract widget (always)
        QRadioButton* w_ = dynamic_cast<QRadioButton*>(w);
        assert(w_);

        // widget basic properties
        QWidgetAdapterManager::FillWidgetBasicValues(aw,w);

        //Select the correct type of abstract widget
        aw->concreteType(AUI::AbstractWidget::RADIOBUTTON);

        // accessibe
        AUR::AccessibleRole ar(aw);
        aw->addRole<AUR::AccessibleRole>();
        ar.accessibleName(w_->accessibleName().toStdString());
        ar.accessibleDescription(w_->accessibleDescription().toStdString());

        // textual
        AUR::TextualRole tr(aw);
        aw->addRole<AUR::TextualRole>();
        tr.fontName(w_->font().family().toStdString());
        tr.fontSize(w_->font().pointSize());
        tr.backgroundColor(csu::qt::QWidgetUtils::getWidgetBackgroundColor(w_).toStdString());
        tr.textColor(csu::qt::QWidgetUtils::getWidgetForegroundColor(w_).toStdString());
        tr.text(w_->text().toStdString());

        //Checkable
        AUR::CheckableRole cr(aw);
        aw->addRole<AUR::CheckableRole>();
        cr.checkableChecked(w_->isChecked());

        //Excludable
        aw->addRole<AUR::ExcludableRole>();

        //Grouped
        AUR::GroupedRole gr(aw);
        aw->addRole<AUR::GroupedRole>();
        assert(w->parent());
        gr.groupedParent(csu::qt::QWidgetUtils::getWidgetPath((QWidget *)w_->parent()).toStdString());
        gr.groupedBrothers(*csu::qt::QWidgetUtils::getStdWidgetBrothers(w_));

        return aw;
    }
};

template <>
struct sensitive_traits<QGroupBox>
{
    // Empty implementation for the default value
    static std::string sensitiveValue(QWidget* w)
    {
        return dynamic_cast<QGroupBox*>(w)->title().toStdString();
    }

    // Empty application of the sensitive value
    static void applySensitiveValue(QWidget* w, const std::string& s)
    {
        (dynamic_cast<QGroupBox*>(w))->setTitle(s.c_str());;
    }

    // Default implementation
    static AUI::AbstractWidget* abstractRepresentation(QWidget* w)
    {
        AUI::AbstractWidget* aw = new AUI::AbstractWidget();
        //abstract widget (always)
        QGroupBox* w_ = dynamic_cast<QGroupBox*>(w);
        assert(w_);

        // widget basic properties
        QWidgetAdapterManager::FillWidgetBasicValues(aw,w);

        //Select the correct type of abstract widget
        aw->concreteType(AUI::AbstractWidget::CONTAINERBOX);

        // accessibe
        AUR::AccessibleRole ar(aw);
        aw->addRole<AUR::AccessibleRole>();
        ar.accessibleName(w_->accessibleName().toStdString());
        ar.accessibleDescription(w_->accessibleDescription().toStdString());

        // textual
        AUR::TextualRole tr(aw);
        aw->addRole<AUR::TextualRole>();
        tr.fontName(w_->font().family().toStdString());
        tr.fontSize(w_->font().pointSize());
        tr.backgroundColor(csu::qt::QWidgetUtils::getWidgetBackgroundColor(w_).toStdString());
        tr.textColor(csu::qt::QWidgetUtils::getWidgetForegroundColor(w_).toStdString());
        tr.text(w_->title().toStdString());

        //Checkable. Yes, this widget can be checkable
        AUR::CheckableRole cr(aw);
        aw->addRole<AUR::CheckableRole>();
        cr.checkableChecked(w_->isChecked());

        //Container
        AUR::ContainerRole conr(aw);
        aw->addRole<AUR::ContainerRole>();
        conr.containerChildren(*csu::qt::QWidgetUtils::getStdWidgetChildren(w_));
        conr.containerHasTags(false);

        return aw;
    }
};

template <>
struct sensitive_traits<QFrame>
{
    // Empty implementation for the default value
    static std::string sensitiveValue(QWidget* w)
    {
        return dynamic_cast<QFrame*>(w)->objectName().toStdString();
    }

    // Empty application of the sensitive value
    static void applySensitiveValue(QWidget* w, const std::string& s)
    {
        (dynamic_cast<QFrame*>(w))->setObjectName(s.c_str());
    }

    // Default implementation
    static AUI::AbstractWidget* abstractRepresentation(QWidget* w)
    {
        AUI::AbstractWidget* aw = new AUI::AbstractWidget();
        //abstract widget (always)
        QFrame* w_ = dynamic_cast<QFrame*>(w);
        assert(w_);

        // widget basic properties
        QWidgetAdapterManager::FillWidgetBasicValues(aw,w);

        //Select the correct type of abstract widget
        aw->concreteType(AUI::AbstractWidget::FRAME);

        // accessibe
        AUR::AccessibleRole ar(aw);
        aw->addRole<AUR::AccessibleRole>();
        ar.accessibleName(w_->accessibleName().toStdString());
        ar.accessibleDescription(w_->accessibleDescription().toStdString());

        //Container
        AUR::ContainerRole conr(aw);
        aw->addRole<AUR::ContainerRole>();
        conr.containerChildren(*csu::qt::QWidgetUtils::getStdWidgetChildren(w_));
        conr.containerHasTags(false);

        return aw;
    }
};

template <>
struct sensitive_traits<QTabWidget>
{
    // Empty implementation for the default value
    static std::string sensitiveValue(QWidget* w)
    {
        return boost::lexical_cast<std::string>(
            dynamic_cast<QTabWidget*>(w)->currentIndex());
    }

    // Empty application of the sensitive value
    static void applySensitiveValue(QWidget* w, const std::string& s)
    {
        dynamic_cast<QTabWidget*>(w)->setCurrentIndex(
            boost::lexical_cast<int>(s));
    }

    // Default implementation
    static AUI::AbstractWidget* abstractRepresentation(QWidget* w)
    {
        AUI::AbstractWidget* aw = new AUI::AbstractWidget();
        //abstract widget (always)
        QTabWidget* w_ = dynamic_cast<QTabWidget*>(w);
        assert(w_);

        // widget basic properties
        QWidgetAdapterManager::FillWidgetBasicValues(aw,w);

        //Select the correct type of abstract widget
        aw->concreteType(AUI::AbstractWidget::TABPANEL);

        // accessibe
        AUR::AccessibleRole ar(aw);
        aw->addRole<AUR::AccessibleRole>();
        ar.accessibleName(w_->accessibleName().toStdString());
        ar.accessibleDescription(w_->accessibleDescription().toStdString());

        // textual
        AUR::TextualRole tr(aw);
        aw->addRole<AUR::TextualRole>();
        tr.fontName(w_->font().family().toStdString());
        tr.fontSize(w_->font().pointSize());
        tr.backgroundColor(csu::qt::QWidgetUtils::getWidgetBackgroundColor(w_).toStdString());
        tr.textColor(csu::qt::QWidgetUtils::getWidgetForegroundColor(w_).toStdString());
        tr.text(w_->tabText(w_->currentIndex()).toStdString());



        //Container
        AUR::ContainerRole conr(aw);
        aw->addRole<AUR::ContainerRole>();
        conr.containerChildren(*csu::qt::QWidgetUtils::getStdWidgetChildren(w_));
        conr.containerHasTags(true);
        AUI::StringList tablist;
        for (int i=0;i<w_->count();i++)
        {
            tablist.push_back(w_->tabText(i).toStdString());
        }
        conr.containerTabLabel(tablist);

        return aw;
    }
};

template <>
struct sensitive_traits<QMenuBar>
{
    // Empty implementation for the default value
    static std::string sensitiveValue(QWidget* w)
    {
        return boost::lexical_cast<std::string>(
            dynamic_cast<QMenuBar*>(w)->objectName().toStdString());
    }

    // Empty application of the sensitive value
    static void applySensitiveValue(QWidget* w, const std::string& s)
    {
        dynamic_cast<QMenuBar*>(w)->setObjectName(s.c_str());
    }

    // Default implementation
    static AUI::AbstractWidget* abstractRepresentation(QWidget* w)
    {
        AUI::AbstractWidget* aw = new AUI::AbstractWidget();
        //abstract widget (always)
        QMenuBar* w_ = dynamic_cast<QMenuBar*>(w);
        assert(w_);

        // widget basic properties
        QWidgetAdapterManager::FillWidgetBasicValues(aw,w);

        //Select the correct type of abstract widget
        aw->concreteType(AUI::AbstractWidget::BAR);

        // accessibe
        AUR::AccessibleRole ar(aw);
        aw->addRole<AUR::AccessibleRole>();
        ar.accessibleName(w_->accessibleName().toStdString());
        ar.accessibleDescription(w_->accessibleDescription().toStdString());


        //Container
        AUR::ContainerRole conr(aw);
        aw->addRole<AUR::ContainerRole>();
        //FIXME: Does it really work for MenuBar?
        conr.containerChildren(*csu::qt::QWidgetUtils::getStdWidgetChildren(w_));
        conr.containerHasTags(false);

        return aw;
    }
};

template <>
struct sensitive_traits<QMenu>
{
    // Empty implementation for the default value
    static std::string sensitiveValue(QWidget* w)
    {
        return boost::lexical_cast<std::string>(
            dynamic_cast<QMenu*>(w)->title().toStdString());
    }

    // Empty application of the sensitive value
    static void applySensitiveValue(QWidget* w, const std::string& s)
    {
        dynamic_cast<QMenu*>(w)->setTitle(s.c_str());
    }

    // Default implementation
    static AUI::AbstractWidget* abstractRepresentation(QWidget* w)
    {

        AUI::AbstractWidget* aw = new AUI::AbstractWidget();
        //abstract widget (always)
        QMenu* w_ = dynamic_cast<QMenu*>(w);
        assert(w_);

        // widget basic properties
        QWidgetAdapterManager::FillWidgetBasicValues(aw,w);

        //Select the correct type of abstract widget
        aw->concreteType(AUI::AbstractWidget::MENU);

        // accessibe
        AUR::AccessibleRole ar(aw);
        aw->addRole<AUR::AccessibleRole>();
        ar.accessibleName(w_->accessibleName().toStdString());
        ar.accessibleDescription(w_->accessibleDescription().toStdString());

        // textual
        AUR::TextualRole tr(aw);
        aw->addRole<AUR::TextualRole>();
        tr.fontName(w_->font().family().toStdString());
        tr.fontSize(w_->font().pointSize());
        tr.backgroundColor(csu::qt::QWidgetUtils::getWidgetBackgroundColor(w_).toStdString());
        tr.textColor(csu::qt::QWidgetUtils::getWidgetForegroundColor(w_).toStdString());
        tr.text(w_->title().toStdString());

        //Container
        AUR::ContainerRole conr(aw);
        aw->addRole<AUR::ContainerRole>();
        //FIXME: Does it really work for Menu?
        //Associated actions are not include into its children
        conr.containerChildren(*csu::qt::QWidgetUtils::getStdWidgetChildren(w_));
        conr.containerHasTags(false);

        //Menu
        AUR::MenuRole mr(aw);
        aw->addRole<AUR::MenuRole>();
        mr.menuName(w_->title().toStdString());
        mr.menuAction(w_->isEmpty());

        return aw;
    }
};

template <>
struct sensitive_traits<QDialog>
{
    // Empty implementation for the default value
    static std::string sensitiveValue(QWidget* w)
    {
        return boost::lexical_cast<std::string>(
            dynamic_cast<QDialog*>(w)->windowTitle().toStdString());
    }

    // Empty application of the sensitive value
    static void applySensitiveValue(QWidget* w, const std::string& s)
    {
        dynamic_cast<QDialog*>(w)->setWindowTitle(s.c_str());
    }

    // Default implementation
    static AUI::AbstractWidget* abstractRepresentation(QWidget* w)
    {
        AUI::AbstractWidget* aw = new AUI::AbstractWidget();
        //abstract widget (always)
        QDialog* w_ = dynamic_cast<QDialog*>(w);
        assert(w_);

        // widget basic properties
        QWidgetAdapterManager::FillWidgetBasicValues(aw,w);

        //Select the correct type of abstract widget
        aw->concreteType(AUI::AbstractWidget::DIALOG);

        // accessibe
        AUR::AccessibleRole ar(aw);
        aw->addRole<AUR::AccessibleRole>();
        ar.accessibleName(w_->accessibleName().toStdString());
        ar.accessibleDescription(w_->accessibleDescription().toStdString());


        // textual
        AUR::TextualRole tr(aw);
        aw->addRole<AUR::TextualRole>();
        tr.fontName(w_->font().family().toStdString());
        tr.fontSize(w_->font().pointSize());
        tr.backgroundColor(csu::qt::QWidgetUtils::getWidgetBackgroundColor(w_).toStdString());
        tr.textColor(csu::qt::QWidgetUtils::getWidgetForegroundColor(w_).toStdString());

        //Hack to store if MainWindow has a system frame or not
        // There are two ways to know it:
        // -- get the widow flags and see if Qt::FramelessWindowHint is enabled
        // -- watch if the window is shown in fullscreen. A widget in full screen mode
        // occupies the whole screen area and does not display window decorations, such as a title bar
        Qt::WindowFlags flags= w_->windowFlags();
        if (flags.testFlag(Qt::FramelessWindowHint))
            tr.text("FRAMELESSWINDOWHINT");
        else
            tr.text(w_->windowTitle().toStdString());

        //Container
        AUR::ContainerRole conr(aw);
        aw->addRole<AUR::ContainerRole>();
        conr.containerChildren(*csu::qt::QWidgetUtils::getStdWidgetChildren(w_));
        conr.containerHasTags(false);

        ///
        /// Dialog
        AUR::DialogRole dlgr(aw);
        aw->addRole<AUR::DialogRole>();
        dlgr.tittle(w_->windowTitle().toStdString());
        dlgr.movable(w_->isTopLevel());//FIXME
        //no resizable if both (h&v) policies are "fixed"
        dlgr.resizable(!(w_->sizePolicy().horizontalPolicy() == QSizePolicy::Fixed
                         && w_->sizePolicy().verticalPolicy()  == QSizePolicy::Fixed));
        dlgr.minimizable(w_->isTopLevel());
        dlgr.closable(w_->isTopLevel());
        dlgr.windowDecoration(!w_->windowFlags().testFlag(Qt::FramelessWindowHint));

        return aw;
    }
};

template <>
struct sensitive_traits<QMainWindow>
{
    // Empty implementation for the default value
    static std::string sensitiveValue(QWidget* w)
    {
        return boost::lexical_cast<std::string>(
            dynamic_cast<QMainWindow*>(w)->windowTitle().toStdString());

    }

    // Empty application of the sensitive value
    static void applySensitiveValue(QWidget* w, const std::string& s)
    {
        dynamic_cast<QMainWindow*>(w)->setWindowTitle(s.c_str());
    }

    // Default implementation
    static AUI::AbstractWidget* abstractRepresentation(QWidget* w)
    {
        AUI::AbstractWidget* aw = new AUI::AbstractWidget();

        //abstract widget (always)
        QMainWindow* w_ = dynamic_cast<QMainWindow*>(w);
        assert(w_);

        // widget basic properties
        QWidgetAdapterManager::FillWidgetBasicValues(aw,w);

        //Select the correct type of abstract widget
        aw->concreteType(AUI::AbstractWidget::WINDOW);

        // accessibe
        AUR::AccessibleRole ar(aw);
        aw->addRole<AUR::AccessibleRole>();
        ar.accessibleName(w_->accessibleName().toStdString());
        ar.accessibleDescription(w_->accessibleDescription().toStdString());

        // textual
        AUR::TextualRole tr(aw);
        aw->addRole<AUR::TextualRole>();
        tr.fontName(w_->font().family().toStdString());
        tr.fontSize(w_->font().pointSize());
        tr.backgroundColor(csu::qt::QWidgetUtils::getWidgetBackgroundColor(w_).toStdString());
        tr.textColor(csu::qt::QWidgetUtils::getWidgetForegroundColor(w_).toStdString());

        //Container
        AUR::ContainerRole conr(aw);
        aw->addRole<AUR::ContainerRole>();
        conr.containerChildren(*csu::qt::QWidgetUtils::getStdWidgetChildren(w_));
        conr.containerHasTags(false);

        ///
        /// Dialog
        AUR::DialogRole dlgr(aw);
        aw->addRole<AUR::DialogRole>();
        dlgr.tittle(w_->windowTitle().toStdString());
        dlgr.movable(true);
        //no resizable if both (h&v) policies are "fixed"
        dlgr.resizable(!(w_->sizePolicy().horizontalPolicy() == QSizePolicy::Fixed
                         && w_->sizePolicy().verticalPolicy()  == QSizePolicy::Fixed));
        dlgr.minimizable(true);
        dlgr.closable(true);
        //Store if MainWindow has a system frame or not
        // There are two ways to know it:
        // -- get the widow flags and see if Qt::FramelessWindowHint is enabled
        // -- watch if the window is shown in fullscreen. A widget in full screen mode
        // occupies the whole screen area and does not display window decorations, such as a title bar
        dlgr.windowDecoration(!w_->windowFlags().testFlag(Qt::FramelessWindowHint));

        return aw;
    }
};

template<typename T, typename s_traits = sensitive_traits<T> >
struct adapter
{
    static std::string className()
    {
        return T().metaObject()->className();
    }

    // Return sensitive Value based on the traits
    static std::string sensitiveValue(QWidget* w)
    {
        return s_traits::sensitiveValue (w);
    }

    // Generic stablishment of a sensitiveValue
    static void applySensitiveValue(QWidget* w, const std::string& s)
    {
        s_traits::applySensitiveValue (w, s);
    }

    static AUI::AbstractWidget* abstractRepresentation(QWidget* w)
    {
        return s_traits::abstractRepresentation (w);
    }
};

/// ////////////////////////////////////////
///
/// QWidgetAdapterManager                ///
///
/// ////////////////////////////////////////

// Static variables of QWidgetAdapterManager
bool QWidgetAdapterManager::inited = false;
QWidgetAdapterManager::AdapterSet QWidgetAdapterManager::adapters;

void QWidgetAdapterManager::init()
{
    if (!inited)
    {
        //Input Widgets
        class_registrar< adapter <QSpinBox> >::register_class(adapters);
        class_registrar< adapter <QDoubleSpinBox> >::register_class(adapters);
        class_registrar< adapter <QTimeEdit> >::register_class (adapters);
        class_registrar< adapter <QDateEdit> >::register_class(adapters);
        class_registrar< adapter <QDateTimeEdit> >::register_class(adapters);
        class_registrar< adapter <QDial> >::register_class(adapters);
        class_registrar< adapter <QComboBox> >::register_class(adapters);
        class_registrar< adapter <QFontComboBox> >::register_class(adapters);
        class_registrar< adapter <QLineEdit> >::register_class(adapters);
        class_registrar< adapter <QTextEdit> >::register_class(adapters);
        class_registrar< adapter <QPlainTextEdit> >::register_class(adapters);
        class_registrar< adapter <QSlider> >::register_class(adapters);
        class_registrar< adapter <QScrollBar> >::register_class(adapters);

        //Display Widgets
        class_registrar< adapter <QProgressBar> >::register_class(adapters);
        class_registrar< adapter <QLabel> >::register_class(adapters);
        class_registrar< adapter <QTextBrowser> >::register_class(adapters);

        //Buttons
        class_registrar< adapter <QPushButton> >::register_class(adapters);
        class_registrar< adapter <QRadioButton> >::register_class(adapters);
        class_registrar< adapter <QCheckBox> >::register_class(adapters);


        //Containers
        class_registrar< adapter <QGroupBox> >::register_class(adapters);
        class_registrar< adapter <QFrame> >::register_class(adapters);
        class_registrar< adapter <QTabWidget> >::register_class(adapters);
        class_registrar< adapter <QMenuBar> >::register_class(adapters);

        //Menu
        class_registrar< adapter <QMenu> >::register_class(adapters);

        //Window
        class_registrar< adapter <QMainWindow> >::register_class(adapters);
        class_registrar< adapter <QDialog> >::register_class(adapters);

        inited = true;
    }
}

std::string QWidgetAdapterManager::sensitiveValue(QWidget* w)
{
    if (!inited) init();
    assert(w);
    //get the name of the class
    std::string wclass = w->metaObject()->className();

    //QT BUG Overcoming
    //In QT, the className of QMainWindow objects return "MainWindow" instead of "QMainWindow",
    //therefore in order to override this behaviour we implement this adaption
    if (wclass=="MainWindow")
        wclass="QMainWindow";
    return adapters[wclass].gf (w);
    //return adapters[w->metaObject()->className()].gf (w);
}

// Application of the sensible value (default)
void QWidgetAdapterManager::applySensitiveValue(QWidget* w, const std::string& s)
{
    if (!inited) init();
    assert(w);
    //get the name of the class
    std::string wclass = w->metaObject()->className();

    //QT BUG Overcoming
    //In QT, the className of QMainWindow objects return "MainWindow" instead of "QMainWindow",
    //therefore in order to override this behaviour we implement this adaption
    if (wclass=="MainWindow")
        wclass="QMainWindow";
    return adapters[wclass].af (w, s);
    //return adapters[w->metaObject()->className()].af (w, s);
}

// Default implementation
csu::base::ui::abstract_ui_datamodel::AUI::AbstractWidget*
QWidgetAdapterManager::abstractRepresentation(QWidget* w)
{
    if (!inited) init();
    assert(w);

    //QT BUG Overcoming
    //In QT, the className of QMainWindow objects return "MainWindow" instead of "QMainWindow",
    //therefore in order to override this behaviour we implement this adaption
    std::string wclass=w->metaObject()->className();
    if (wclass=="MainWindow")
        return adapters["QMainWindow"].arf (w);
    else
        return adapters[w->metaObject()->className()].arf (w);
}

///
/// supporting methods
///

void QWidgetAdapterManager::FillWidgetBasicValues(
    csu::base::ui::abstract_ui_datamodel::AUI::AbstractWidget* aw,
    QWidget* w)
{
    assert(w);

    aw->name(QWidgetUtils::getWidgetPath(w).toStdString());

    aw->x(w->x());
    aw->y(w->y());

    aw->height(w->height());
    aw->width(w->width());

    aw->enabled(w->isEnabled());
    aw->visible(w->isVisible());
    aw->hidden(w->isHidden());
    aw->tooltip(w->toolTip().toStdString());

    aw->concreteType(AUI::AbstractWidget::ABSTRACTWIDGET);
}

}//QWA
}//widget_adapter
}//qt
}//csu
