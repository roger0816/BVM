#ifndef DATAPRODUCT_H
#define DATAPRODUCT_H

#include <QObject>

class DataProduct : public QObject
{
    Q_OBJECT
public:
    explicit DataProduct(QObject *parent = 0);

    QString sPid;

    QString sName;

    QString sDeatail;

    QString sImageSpath;

    QString sImageDpath;

    QString sPrice;

signals:

public slots:
};

#endif // DATAPRODUCT_H
