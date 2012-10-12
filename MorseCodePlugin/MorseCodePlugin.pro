TEMPLATE        = lib
CONFIG         += plugin
INCLUDEPATH    += ../Main
TARGET          = $$qtLibraryTarget(morsecodeplugin)
DESTDIR         = ../plugins

HEADERS += \
    morsecodeplugin.h \
    ../Main/blinksequence.h \
    ../Main/blink.h \
    stringtoblinksequence.h

SOURCES += \
    morsecodeplugin.cpp \
    ../Main/blinksequence.cpp \
    ../Main/blink.cpp \
    stringtoblinksequence.cpp
