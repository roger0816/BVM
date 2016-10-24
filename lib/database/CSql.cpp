#include "CSql.h"

CSql *CSql::m_pInstance = 0;


CSql::CSql(QObject *parent):QThread(parent)
{

}


bool CSql::openDb(QString sDbName,  QString sUser, QString sPassword,QString sIp, QString sPort,QString sSqldriver)
{
    bool bRe=false;
        
    m_db = QSqlDatabase::addDatabase(sSqldriver,sDbName);

    m_db.setDatabaseName(sDbName);

    m_db.setPort(sPort.toInt());

    m_db.setHostName(sIp);

    m_db.setUserName(sUser);

    m_db.setPassword(sPassword);

    emit signalLog("db name: "+sDbName);

    emit signalLog("db host name: "+sIp);

    emit signalLog("db port: "+sPort);

    emit signalLog("db User name: "+sUser);

    bRe=m_db.open();
    
    if(!bRe)
    {
        emit signalLog("ERROR: "+QSqlError(m_db.lastError()).text());
    }
    else
    {
        emit signalLog("sql open Ok");
    }

    return bRe;
}

QList<QVariantList> CSql::getTable(QString sTableName)
{
    QList<QVariantList> dRe;

        QSqlQuery query(m_db);

        QString dbCmd="SELECT  * FROM  "+sTableName;

        query.exec(dbCmd);
        int iRow=0;
            while(query.next())
            {
                QVariantList list;
              //  qDebug()<<" row : "<<iRow<<"  ,  column count: "<<query.record().count();
                for(int i=0;i<query.record().count();i++)
                {
                  list.append(query.value(i));
                }
                dRe.append(list);
                    iRow++;
            }

            return dRe;
}

int CSql::insertDb(QString sTableName, QMap<QString, QString> list)
{
    int iRe=-1;
  //  insert into 資料表名稱(欄位1,欄位2,欄位3,欄位4, ...... 欄位N)
  //  values('值1','值2','值3','值4', ...... '值N');
   // INSERT INTO table1 ( id , name , pwd ) VALUES ( '9', 'Jacky', '54545' );

      QSqlQuery query(m_db);

      QString sColName;

      QString sValues;


      for(int i=0;i<list.count();i++)
      {
          if(i!=0)
          {
              sColName+=",";
              sValues+=",";
          }

          sColName+=list.keys().at(i);
          sValues+="'";
          sValues+=list.values().at(i);
          sValues+="'";

      }

      QString sCmd="INSERT INTO "+sTableName+"(" +sColName+") VALUES ("+sValues +")";

      bool bExe=query.exec(sCmd);

      if(bExe)
          iRe=0;

      return iRe;
}
