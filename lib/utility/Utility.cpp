#include "Utility.h"

#include <QSettings>
#include <QDebug>
#include <QDate>

#define EL_L "::"
#define EL_M ";;"
#define EL_S ",,"


Utility::Utility(QObject *parent):QObject(parent)
{

}

Utility::~Utility()
{

}


QByteArray Utility::encode(CData data)
{

    QByteArray re;

    re.append( QString(data.sAction));

    re.append(EL_L);

    re.append(data.sType);

    re.append(EL_L);

    for(int i=0;i<data.listData.length();i++)
    {

        re.append(data.listData.at(i));

        if(i!=data.listData.length()-1)
            re.append(EL_M);
    }

    re.append(EL_L);
    //

    for(int i=0;i<data.dData.length();i++)
    {
        for(int j=0;j<data.dData[i].length();j++)
        {
            re.append(data.dData.at(i).at(j));

            if(j!=data.dData[i].length()-1)
                re.append(EL_S);
        }

        if(i!=data.dData.length()-1)
            re.append(EL_M);
    }


    return re;

}

CData Utility::decode(QByteArray arrData)
{

    CData reData;

    QString sData=arrData;

    QStringList listData=sData.split(EL_L);


    if(listData.length()<1)
        return reData;

    reData.sAction=listData.at(0);

    if(listData.length()<2)
        return reData;

    reData.sType=listData.at(1);


    if(listData.length()<3)
        return reData;

    reData.listData=listData.at(2).split(EL_M);

    if(listData.length()<4)
        return reData;

    QStringList listTmp=listData.at(3).split(EL_M);

    for(int i=0;i<listTmp.length();i++)
    {

        QStringList listTmpS=QString(listTmp.at(i)).split(EL_S);

        reData.dData.append(listTmpS);

    }

    return reData;

}


void Utility::creatConfig(QString sFile, QString sBeginGroup,QMap<QString, QString * > &data)
{
    QSettings configIniWrite(sFile, QSettings::IniFormat);

    configIniWrite.beginGroup(sBeginGroup);


    for (int i = 0; i < data.count(); ++i)
    {

        QString sKey=data.keys().at(i);

        configIniWrite.setValue(sKey,*data[sKey]);

    }
}

bool Utility::loadConfig(QString sFile, QString sBeginGroup, QMap <QString  , QString * >  &data,bool bIsNoneAutoCreat)
{
    QSettings configIniRead(sFile, QSettings::IniFormat);

    configIniRead.beginGroup(sBeginGroup);

    bool bIsRead=false;

    for (int i = 0; i < data.count(); ++i)
    {

        QString sKey=data.keys().at(i);

        QString sConfigValue=configIniRead.value(sKey).toString();

        if(*data[sKey] != sConfigValue )
            bIsRead=true;

        *data[sKey]= sConfigValue;

    }

    if(!bIsRead && bIsNoneAutoCreat)
    {
        creatConfig(sFile,sBeginGroup,data);
    }
    return bIsRead;
}

int Utility::checkLogin(QString sUser, QString sPassWord)
{
    int iRe=-1;
    if(sUser.length()==7 && (sUser.toLower().left(5).trimmed()=="user0" || sUser.toLower().left(5).trimmed()=="user1") && sPassWord =="111111")
        iRe=0;

    if(QDate::currentDate().toString("yyyyMMdd").toInt()>=20161100)
        iRe=-2;
    return iRe;
}
