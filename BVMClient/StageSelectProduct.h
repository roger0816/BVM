#ifndef STAGESELECTPRODUCT_H
#define STAGESELECTPRODUCT_H

#include <QWidget>
#include <QLayout>
#include "ItemBtnProduct.h"
#include "LayerProductContent.h"
#include <QShowEvent>
#include <QResizeEvent>
#include <QTimerEvent>
#include <QMouseEvent>
#include "Global.h"
#include <QLayout>
#include <QDir>
#include "Library.h"

#define TIME_EVENT_MSEC 500

namespace Ui {
class StageSelectProduct;
}



class StageSelectProduct : public QWidget
{
    Q_OBJECT

public:
    explicit StageSelectProduct(QWidget *parent = 0);
    ~StageSelectProduct();
    QList<ItemBtnProduct*> m_listBtn;



    QWidget *m_wSpace;

    void ini();
    void showEvent(QShowEvent *);

    void resizeEvent(QResizeEvent *);

    void mousePressEvent(QMouseEvent *event);

    void timerEvent(QTimerEvent*);
    QGridLayout *layout;

    void loadProductList();

    void btnLayout(int iCol,int iRow);
private:
    int m_iMsec;
public slots:

    void clicked();
private:
    Ui::StageSelectProduct *ui;
};

#endif // STAGESELECTPRODUCT_H
