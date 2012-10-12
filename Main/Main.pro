#-------------------------------------------------
#
# Project created by QtCreator 2012-10-08T15:05:40
#
#-------------------------------------------------

QT       += core gui

TARGET = SBP
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    settingsdialog.cpp \
    blinksequence.cpp \
    blink.cpp

HEADERS  += mainwindow.h \
    plugininterface.h \
    settingsdialog.h \
    blinksequence.h \
    blink.h

FORMS    += mainwindow.ui \
    settingsdialog.ui

RESOURCES += \
    images.qrc
