#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QTimer>

#include "DialogRobot.h"
#include "DialogFire.h"
#include "DialogInput.h"
#include "DialogOutput.h"
#include "Recipe.h"
#include "History.h"
#include "Scheduler.h"
#include "Logger.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    DialogRobot *robot;
    Recipe      *recipe;
    History     *history;
    Scheduler   *schedule;

    QVector<DialogFire*>    fires;
    QVector<DialogInput*>   inputs;
    QVector<DialogOutput*>  outputs;

public slots:
    void onTimer();

private slots:
    void on_BTN_TEST_SEN_ON_1_clicked();
    void on_BTN_TEST_SEN_OFF_1_clicked();
    void on_BTN_TEST_SEN_ON_2_clicked();
    void on_BTN_TEST_SEN_OFF_2_clicked();

//    void on_BTN_TEST_SEN_ON_4_clicked();
    void on_BTN_TEST_SEN_OFF_3_clicked();
//    void on_BTN_TEST_SEN_ON_5_clicked();
//    void on_BTN_TEST_SEN_OFF_4_clicked();

    void on_BTN_FIRE_DEVICE_1_clicked();

    void on_BTN_FIRE_DEVICE_2_clicked();

    void on_BTN_OIL_RESET_1_clicked();

    void on_BTN_OIL_RESET_2_clicked();

    void on_BTN_TEST_SEN_ON_3_clicked();

//    void on_BTN_TEST_SEN_OFF_5_clicked();

    void on_BTN_EXIT_pressed();

    void on_BTN_RESTART_pressed();

    void on_BTN_EXIT_released();

    void on_BTN_RESTART_released();

    void on_BTN_MINIMIZE_pressed();

    void on_BTN_MINIMIZE_released();

private:
    Ui::MainWindow *ui;
    QTimer *timer;

    void SetFireBtnStylesheet(QPushButton *btn, int onoff);


    QTime   exit_time;
    QTime   restart_time;
    QTime   minimize_time;
};
#endif // MAINWINDOW_H
