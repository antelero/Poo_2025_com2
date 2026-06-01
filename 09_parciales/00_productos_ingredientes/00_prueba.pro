TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        caja.cpp \
        gestor.cpp \
        ingrediente.cpp \
        main.cpp \
        producto.cpp \
        productocompuesto.cpp \
        productosimple.cpp \
        vector.cpp

HEADERS += \
    caja.h \
    gestor.h \
    ingrediente.h \
    producto.h \
    productocompuesto.h \
    productosimple.h \
    vector.h
