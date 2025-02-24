#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <QObject>
#include <QTimer>

#include "DialogRobot.h"
#include "GlobalHeader.h"


enum{
    AS_INPUT_IDLE,
    AS_INPUT_GET_BASKET,
    AS_INPUT_PUT_BASKET_TO_FIRE,
    AS_INPUT_RETURN,
    AS_INPUT_WAIT_DONE
};

enum{
    AS_SHAKE_IDLE,
    AS_SHAKE_BASKET,
    AS_SHAKE_WAIT_DONE
};

enum{
    AS_OUTPUT_IDLE,
    AS_OUTPUT_GET_BASKET_AT_FIRE,
    AS_OUTPUT_PUT_BASKET_TO_OUTPUT,
    AS_OUTPUT_RETURN,
    AS_OUTPUT_WAIT_DONE
};


enum{
    RO_FREE,
    RO_INPUT,
    RO_SHAKE,
    RO_OUTPUT
};


class Scheduler : public QObject
{
    Q_OBJECT
public:
    Scheduler(DialogRobot *_robot);


    int action_state_input;
    int action_state_shake;
    int action_state_output;

    QString keymotion;

    QStringList strlist_input;
    QStringList strlist_shake;
    QStringList strlist_output;


    QString GetActionStrInput();
    QString GetActionStrShake();
    QString GetActionStrOutput();


public slots:
    void onTimer();

private:
    QTimer  timer;
    DialogRobot *robot;

    int ROBOT_OCCUPY;

    int GetFreeFire();
    int GetNewInput();

    int GetFreeOutput();
    int GetDoneFire();
    int GetShakeFire();

};

#endif // SCHEDULER_H
