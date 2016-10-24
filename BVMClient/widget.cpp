#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_iPressTime=-1;

    m_iBtnShowTime=0;

    m_iClick=0;

    m_iStageIdx=Stage::_start;

    connect(&GLOBAL(),SIGNAL(siganlStage(Stage::index)),this,SLOT(stageFilter(Stage::index)));


    m_stageSelect=new StageSelectProduct(ui->wBg);

    m_stageSelect->hide();

    m_stageManager=new StageManager(ui->wBg);

    m_stageManager->hide();

    m_stageStart=new StageStart(ui->wBg);

    ui->btnManager->raise();

    QObject::startTimer(TIME_ADD);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::resizeEvent(QResizeEvent *)
{

  //  m_wBg->setGeometry(rect());

    m_stageStart->setGeometry(rect());

    m_stageSelect->setGeometry(rect());

    m_stageManager->setGeometry(rect());

    ui->btnManager->move(width()-ui->btnManager->width(),height()-ui->btnManager->height());

    ui->btnManager->hide();


    //resize(1440,768);
   // m_wBg ->resize(500,500);
//    QRectF r = form->boundingRect();
//    for(int i=1;i<=180;i++)
//    {
//       form->setTransform(QTransform()
//                           .translate(r.width() / 2, r.height() / 2)
//                           .rotate(i - 360 * 1, Qt::YAxis)
//                           .translate(-r.width() / 2, -r.height() / 2));
//        sleep(20);
//        this->update();
//    }




}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->pos().x()<=TOUCH_RANGE && event->pos().y()>= height()-TOUCH_RANGE)
        m_iPressTime=0;
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->pos().x()>= width()-TOUCH_RANGE && event->pos().y() >= height()-TOUCH_RANGE && m_iPressTime>5000)
    {
        ui->btnManager->show();
    }
    else
    {
        if(m_iStageIdx==Stage::_start)
            stageFilter(Stage::_selectProduct);
    }
    m_iPressTime=-1;
}

void Widget::timerEvent(QTimerEvent *)
{
    if(m_iPressTime!=-1)
    {
        m_iPressTime+=TIME_ADD;
    }

    if(!ui->btnManager->isHidden())
    {
        m_iBtnShowTime+=TIME_ADD;

        if(m_iBtnShowTime>BTN_SHOW_TIME)
        {
            ui->btnManager->hide();
            m_iBtnShowTime=0;
        }
    }
    else
    {
        m_iBtnShowTime=0;
    }

}

void Widget::stageFilter(Stage::index iIdx)
{
    m_stageStart->hide();
    m_stageManager->hide();
    m_stageSelect->hide();

    if(iIdx==Stage::_start)
    {
        qDebug()<<"change to stage::start";
        m_stageStart->show();
        m_iStageIdx=Stage::_start;
    }

    else if(iIdx==Stage::_manager)
    {
        qDebug()<<"change to stage::manager";
        m_stageManager->show();
        m_iStageIdx=Stage::_manager;
    }

    else// if(iIdx==Stage::_selectProduct)
    {
        qDebug()<<"change to stage::select";
        m_stageSelect->show();
        m_iStageIdx=Stage::_selectProduct;
    }


}

void Widget::on_btnManager_clicked()
{
    if(m_iClick>=5)
    {
        m_iClick=0;
        ui->btnManager->hide();
        m_iBtnShowTime=0;
        stageFilter(Stage::_manager);
    }
}

void Widget::on_btnManager_pressed()
{
    m_iClick++;
}

void Widget::sleep(unsigned int msec)
{
        QTime dieTime = QTime::currentTime().addMSecs(msec);
        while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
