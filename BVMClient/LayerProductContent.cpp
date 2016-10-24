#include "LayerProductContent.h"
#include "ui_LayerProductContent.h"

LayerProductContent::LayerProductContent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LayerProductContent)
{
    ui->setupUi(this);
}

LayerProductContent::~LayerProductContent()
{
    delete ui;
}
