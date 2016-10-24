#ifndef ITEMBTNPRODUCT_H
#define ITEMBTNPRODUCT_H

#include <QWidget>
#include <QMouseEvent>
#include <QResizeEvent>
namespace Ui {
class ItemBtnProduct;
}

class ItemBtnProduct : public QWidget
{
    Q_OBJECT

public:
    explicit ItemBtnProduct(QWidget *parent,int iIdx);
    ~ItemBtnProduct();

    void mousePressEvent(QMouseEvent *);

    void setProductName(QString sText);

    void resizeEvent(QResizeEvent *);
signals:
    void clicked();

private:
    Ui::ItemBtnProduct *ui;

    int m_mIdx;
};

#endif // ITEMBTNPRODUCT_H
