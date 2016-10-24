#include "StageManager.h"
#include "ui_StageManager.h"

StageManager::StageManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StageManager)
{
    ui->setupUi(this);
}

StageManager::~StageManager()
{
    delete ui;
}

void StageManager::on_pushButton_clicked()
{
    GLOBAL().changeStage(Stage::_selectProduct);
}
