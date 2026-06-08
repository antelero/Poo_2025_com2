TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        alumno.cpp \
        curso.cpp \
        main.cpp \
        suscripcion.cpp \
        suscripcioninvitado.cpp \
        suscripcionmedio.cpp \
        suscripcionpremium.cpp

HEADERS += \
    alumno.h \
    curso.h \
    suscripcion.h \
    suscripcioninvitado.h \
    suscripcionmedio.h \
    suscripcionpremium.h
