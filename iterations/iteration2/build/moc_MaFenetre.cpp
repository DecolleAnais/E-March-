/****************************************************************************
** Meta object code from reading C++ file 'MaFenetre.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../EMarche/MaFenetre.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MaFenetre.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MaFenetre_t {
    QByteArrayData data[10];
    char stringdata[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MaFenetre_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MaFenetre_t qt_meta_stringdata_MaFenetre = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 23),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 21),
QT_MOC_LITERAL(4, 57, 1),
QT_MOC_LITERAL(5, 59, 19),
QT_MOC_LITERAL(6, 79, 10),
QT_MOC_LITERAL(7, 90, 7),
QT_MOC_LITERAL(8, 98, 12),
QT_MOC_LITERAL(9, 111, 9)
    },
    "MaFenetre\0signalRechercheProduits\0\0"
    "std::vector<Produit*>\0v\0afficherResProduits\0"
    "rechercher\0accueil\0ajouterVente\0"
    "connexion\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MaFenetre[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       5,    1,   47,    2, 0x0a,
       6,    0,   50,    2, 0x0a,
       7,    0,   51,    2, 0x0a,
       8,    0,   52,    2, 0x0a,
       9,    0,   53,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MaFenetre::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MaFenetre *_t = static_cast<MaFenetre *>(_o);
        switch (_id) {
        case 0: _t->signalRechercheProduits((*reinterpret_cast< std::vector<Produit*>(*)>(_a[1]))); break;
        case 1: _t->afficherResProduits((*reinterpret_cast< std::vector<Produit*>(*)>(_a[1]))); break;
        case 2: _t->rechercher(); break;
        case 3: _t->accueil(); break;
        case 4: _t->ajouterVente(); break;
        case 5: _t->connexion(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MaFenetre::*_t)(std::vector<Produit*> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MaFenetre::signalRechercheProduits)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject MaFenetre::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MaFenetre.data,
      qt_meta_data_MaFenetre,  qt_static_metacall, 0, 0}
};


const QMetaObject *MaFenetre::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MaFenetre::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaFenetre.stringdata))
        return static_cast<void*>(const_cast< MaFenetre*>(this));
    if (!strcmp(_clname, "Vue"))
        return static_cast< Vue*>(const_cast< MaFenetre*>(this));
    return QWidget::qt_metacast(_clname);
}

int MaFenetre::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void MaFenetre::signalRechercheProduits(std::vector<Produit*> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
