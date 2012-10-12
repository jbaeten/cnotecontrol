TEMPLATE        = lib
CONFIG         += plugin
INCLUDEPATH    += ../Main
TARGET          = $$qtLibraryTarget(gmailplugin)
DESTDIR         = ../plugins
QT += network

HEADERS += \
    gmailplugin.h \
    simplecrypt.h \
    ../Main/blinksequence.h \
    ../Main/blink.h

SOURCES += \
    gmailplugin.cpp \
    simplecrypt.cpp \
    ../Main/blinksequence.cpp \
    ../Main/blink.cpp

#INCLUDEPATH += ../kqoauth/include
#LIBS += ../kqoauth/lib/kqoauth0.lib \
#    ../kqoauth/lib/kqoauthd0.lib
