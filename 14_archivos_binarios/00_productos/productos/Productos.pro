TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        gestor.cpp \
        main.cpp \
        noperecedero.cpp \
        perecedero.cpp \
        producto.cpp

HEADERS += \
    gestor.h \
    noperecedero.h \
    perecedero.h \
    producto.h

DISTFILES += \
    leer.txt
