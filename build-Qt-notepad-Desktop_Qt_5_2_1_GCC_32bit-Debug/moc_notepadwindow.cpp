/****************************************************************************
** Meta object code from reading C++ file 'notepadwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Qt-notepad/notepadwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'notepadwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NotepadWindow_t {
    QByteArrayData data[13];
    char stringdata[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_NotepadWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_NotepadWindow_t qt_meta_stringdata_NotepadWindow = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 7),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 9),
QT_MOC_LITERAL(4, 33, 8),
QT_MOC_LITERAL(5, 42, 7),
QT_MOC_LITERAL(6, 50, 7),
QT_MOC_LITERAL(7, 58, 12),
QT_MOC_LITERAL(8, 71, 12),
QT_MOC_LITERAL(9, 84, 14),
QT_MOC_LITERAL(10, 99, 10),
QT_MOC_LITERAL(11, 110, 13),
QT_MOC_LITERAL(12, 124, 11)
    },
    "NotepadWindow\0alAbrir\0\0alGuardar\0"
    "alFuente\0alSalir\0alAyuda\0herr_cursiva\0"
    "herr_negrita\0herr_subrayado\0ali_centro\0"
    "ali_izquierda\0ali_derecha\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NotepadWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08,
       3,    0,   70,    2, 0x08,
       4,    0,   71,    2, 0x08,
       5,    0,   72,    2, 0x08,
       6,    0,   73,    2, 0x08,
       7,    0,   74,    2, 0x08,
       8,    0,   75,    2, 0x08,
       9,    0,   76,    2, 0x08,
      10,    0,   77,    2, 0x08,
      11,    0,   78,    2, 0x08,
      12,    0,   79,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NotepadWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NotepadWindow *_t = static_cast<NotepadWindow *>(_o);
        switch (_id) {
        case 0: _t->alAbrir(); break;
        case 1: _t->alGuardar(); break;
        case 2: _t->alFuente(); break;
        case 3: _t->alSalir(); break;
        case 4: _t->alAyuda(); break;
        case 5: _t->herr_cursiva(); break;
        case 6: _t->herr_negrita(); break;
        case 7: _t->herr_subrayado(); break;
        case 8: _t->ali_centro(); break;
        case 9: _t->ali_izquierda(); break;
        case 10: _t->ali_derecha(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject NotepadWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_NotepadWindow.data,
      qt_meta_data_NotepadWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *NotepadWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NotepadWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NotepadWindow.stringdata))
        return static_cast<void*>(const_cast< NotepadWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int NotepadWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
