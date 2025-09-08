TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        alumno.cpp \
        alumnoespecial.cpp \
        alumnolibre.cpp \
        alumnonormal.cpp \
        alumnovocacional.cpp \
        curso.cpp \
        main.cpp

HEADERS += \
    alumno.h \
    alumnoespecial.h \
    alumnolibre.h \
    alumnonormal.h \
    alumnovocacional.h \
    curso.h
