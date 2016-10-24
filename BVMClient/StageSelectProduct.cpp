#include "StageSelectProduct.h"
#include "ui_StageSelectProduct.h"

StageSelectProduct::StageSelectProduct(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StageSelectProduct)
{
    ui->setupUi(this);


    //new元件效能代價大，所以只有程式啟動時new，而不在切頁時new ，防止切頁緩慢

    for(int i=0;i<100;i++)
    {

        ItemBtnProduct *btn=new ItemBtnProduct(ui->wBtnGroup,0);

        btn->hide();

        m_listBtn.append(btn);

    }


}

StageSelectProduct::~StageSelectProduct()
{
    delete ui;
}

void StageSelectProduct::showEvent(QShowEvent *)
{



//    if(layout!=NULL)
//    layout->deleteLater();

//    layout=new QGridLayout;


//    QStringList list;

//    list<<"product 1"<<"product 2"<<"product 3"<<"product 4"<<"product 5"<<"product 6"<<"product 7"<<
//          "product 8"<<"product 9"<<"product 10"<<"product 11"<<"product 12"<<"product 13";

//    int iRow=qBound(0,GLOBAL().m_iRow,100);
//    int iCol=qBound(0,GLOBAL().m_iCol,100);

//    int iIdx=0;
//    ItemBtnProduct *btn;
//    for(int i=0;i<iRow;i++)
//    {
//        for(int j=0;j<iCol;j++)
//        {
//            if(iIdx>=m_listBtn.length())
//            {
//                btn=new ItemBtnProduct(this,iIdx);
//                m_listBtn.append(btn);
//            }
//            else
//            {
//                btn=m_listBtn.at(iIdx);
//            }

//            layout->addWidget(btn,i,j);

//            if(iIdx<list.length())
//            {
//                btn->setProductName(list.at(iIdx));
//            }

//            iIdx++;
//        }
//    }


    //    ui->wBtnGroup->setLayout(layout);
}

void StageSelectProduct::btnLayout(int iCol, int iRow)
{
    QSize itemSize;
    itemSize.setHeight(200);
    itemSize.setWidth(150);

    int iHborder=40;

    int iMargin=40;

   iHborder= (ui->wBtnGroup->width()-iCol*itemSize.width()-iMargin*2)/(iCol-1);


 //   for(int i=0)
}

void StageSelectProduct::on_pushButton_clicked()
{

}
