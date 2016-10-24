#ifndef LAYERPRODUCTCONTENT_H
#define LAYERPRODUCTCONTENT_H

#include <QWidget>

namespace Ui {
class LayerProductContent;
}

class LayerProductContent : public QWidget
{
    Q_OBJECT

public:
    explicit LayerProductContent(QWidget *parent = 0);
    ~LayerProductContent();

private:
    Ui::LayerProductContent *ui;
};

#endif // LAYERPRODUCTCONTENT_H
