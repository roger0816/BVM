#include "StageMachine.h"
#include "ui_StageMachine.h"

StageMachine::StageMachine(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StageMachine)
{
    ui->setupUi(this);
}

StageMachine::~StageMachine()
{
    delete ui;
}
