#ifndef UTILITY_H
#define UTILITY_H

#include <QObject>
#include <QMap>
#include <QStringList>
struct CData
{
    QString sAction;
    QString sType;
    QStringList listData;
    QList<QStringList> dData;
};



class Utility :public QObject
{
    Q_OBJECT
public:
    Utility(QObject *parent = 0);
    ~Utility();

    QByteArray encode(CData data);

    CData decode(QByteArray arrData);

    void creatConfig(QString sFile, QString sBeginGroup, QMap<QString, QString *> &data);

    bool loadConfig(QString sFile, QString sBeginGroup, QMap<QString, QString *> &data,bool bIsNoneAutoCreat=true);

    int checkLogin(QString sUser,QString sPassWord);
};

#endif // UTILITY_H
