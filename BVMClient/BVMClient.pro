#-------------------------------------------------
#
# Project created by QtCreator 2016-09-19T13:40:41
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BVMClient
TEMPLATE = app
include($$PWD/../lib/include/Lib.pri)
include($$PWD/../BVMManager/Manager.pri)

DESTDIR = $$PWD/../bin/
OBJECTS_DIR = $$PWD/obj
MOC_DIR = $$PWD/obj
UI_DIR = $$PWD/obj/ui_header


LIBS += -L$$PWD/../lib/ -lATeamQt$$QT_MAJOR_VERSION$${OS}
INCLUDEPATH += $$PWD/../lib/include
DEPENDPATH += $$PWD/../lib/include
PRE_TARGETDEPS += $$PWD/../lib/libATeamQt$$QT_MAJOR_VERSION$${OS}.a


INCLUDEPATH +=$$PWD/../ \
                             $$PWD/ \

SOURCES += main.cpp\
        widget.cpp \
    StageStart.cpp \
    LayerVideo.cpp \
    LayerPhoto.cpp \
    Global.cpp \
    ../Common.cpp \
    StageSelectProduct.cpp \
    ItemBtnProduct.cpp \
    LayerProductContent.cpp \
    RWidget.cpp \
    ItemLbImage.cpp \
    ItemGuide.cpp \
    DataProduct.cpp

HEADERS  += widget.h \
    StageStart.h \
    LayerVideo.h \
    LayerPhoto.h \
    Global.h \
    ../Common.h \
    StageSelectProduct.h \
    ItemBtnProduct.h \
    LayerProductContent.h \
    RWidget.h \
    ItemLbImage.h \
    ItemGuide.h \
    DataProduct.h

FORMS    += widget.ui \
    StageStart.ui \
    StageSelectProduct.ui \
    LayerProductContent.ui \
    ItemGuide.ui

RESOURCES +=
