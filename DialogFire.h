#ifndef DIALOGFIRE_H
#define DIALOGFIRE_H

#include <QDialog>
#include <QTimer>
#include <QPainter>
#include <QDebug>

#include "GlobalHeader.h"

typedef enum{
    FIRE_STATE_IDLE = 0,
    FIRE_STATE_JUST_OCCUPIED,
    FIRE_STATE_FRYING,
    FIRE_STATE_WAIT_REMOVING,
    FIRE_STATE_WAIT_EMERGENCY_REMOVING
}ENUM_FIRE_STATE;


typedef enum{
    PENDING_ACTION_SHAKE = 0,
    PENDING_ACTION_OUT
}ENUM_PENDING_ACTION;

namespace Ui {
class DialogFire;
}

class DialogFire : public QDialog
{
    Q_OBJECT

public:
    explicit DialogFire(QWidget *parent = nullptr);
    ~DialogFire();


    bool IsAvailable();
    int GetFryNum();
    void SetFryNum(int num);

    void SetStateOccupied();
    void SetNewInput(int menu_num);


    bool IsDone();
    bool IsEmergencyStop();
    int GetDoneWaitSec();
    int GetMenuNum();
    void ClearFire();


    bool NeedShake();
    int GetShakeWaitSec();
    void ShakeDone();


    void SetBasketName(QString str);
    void SetFireAvailable(int available);


public slots:
    void onTimer();


private slots:
    void on_BTN_FORCED_STOP_clicked();

private:
    Ui::DialogFire *ui;
    QTimer  *timer;

    int state;
    int fry_num_count;

    int frying_menu_num;
    int frying_time_count;

    QString     current_menu_name;
    V_RECIPE    current_menu_recipe;


    int has_pending_action_flag;
    int pending_action_type;
    QTime stop_watch;

    int done_wait_count;


    int FIRE_AVAILABLE;



    void DrawPoint(QVector<int> target, int total);
    void ClearPoint();

};

#endif // DIALOGFIRE_H
