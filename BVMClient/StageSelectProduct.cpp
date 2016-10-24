#include "StageSelectProduct.h"
#include "ui_StageSelectProduct.h"

StageSelectProduct::StageSelectProduct(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StageSelectProduct)
{
    ui->setupUi(this);

    ui->wBg->setStyleSheet("QWidget#wBg{border-image:url(res/Background/bk-02.png);}");
    //ui->wBg->setStyleSheet("border-image:url(res/Background/bk-02.png);");
    //new元件效能代價大，所以只有程式啟動時new，而不在切頁時new ，防止切頁緩慢

    ui->widget_2->setStyleSheet("QWidget#widget_2{border-image:url(res/P03/F01.png)}");

    m_iMsec=-1;

    QDir d;
    if (!d.exists("res/product"));
    d.mkdir("res/product");

    for(int i=0;i<64;i++)
    {

        ItemBtnProduct *btn=new ItemBtnProduct(ui->wBtnGroup,i);

        btn->connect(btn,SIGNAL(clicked()),this,SLOT(clicked()));

        btn->hide();

        m_listBtn.append(btn);



        QString sIdx=QString::number(i);
        if(i<=9)
            sIdx.push_front("0");
        QString sProductDir="P"+sIdx;

        if (!d.exists("res/product/"+sProductDir));
        d.mkdir("res/product/"+sProductDir);


    }


    QObject::startTimer(TIME_EVENT_MSEC);
}

StageSelectProduct::~StageSelectProduct()
{
    delete ui;
}

void StageSelectProduct::ini()
{
    foreach (ItemBtnProduct*btn, m_listBtn)
    {
        btn->setSelect(false);
    }

}

void StageSelectProduct::showEvent(QShowEvent *)
{

    btnLayout(4,3);
    loadProductList();
    m_iMsec=0;


}

void StageSelectProduct::resizeEvent(QResizeEvent *)
{
    qDebug()<<"resize ";


}

void StageSelectProduct::mousePressEvent(QMouseEvent *event)
{
    m_iMsec=0;
}

void StageSelectProduct::timerEvent(QTimerEvent *)
{
    if(m_iMsec<0)
        return;

    m_iMsec+=TIME_EVENT_MSEC;

    if(m_iMsec>=GLOBAL().m_iStayMsec)
    {
        m_iMsec=-1;
        GLOBAL().changeStage(Stage::_start);
    }
}

void StageSelectProduct::loadProductList()
{
    for(int i=0;i<m_listBtn.length();i++)
    {
        if(m_listBtn.at(i)->isVisible())
        {
            qDebug()<<" I : "<<i;
            QString sIdx=QString::number(i);
            if(i<=9)
                sIdx.push_front("0");
            QString sProductDir="res/product/P"+sIdx;


            QMap<QString,QString*> map;

            map.insert("pid",&m_listBtn[i]->m_data.sPid);
            map.insert("name",&m_listBtn[i]->m_data.sName);
            map.insert("price",&m_listBtn[i]->m_data.sPrice);

            Lib().utility.loadConfig(sProductDir+"/data","data",map);

            m_listBtn[i]->m_data.sImageSpath=sProductDir+"/s.png";

            m_listBtn[i]->m_data.sImageDpath=sProductDir+"/d0.png";

            m_listBtn[i]->updateProduct();
        }

    }

}

void StageSelectProduct::btnLayout(int iCol, int iRow)
{

    if(iCol>8)
        iCol=8;

    if(iRow>8)
        iRow=8;

    QSize itemSize;
    itemSize.setHeight(40);
    itemSize.setWidth(40);

    int iHborder=10;

    int iBorder=10;
    int iMargin=9;

    itemSize.setWidth((ui->wBtnGroup->width()-(iCol-1)*iBorder-iMargin*2)/iCol);
    itemSize.setHeight(itemSize.width()*1.4);

    int iVborder=10;

    iVborder=(ui->wBtnGroup->height()-iMargin*4-(itemSize.height()*iRow))/iRow;


    int k=0;

    for(int x=0;x<m_listBtn.length();x++)
    {
        //m_listBtn[x]->setHidden(x>=iCol*iRow);

        m_listBtn[x]->setHidden(true);
    }


    for(int i=0;i<iRow;i++)
    {
        for(int j=0;j<iCol;j++)
        {
            m_listBtn[k]->setHidden(false);
            m_listBtn[k]->resize(itemSize);
            m_listBtn[k]->move(j*(itemSize.width()+iHborder)+iMargin,i*(itemSize.height()+iVborder)+iMargin*2);

            k++;
        }
    }


}


void StageSelectProduct::clicked()
{
    m_iMsec=0;
    ini();
    ItemBtnProduct *item=dynamic_cast<ItemBtnProduct*>(QObject::sender());

    item->setSelect(true);

    ui->lbName->setText(item->m_data.sName);

    ui->lbPrice->setText(item->m_data.sPrice);

    ui->wImage->setStyleSheet("border-image:url("+item->m_data.sImageDpath+")");


}


