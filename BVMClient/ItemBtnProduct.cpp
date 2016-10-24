#include "ItemBtnProduct.h"
#include "ui_ItemBtnProduct.h"

ItemBtnProduct::ItemBtnProduct(QWidget *parent, int iIdx) :
    QWidget(parent),
    ui(new Ui::ItemBtnProduct)
{
    ui->setupUi(this);

    m_mIdx=iIdx;



}

ItemBtnProduct::~ItemBtnProduct()
{
    delete ui;
}

void ItemBtnProduct::mousePressEvent(QMouseEvent *)
{

}


void ItemBtnProduct::setProductName(QString sText)
{

}

void ItemBtnProduct::resizeEvent(QResizeEvent *)
{

//    ui->lbImage->setMinimumHeight(ui->lbImage->width());

//    ui->lbImage->setMaximumHeight(ui->lbImage->width());

}
