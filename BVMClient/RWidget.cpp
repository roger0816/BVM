#include "RWidget.h"


RWidget::RWidget(QWidget *parent) :
    QGraphicsView(parent)

{
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

   this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


}

RWidget::~RWidget()
{

}

QGraphicsProxyWidget &RWidget::rotateZ(QWidget *wTarget, int iRange, int iTime)
{
    QRect tmpRect=wTarget->rect();
    wTarget->setParent(0);

    form = scene.addWidget(wTarget);

    setScene(&scene);

    show();

    form->setGeometry(rect());

    QRectF r = form->boundingRect();

    if(iRange==-1)
    {
        for(int i=1;i<=360;i++)
        {
            form->setTransform(QTransform()
                               .translate(r.width() / 2, r.height() / 2)
                               .rotate(i - 360 * 1, Qt::YAxis)
                               .translate(-r.width() / 2, -r.height() / 2));
            sleep(iTime);
            update();
        }
    }
    else
    {
        form->setTransform(QTransform()
                           .translate(r.width() / 2, r.height() / 2)
                           .rotate(iRange - 360 * 1, Qt::YAxis)
                           .translate(-r.width() / 2, -r.height() / 2));
        sleep(iTime);
        update();
    }

    return *form;
}

void RWidget::sleep(unsigned int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 10);
}

