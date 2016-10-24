
QT       += network sql testlib

win32{
OS=Win

}
unix:!macx{

#linux-arm-gnueabi {
#    //ARM stuff here
#}

OS=Linux
}
mac:!macx{
OS=Ios
}
macx{
QMAKE_MAC_SDK = macosx10.12
OS=Osx
}
android{
OS=Android
}

TARGET = $${TARGET}Qt$$QT_MAJOR_VERSION$${OS}


INCLUDEPATH+= \
            $$PWD \


HEADERS += \
    $$PWD/Network.h \
    $$PWD/DataBase.h \
    $$PWD/Ipc.h \
    $$PWD/Utility.h \
    $$PWD/Library.h



