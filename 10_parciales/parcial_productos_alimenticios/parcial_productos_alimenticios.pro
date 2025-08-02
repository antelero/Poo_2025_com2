TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        producto.cpp \
        productocompuesto.cpp \
        productosimple.cpp \
        vectordinamico.cpp

HEADERS += \
    producto.h \
    productocompuesto.h \
    productosimple.h \
    vectordinamico.h
