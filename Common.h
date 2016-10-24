#ifndef COMMON_H
#define COMMON_H

#include <QObject>
#include <QVariantList>
#include <QStringList>
#include <QMap>
#include <QList>
#include <QDebug>
#include <QSettings>
#include <QDir>
#define FILE_NAME "G48.ini"

#define     ACTION_CONNECT "3001"
# define     ACTION_DISCONNECT "3002"

#define     ACTION_GET_ORDER "3003"
#define     ACTION_GET_HISTORY "3004"

#define COMMAND_UPDATE_ORDER "4001"
#define COMMAND_UPDATE_HISTORY "4002"

#define ACTION_GET_TOTAL_ASSETS "3005"

namespace _DbTable
{
class Orders
{

};
}



class Common : public QObject
{
    Q_OBJECT
public:
    explicit Common(QObject *parent = 0);

    QList<QStringList> toStlist(QList<QVariantList> list);





signals:

public slots:
};

#endif // COMMON_H
