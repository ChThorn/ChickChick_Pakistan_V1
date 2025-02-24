#ifndef DIALOGINPUT_H
#define DIALOGINPUT_H

#include <QDialog>
#include <QTimer>
#include <QPushButton>
#include <QDebug>

#include "GlobalHeader.h"

namespace Ui {
class DialogInput;
}

class DialogInput : public QDialog
{
    Q_OBJECT

public:
    explicit DialogInput(QWidget *parent = nullptr);
    ~DialogInput();

    void SetInputNumber(int input_num);
    void SetSensorDIO(int dio);

    bool HasOrder();
    int GetWaitSec();
    int GetMenuSelected();

    void ClearMenu();

    void SetInputName(QString str);

public slots:
    void onTimer();

private slots:
    void on_BTN_MENU_1_clicked();
    void on_BTN_MENU_2_clicked();
    void on_BTN_MENU_3_clicked();
    void on_BTN_MENU_4_clicked();

    void on_BTN_MENU_5_clicked();

private:
    Ui::DialogInput *ui;
    QTimer  *timer;

    int MenuSelected;
    void SelectMenu(int menu);

    int InputNumber;
    int SensorDIO;

    int prev_sensor;
    int stable_count;

    int SENSOR_ON_FLAG;

    QVector<QPushButton*> buttons;
};

#endif // DIALOGINPUT_H
