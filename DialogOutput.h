#ifndef DIALOGOUTPUT_H
#define DIALOGOUTPUT_H

#include <QDialog>
#include <QTimer>

#include "GlobalHeader.h"


namespace Ui {
class DialogOutput;
}

class DialogOutput : public QDialog
{
    Q_OBJECT

public:
    explicit DialogOutput(QWidget *parent = nullptr);
    ~DialogOutput();

    void SetOutputNumber(int output_num);
    void SetSensorDIO(int dio);

    bool IsEmpty();
    int GetWaitSec();

    void SetNewOutput(int menu_num);

public slots:
    void onTimer();

private:
    Ui::DialogOutput *ui;
    QTimer  *timer;

    int OutputNumber;
    int SensorDIO;

    int stable_count;

    int SENSOR_OFF_FLAG;

    QString LastMenuName;
};

#endif // DIALOGOUTPUT_H
