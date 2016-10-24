#ifndef RWIDGET_H
#define RWIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsWidget>
#include <QGraphicsProxyWidget>
#include <QCoreApplication>
#include <QTime>
#include <QTextEdit>
#include <QPushButton>
#include <QGraphicsLinearLayout>


class RWidget : public QGraphicsView
{
    Q_OBJECT

public:
    explicit RWidget(QWidget *parent = 0);
    ~RWidget();

    QGraphicsProxyWidget& rotateZ(QWidget *wTarget,int iRange=-1,int iTime=10);

    void sleep(unsigned int msec);

    QGraphicsScene scene;

private:
    QGraphicsProxyWidget *form;

};

#endif // RWIDGET_H
