#ifndef ITEMBTNPRODUCT_H
#define ITEMBTNPRODUCT_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMouseEvent>
#include <QResizeEvent>
#include <QFont>
#include <QDebug>
#include "DataProduct.h"

class ItemBtnProduct : public QWidget
{
    Q_OBJECT

public:
    explicit ItemBtnProduct(QWidget *parent,int iIdx);
    ~ItemBtnProduct();

    QWidget *m_wBg;

    QLabel *m_lbImage;

    QWidget *m_wMask;

    QWidget *m_wMask2;

    QLabel *m_lbCost;

    void mousePressEvent(QMouseEvent *);

    void setProductName(QString sText);

    void resizeEvent(QResizeEvent *);

    void setSelect(bool bIsSelect=true);

    bool m_bIsSelect;

    DataProduct m_data;

    void updateProduct();

signals:

    void clicked();

private:


    int m_mIdx;
};

#endif // ITEMBTNPRODUCT_H
