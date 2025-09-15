TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        gestor.cpp \
        main.cpp \
        vino.cpp \
        vinoespecial.cpp \
        vinomesa.cpp \
        vinopremium.cpp

HEADERS += \
    gestor.h \
    vino.h \
    vinoespecial.h \
    vinomesa.h \
    vinopremium.h
