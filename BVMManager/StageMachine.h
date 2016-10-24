#ifndef STAGEMACHINE_H
#define STAGEMACHINE_H

#include <QWidget>

namespace Ui {
class StageMachine;
}

class StageMachine : public QWidget
{
    Q_OBJECT

public:
    explicit StageMachine(QWidget *parent = 0);
    ~StageMachine();

private:
    Ui::StageMachine *ui;
};

#endif // STAGEMACHINE_H
