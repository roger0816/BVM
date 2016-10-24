#include "ItemBtnProduct.h"

ItemBtnProduct::ItemBtnProduct(QWidget *parent, int iIdx) :
    QWidget(parent)
{
  //  ui->setupUi(this);

    m_mIdx=iIdx;

    m_bIsSelect=false;

    m_wBg=new QWidget(this);

    m_wBg->setStyleSheet("background-color:rgb(25,35,61,0)");

    m_lbCost=new QLabel(m_wBg);

    m_lbCost->setAlignment(Qt::AlignCenter);

    QFont font;

    font.setPixelSize(42);

    m_lbCost->setFont(font);


    m_wMask2=new QWidget(m_wBg);

    m_lbImage=new QLabel(m_wBg);

    m_lbImage->setStyleSheet("border-image:url(res/)");

    m_wMask=new QWidget(m_lbImage);

    m_wMask->setStyleSheet("border-image:url(res/P03/F01.png)");



}

ItemBtnProduct::~ItemBtnProduct()
{

}

void ItemBtnProduct::mousePressEvent(QMouseEvent *)
{
    emit clicked();
}


void ItemBtnProduct::setProductName(QString sText)
{

}

void ItemBtnProduct::resizeEvent(QResizeEvent *)
{

    m_wBg->resize(size());

    m_lbImage->setGeometry(0,0,width(),width());

    m_wMask2->setGeometry(m_lbImage->rect());

    m_wMask->setGeometry(0,0,m_lbImage->width(),m_lbImage->height());

    m_lbCost->setGeometry(0,m_lbImage->height(),width(),height()-m_lbImage->height());


}

void ItemBtnProduct::setSelect(bool bIsSelect)
{
    QString sAlpha="0";

    if(bIsSelect)
        sAlpha="255";
    m_wMask2->setStyleSheet("background-color:rgb(255,255,255,"+sAlpha+")");

    m_bIsSelect=bIsSelect;


}

void ItemBtnProduct::updateProduct()
{

    m_lbImage->setStyleSheet("border-image:url("+m_data.sImageSpath+")");
       qDebug()<<"GGE : "<<m_data.sPrice;
    m_lbCost->setText("$ "+m_data.sPrice);
}
