/****************************************************************************
** Meta object code from reading C++ file 'dynamicmenu.h'
**
** Created: Wed Dec 15 09:38:57 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dynamicmenu.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dynamicmenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_csu__qt__dynamic_menu__Handled_QMenu[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      38,   37,   37,   37, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_csu__qt__dynamic_menu__Handled_QMenu[] = {
    "csu::qt::dynamic_menu::Handled_QMenu\0"
    "\0handleMenu()\0"
};

const QMetaObject csu::qt::dynamic_menu::Handled_QMenu::staticMetaObject = {
    { &QMenu::staticMetaObject, qt_meta_stringdata_csu__qt__dynamic_menu__Handled_QMenu,
      qt_meta_data_csu__qt__dynamic_menu__Handled_QMenu, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &csu::qt::dynamic_menu::Handled_QMenu::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *csu::qt::dynamic_menu::Handled_QMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *csu::qt::dynamic_menu::Handled_QMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_csu__qt__dynamic_menu__Handled_QMenu))
        return static_cast<void*>(const_cast< Handled_QMenu*>(this));
    return QMenu::qt_metacast(_clname);
}

int csu::qt::dynamic_menu::Handled_QMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenu::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: handleMenu(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
static const uint qt_meta_data_csu__qt__dynamic_menu__Handled_QAction[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      40,   39,   39,   39, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_csu__qt__dynamic_menu__Handled_QAction[] = {
    "csu::qt::dynamic_menu::Handled_QAction\0"
    "\0handleMenu()\0"
};

const QMetaObject csu::qt::dynamic_menu::Handled_QAction::staticMetaObject = {
    { &QAction::staticMetaObject, qt_meta_stringdata_csu__qt__dynamic_menu__Handled_QAction,
      qt_meta_data_csu__qt__dynamic_menu__Handled_QAction, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &csu::qt::dynamic_menu::Handled_QAction::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *csu::qt::dynamic_menu::Handled_QAction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *csu::qt::dynamic_menu::Handled_QAction::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_csu__qt__dynamic_menu__Handled_QAction))
        return static_cast<void*>(const_cast< Handled_QAction*>(this));
    return QAction::qt_metacast(_clname);
}

int csu::qt::dynamic_menu::Handled_QAction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAction::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: handleMenu(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
