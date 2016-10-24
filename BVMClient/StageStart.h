#ifndef STAGESTART_H
#define STAGESTART_H

#include <QWidget>
#include <QMouseEvent>
#include <Global.h>
#include <QResizeEvent>
#include <QLabel>
#include <QTimerEvent>
#include "ItemGuide.h"
namespace Ui {
class StageStart;
}

class StageStart : public QWidget
{
    Q_OBJECT

public:
    explicit StageStart(QWidget *parent = 0);
    ~StageStart();

   // void mousePressEvent(QMouseEvent *);

    void resizeEvent(QResizeEvent *);

    void changeIcon(int iIdx);

    QVector<QLabel*> m_listIcon;

    void timerEvent(QTimerEvent *);

    ItemGuide *m_itemGuide;

    int m_iFocusIdx;
signals:
    void singalClicked();

private:
    Ui::StageStart *ui;
};

#endif // STAGESTART_H
