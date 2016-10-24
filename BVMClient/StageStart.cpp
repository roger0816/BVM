#include "StageStart.h"
#include "ui_StageStart.h"

#include <QFile>

StageStart::StageStart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StageStart)
{
    ui->setupUi(this);



    ui->wBg->setStyleSheet(QStringLiteral("QWidget#wBg{border-image:url(res/Background/bk-01.png);}"));

    m_itemGuide=new ItemGuide(this);




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
    int iBorder=80;

    float iW=width()-iBorder*2;

    float iH=iW*1.77778;

    qDebug()<<"video W x H : "<<iW<<" x "<<iH;

    ui->stackedWidget->setMinimumSize(iW,iH);

    ui->stackedWidget->setMaximumSize(iW,iH);

    m_itemGuide->setGeometry(0,ui->stackedWidget->height()+iBorder/2,width(),height()-iH-iBorder);


}

void StageStart::changeIcon(int iIdx)
{





}

void StageStart::timerEvent(QTimerEvent *)
{
    m_iFocusIdx++;




}
