TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        calendario.cpp \
        main.cpp \
        tarea.cpp \
        tareaarchivo.cpp \
        tareanormal.cpp \
        tarearepetitiva.cpp

HEADERS += \
    calendario.h \
    tarea.h \
    tareaarchivo.h \
    tareanormal.h \
    tarearepetitiva.h
