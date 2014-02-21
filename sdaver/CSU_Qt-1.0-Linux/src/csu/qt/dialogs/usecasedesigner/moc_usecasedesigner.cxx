/****************************************************************************
** Meta object code from reading C++ file 'usecasedesigner.h'
**
** Created: Wed Dec 15 09:38:57 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "usecasedesigner.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'usecasedesigner.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_csu__qt__dialog__usecasedesigner__UseCaseDesigner[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      51,   50,   50,   50, 0x08,
      82,   50,   50,   50, 0x08,
     117,   50,   50,   50, 0x08,
     149,   50,   50,   50, 0x08,
     194,  182,   50,   50, 0x08,
     243,   50,   50,   50, 0x08,
     280,   50,   50,   50, 0x08,
     311,   50,   50,   50, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_csu__qt__dialog__usecasedesigner__UseCaseDesigner[] = {
    "csu::qt::dialog::usecasedesigner::UseCaseDesigner\0"
    "\0on_deleteStageButton_clicked()\0"
    "on_editcancelStageButton_clicked()\0"
    "on_newsaveStageButton_clicked()\0"
    "on_deleteUseCaseButton_clicked()\0"
    "item,column\0"
    "on_usecaseTree_itemClicked(QTreeWidgetItem*,int)\0"
    "on_editcancelUseCaseButton_clicked()\0"
    "on_closeDialogButton_clicked()\0"
    "on_newsaveUseCaseButton_clicked()\0"
};

const QMetaObject csu::qt::dialog::usecasedesigner::UseCaseDesigner::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_csu__qt__dialog__usecasedesigner__UseCaseDesigner,
      qt_meta_data_csu__qt__dialog__usecasedesigner__UseCaseDesigner, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &csu::qt::dialog::usecasedesigner::UseCaseDesigner::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *csu::qt::dialog::usecasedesigner::UseCaseDesigner::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *csu::qt::dialog::usecasedesigner::UseCaseDesigner::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_csu__qt__dialog__usecasedesigner__UseCaseDesigner))
        return static_cast<void*>(const_cast< UseCaseDesigner*>(this));
    return QDialog::qt_metacast(_clname);
}

int csu::qt::dialog::usecasedesigner::UseCaseDesigner::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_deleteStageButton_clicked(); break;
        case 1: on_editcancelStageButton_clicked(); break;
        case 2: on_newsaveStageButton_clicked(); break;
        case 3: on_deleteUseCaseButton_clicked(); break;
        case 4: on_usecaseTree_itemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: on_editcancelUseCaseButton_clicked(); break;
        case 6: on_closeDialogButton_clicked(); break;
        case 7: on_newsaveUseCaseButton_clicked(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
