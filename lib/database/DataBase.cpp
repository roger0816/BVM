#include "DataBase.h"
#include "CSql.h"

CSql *sql=0;

DataBase::DataBase(QObject *parent) : QObject(parent)
{
    sql=new CSql(this);
    sql->connect(sql,SIGNAL(signalLog(QString)),this,SIGNAL(signalLog(QString)));
}

bool DataBase::openDb(QString sDbName, QString sUser, QString sPassword,QString sIp, QString sPort,_db_type type)
{
    QString sSqldrive="QSQLITE";

    if(type==_mysql)
        sSqldrive="QMYSQL";



    return sql->openDb(sDbName,sUser,sPassword,sIp,sPort,sSqldrive);
}



void DataBase::closeDb()
{
    sql->closeDB();
}


QSqlDatabase &DataBase::getCurrentDb()
{
    return sql->m_db;
}

QList<QVariantList> DataBase::getTable(QString sTableName)
{
    QList<QVariantList> dRe;
    dRe=sql->getTable(sTableName);
    return dRe;
}

void DataBase::insertDb(QString sTableName, QMap<QString, QString> data)
{
    sql->insertDb(sTableName,data);
}
