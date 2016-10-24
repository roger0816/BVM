#include "StageWarehousing.h"
#include "ui_StageWarehousing.h"

StageWarehousing::StageWarehousing(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StageWarehousing)
{
    ui->setupUi(this);
}

StageWarehousing::~StageWarehousing()
{
    delete ui;
}
