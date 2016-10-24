#ifndef STAGEWAREHOUSING_H
#define STAGEWAREHOUSING_H

#include <QWidget>

namespace Ui {
class StageWarehousing;
}

class StageWarehousing : public QWidget
{
    Q_OBJECT

public:
    explicit StageWarehousing(QWidget *parent = 0);
    ~StageWarehousing();

private:
    Ui::StageWarehousing *ui;
};

#endif // STAGEWAREHOUSING_H
