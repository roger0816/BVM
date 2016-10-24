#include "ItemGuide.h"
#include "ui_ItemGuide.h"

#include <QResizeEvent>

ItemGuide::ItemGuide(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemGuide)
{
    ui->setupUi(this);



    m_iAction=0;
    CImagePath path0;
    path0.sTopDisable="border-image:url(res/P01/a01.png);";
    path0.sBottomDisable="border-image:url(res/P01/x01.png);";
    path0.sTopEnable="border-image:url(res/P01/a02.png);";
    path0.sBottomEnable="border-image:url(res/P01/x04.png);";

    CImagePath path1;
    path1.sTopDisable="border-image:url(res/P01/a01.png);";
    path1.sBottomDisable="border-image:url(res/P01/x02.png);";
    path1.sTopEnable="border-image:url(res/P01/b01.png);";
    path1.sBottomEnable="border-image:url(res/P01/x08.png);";

    CImagePath path2;
    path2.sTopDisable="border-image:url(res/P01/a01.png);";
    path2.sBottomDisable="border-image:url(res/P01/x03.png);";
    path2.sTopEnable="border-image:url(res/P01/b02.png);";
    path2.sBottomEnable="border-image:url(res/P01/x12.png);";

    m_listImage.append(path0);
    m_listImage.append(path1);
    m_listImage.append(path2);

    ini();

    QObject::startTimer(1000);

}

ItemGuide::~ItemGuide()
{
    delete ui;
}

void ItemGuide::ini()
{
    ui->w0_0->setStyleSheet(m_listImage.at(0).sTopDisable);
    ui->w0_1->setStyleSheet(m_listImage.at(0).sBottomDisable);

    ui->w1_0->setStyleSheet(m_listImage.at(1).sTopDisable);
    ui->w1_1->setStyleSheet(m_listImage.at(1).sBottomDisable);

    ui->w2_0->setStyleSheet(m_listImage.at(2).sTopDisable);
    ui->w2_1->setStyleSheet(m_listImage.at(2).sBottomDisable);

}

void ItemGuide::nextAction()
{

    switch (m_iAction)
    {
    case 1:
        ui->w0_0->setStyleSheet(m_listImage.at(0).sTopEnable);
        ui->w0_1->setStyleSheet(m_listImage.at(0).sBottomEnable);

        ui->w1_0->setStyleSheet(m_listImage.at(1).sTopDisable);
        ui->w1_1->setStyleSheet(m_listImage.at(1).sBottomDisable);

        ui->w2_0->setStyleSheet(m_listImage.at(2).sTopDisable);
        ui->w2_1->setStyleSheet(m_listImage.at(2).sBottomDisable);

        break;

    case 2:
        ui->w0_0->setStyleSheet(m_listImage.at(0).sTopEnable);
        ui->w0_1->setStyleSheet(m_listImage.at(0).sBottomEnable);

        ui->w1_0->setStyleSheet(m_listImage.at(1).sTopEnable);
        ui->w1_1->setStyleSheet(m_listImage.at(1).sBottomEnable);

        ui->w2_0->setStyleSheet(m_listImage.at(2).sTopDisable);
        ui->w2_1->setStyleSheet(m_listImage.at(2).sBottomDisable);

        break;


    case 3:
        ui->w0_0->setStyleSheet(m_listImage.at(0).sTopEnable);
        ui->w0_1->setStyleSheet(m_listImage.at(0).sBottomEnable);

        ui->w1_0->setStyleSheet(m_listImage.at(1).sTopEnable);
        ui->w1_1->setStyleSheet(m_listImage.at(1).sBottomEnable);

        ui->w2_0->setStyleSheet(m_listImage.at(2).sTopEnable);
        ui->w2_1->setStyleSheet(m_listImage.at(2).sBottomEnable);
        break;

    case 0:
    default:
        ini();
        break;
    }

    m_iAction++;

    if(m_iAction>3)
        m_iAction=0;
}

void ItemGuide::resizeEvent(QResizeEvent *)
{



}

void ItemGuide::timerEvent(QTimerEvent *)
{
    nextAction();
}
