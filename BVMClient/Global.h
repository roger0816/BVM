#ifndef GLOBAL_H
#define GLOBAL_H

#include <QObject>
#include <QDebug>
#include <QDate>
#include "Common.h"

#include "Library.h"

#include <QDir>

//外部要呼叫統一使用define的，design patten : singleton 
#define GLOBAL Global::Instance

#define CONFIG Global::Instance().m_config

#define COMMON Global::Instance().g_common

#if Q_WS_MACX


#else

#endif

#define RES "../res/"
namespace Stage
{
enum index
{
    _start=0,
    _selectProduct,
    _manager,
};
}

struct config
{
    QString sVer;

    QString sIp;

    QString sPort;

    QString m_sCol="3";

    QString m_sRow="2";
};


class Global : public QObject
{
     Q_OBJECT
public:

    static Global& Instance()
    {
        if(m_pInstance==0)
            m_pInstance=new Global();
        return *m_pInstance;
    }

     Common g_common;

    config m_config;

    void loadConfig();








public slots:
    void changeStage(Stage::index index);
signals:
    void siganlStage(Stage::index index);
private:
    Global();
    static Global* m_pInstance;
};

#endif // GLOBAL_H
