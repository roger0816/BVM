#ifndef ITEMGUIDE_H
#define ITEMGUIDE_H

#include <QWidget>
#include <QDebug>

#include <QTimerEvent>

enum _Action
{
    _Select=0,
    _Pay,
    _Get,
};

struct CImagePath
{
    QString sTopDisable;
    QString sTopEnable;
    QString sBottomDisable;
    QString sBottomEnable;
};

namespace Ui {
class ItemGuide;
}

class ItemGuide : public QWidget
{
    Q_OBJECT

public:
    explicit ItemGuide(QWidget *parent = 0);
    ~ItemGuide();

    void ini();

    void nextAction();

    void resizeEvent(QResizeEvent *);

    void timerEvent(QTimerEvent *);

    int m_iAction;

private:
    Ui::ItemGuide *ui;

    QList<CImagePath> m_listImage;


};

#endif // ITEMGUIDE_H
