#include "StageStart.h"
#include "ui_StageStart.h"

#include <QFile>

StageStart::StageStart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StageStart)
{
    ui->setupUi(this);

    ui->wBg->setStyleSheet("QWidget#wBg{border-image:url(res/Background/bk-01.png);}");

    ui->wLogo->setStyleSheet("border-image:url(res/logo00.png);");




    m_iFocusIdx=0;

    QObject::startTimer(5000);



}

StageStart::~StageStart()
{
    delete ui;
}


//void StageStart::mousePressEvent(QMouseEvent *)
//{

//    GLOBAL().changeStage(Stage::_selectProduct);

//   // hide();

//}

void StageStart::resizeEvent(QResizeEvent *)
{
    int iBorder=10;

    float iW=width()-iBorder*2;

    float iH=iW*1.77778;

    qDebug()<<"video W x H : "<<iW<<" x "<<iH;


    ui->stackedWidget->setMinimumSize(iW,iH);

    ui->stackedWidget->setMaximumSize(iW,iH);




}

void StageStart::changeIcon(int iIdx)
{





}

void StageStart::timerEvent(QTimerEvent *)
{
    m_iFocusIdx++;




}
