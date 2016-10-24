#-------------------------------------------------
#
# Project created by QtCreator 2016-09-22T15:03:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BVMManager
TEMPLATE = app

include($$PWD/Manager.pri)

DESTDIR = $$PWD/../bin/
OBJECTS_DIR = $$PWD/obj
MOC_DIR = $$PWD/obj
UI_DIR = $$PWD/obj/ui_header

INCLUDEPATH +=$$PWD/../ \
                             $$PWD/ \
                             $$PWD/../BVMClient/

SOURCES += main.cpp\
        widget.cpp \
    ../BVMClient/Global.cpp

HEADERS  += widget.h \
    ../BVMClient/Global.h

FORMS    += widget.ui


