#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "StageStart.h"
#include "StageSelectProduct.h"
#include "StageManager.h"
#include <QResizeEvent>
#include <QMouseEvent>
#include <QTimerEvent>
#include <QPainter>
#include "Global.h"

#include <QThread>
namespace Ui {
class Widget;
}

#define TIME_ADD 100

#define TOUCH_RANGE 90

#define BTN_SHOW_TIME 3000

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    int m_iPressTime;

    int m_iBtnShowTime;

    int m_iClick;

    int m_iStageIdx;

    StageStart *m_stageStart;

    StageSelectProduct *m_stageSelect;

    StageManager *m_stageManager;

    void resizeEvent(QResizeEvent *);

    void mousePressEvent(QMouseEvent *event);

    void mouseReleaseEvent(QMouseEvent *event);

    void timerEvent(QTimerEvent *);

    void sleep(unsigned int msec);
public slots:

    void stageFilter(Stage::index iIdx);

private slots:

    void on_btnManager_clicked();

    void on_btnManager_pressed();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
