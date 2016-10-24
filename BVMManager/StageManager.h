#ifndef STAGEMANAGER_H
#define STAGEMANAGER_H

#include <QWidget>
#include "Global.h"
namespace Ui {
class StageManager;
}

class StageManager : public QWidget
{
    Q_OBJECT

public:
    explicit StageManager(QWidget *parent = 0);
    ~StageManager();

private slots:


    void on_pushButton_clicked();

private:
    Ui::StageManager *ui;
};

#endif // STAGEMANAGER_H
