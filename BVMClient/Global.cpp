#include "Global.h"

Global *Global::m_pInstance = 0;



void Global::loadConfig()
{

    QString sFile=QDir::currentPath()+"/Client.ini";

    QString sBeginGroup="Client";

    QMap<QString ,QString * > data;

    data.insert("Version",&m_config.sVer);

    data.insert("IP",&m_config.sIp);

    data.insert("Port",&m_config.sPort);

    data.insert("Row",&m_config.m_sRow);

    data.insert("Column",&m_config.m_sCol);

    Lib().utility.loadConfig(sFile,sBeginGroup,data);

}

void Global::changeStage(Stage::index index)
{
    emit siganlStage(index);
}

Global::Global()
{
    m_iStayMsec=6000;
}

