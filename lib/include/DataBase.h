#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QMap>
#include <QVariantList>
#include <QVariant>

namespace _db
{
enum _db_type
{
    _mysql=0,
    _sql_lite
};
}

using namespace _db;

class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = 0);


        /**
         * @brief dbOpen
         * @param sDbName
         * @param sIp
         * @param sPort
         * @param sUser
         * @param sPassword
         * @return
         */
        bool openDb(QString sDbName, QString sUser, QString sPassword,QString sIp, QString sPort="3306",_db_type type=_mysql);

        void closeDb();

        /**
         * @brief getCurrentDb
         * @return
         */

        QSqlDatabase& getCurrentDb();

        QList<QVariantList> getTable(QString sTableName);

        void insertDb(QString sTableName,QMap<QString,QString> data);

signals:
    void signalLog(QString st);
public slots:
};

#endif // DATABASE_H
