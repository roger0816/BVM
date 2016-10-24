#include "Common.h"



Common::Common(QObject *parent) : QObject(parent)
{



}

QList<QStringList> Common::toStlist(QList<QVariantList> list)
{
    QList<QStringList> listRe;

    foreach(QVariantList tmp,list)
    {
        QStringList listIn;
        for(int i=0;i<tmp.length();i++)
        {
            listIn.append(tmp.at(i).toString());
        }
        listRe.append(listIn);
    }

    return listRe;

}




//void _CONFIG::loadingClientConfig()
//{
//    QSettings *configIniRead = new QSettings(QDir::currentPath()+"/../G48.ini", QSettings::IniFormat);

//    configIniRead->beginGroup("Client");

//    client.sVersion=configIniRead->value("Version").toString();

//    client.sTcpIp=configIniRead->value("IP","").toString();

//    client.sTcpPort=configIniRead->value("Port","").toString();

//    configIniRead->deleteLater();

//}




