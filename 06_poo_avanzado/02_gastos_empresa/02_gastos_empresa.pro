TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        gasto.cpp \
        gasto_compra.cpp \
        gasto_extraordinario.cpp \
        gasto_servicio.cpp \
        gestorgasto.cpp \
        main.cpp

HEADERS += \
    gasto.h \
    gasto_compra.h \
    gasto_extraordinario.h \
    gasto_servicio.h \
    gestorgasto.h
