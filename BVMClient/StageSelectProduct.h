#ifndef STAGESELECTPRODUCT_H
#define STAGESELECTPRODUCT_H

#include <QWidget>
#include <QLayout>
#include "ItemBtnProduct.h"
#include <QShowEvent>
#include "Global.h"
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
    void showEvent(QShowEvent *);
    QGridLayout *layout;

    void btnLayout(int iCol,int iRow);

private slots:
    void on_pushButton_clicked();

private:
    Ui::StageSelectProduct *ui;
};

#endif // STAGESELECTPRODUCT_H
