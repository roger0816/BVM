#-------------------------------------------------
#
# Project created by QtCreator 2016-08-15T17:47:13
#
#-------------------------------------------------

#QT       += widgets

QT       -= gui

TARGET = ATeam
TEMPLATE = lib
CONFIG += staticlib

DESTDIR = $$PWD
OBJECTS_DIR = $$PWD/obj
MOC_DIR = $$PWD/obj
UI_DIR = $$PWD/obj/ui_header

include(include/Lib.pri)


INCLUDEPATH +=$$PWD/../include/ \
              $$PWD/../network/ \
              $$PWD/../database/ \
              $$PWD/../ipc/ \
              $$PWD/../utility/ \

SOURCES += \
    network/CTcpClient.cpp \
    network/CTcpServer.cpp \
    network/Network.cpp \
    database/DataBase.cpp \
    database/CSql.cpp \
    ipc/Ipc.cpp \
    ipc/CLocalServer.cpp \
    ipc/CLocalClient.cpp \
    utility/Utility.cpp \
    Libraya.cpp




unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \

HEADERS += \
    database/CSql.h \
    network/CTcpClient.h \
    network/CTcpServer.h \
    ipc/CLocalServer.h \
    ipc/CLocalClient.h \








