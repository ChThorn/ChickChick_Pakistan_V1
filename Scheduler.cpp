#include "Scheduler.h"
#include <math.h>
#include <DialogFire.h>
#include <DialogInput.h>
#include <DialogOutput.h>

#define SCHEDULER_TIME_INTERVAL 100
#define MOTION_RESPONSE_DELAY   60000
#define LOADCELL_TARE_DELAY     400
#define COFFEE_RESPONSE_DELAY   4000
#define COFFEE_LAST_DELAY       1500
#define ICECREAM_WAIT_DELAY     3500


extern Logger *plog;
extern QVector<DialogFire*>    *pfires;
extern QVector<DialogInput*>   *pinputs;
extern QVector<DialogOutput*>  *poutputs;


Scheduler::Scheduler(DialogRobot *_robot) :
    robot(_robot)
{
    ROBOT_OCCUPY = RO_FREE;

    action_state_shake = AS_SHAKE_IDLE;
    action_state_input = AS_INPUT_IDLE;
    action_state_output = AS_OUTPUT_IDLE;


    strlist_input
        << "INPUT_IDLE"
        << "INPUT_GET_BASKET"
        << "INPUT_PUT_BASKET_TO_FIRE"
        << "INPUT_RETURN"
        << "INPUT_WAIT_DONE";

    strlist_shake
        << "SHAKE_IDLE"
        << "SHAKE_BASKET"
        << "SHAKE_WAIT_DONE";

    strlist_output
        << "OUTPUT_IDLE"
        << "OUTPUT_GET_BASKET_AT_FIRE"
        << "OUTPUT_PUT_BASKET_TO_OUTPUT"
        << "OUTPUT_RETURN"
        << "OUTPUT_WAIT_DONE";


    connect(&timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer.start(SCHEDULER_TIME_INTERVAL);
}

int Scheduler::GetFreeFire(){
    int ret = -1;
    int lowest_fry_num = 999999;
    for(int i=0; i<FIRE_NUM; i++){
        if(pfires->at(i)->IsAvailable()){
            int fry_num = pfires->at(i)->GetFryNum();
            if(fry_num < lowest_fry_num){
                lowest_fry_num = fry_num;
                ret = i;
            }
        }
    }
    return ret;
}

int Scheduler::GetNewInput(){
    int ret = -1;
    int longest_wait_sec = -1;
    for(int i=0; i<pinputs->size(); i++){
        if(pinputs->at(i)->HasOrder()){
            int wait_sec = pinputs->at(i)->GetWaitSec();
            if(wait_sec > longest_wait_sec){
                longest_wait_sec = wait_sec;
                ret = i;
            }
        }
    }
    return ret;
}


int Scheduler::GetFreeOutput(){
    int ret = -1;
    int longest_wait_sec = -1;
    for(int i=0; i<poutputs->size(); i++){
        if(poutputs->at(i)->IsEmpty()){
            int wait_sec = poutputs->at(i)->GetWaitSec();
            if(wait_sec > longest_wait_sec){
                longest_wait_sec = wait_sec;
                ret = i;
            }
        }
    }
    return ret;
}

int Scheduler::GetDoneFire(){
    int ret = -1;
    int longest_wait_sec = -1;
    for(int i=0; i<FIRE_NUM; i++){
        if(pfires->at(i)->IsEmergencyStop()){
            ret = i;
            return ret;
        }
        if(pfires->at(i)->IsDone()){
            int wait_sec = pfires->at(i)->GetDoneWaitSec();
            if(wait_sec > longest_wait_sec){
                longest_wait_sec = wait_sec;
                ret = i;
            }
        }
    }
    return ret;
}

int Scheduler::GetShakeFire(){
    int ret = -1;
    int longest_wait_sec = -1;
    for(int i=0; i<FIRE_NUM; i++){
        if(pfires->at(i)->NeedShake()){
            int wait_sec = pfires->at(i)->GetShakeWaitSec();
            if(wait_sec > longest_wait_sec){
                longest_wait_sec = wait_sec;
                ret = i;
            }
        }
    }
    return ret;
}


void Scheduler::onTimer(){
//    static int timeout = 0;

//    static unsigned int ext_coll_flag = 0;
//    static unsigned int ext_coll_cnt = 0;
//    if(OP_STATUS_OPERATING == PLATFORM_OPERATION_ON_OPERATING_STATE){
//        if((sys_status.sdata.op_stat_collision_occur == 1) && (ext_coll_cnt < 3)){
//            ext_coll_flag++;
//            if(ext_coll_flag%10 == 0){
//                robot->CollisionResume();
//                ext_coll_cnt++;

//                plog->write("[SCHEDULE] ERROR : ROBOT COLLISION OCCUR " + QString::number(ext_coll_cnt));

//            }
//        }
//    }



    //==========================================================================================
    static int OUTPUT_TARGET_OUTPUT = -1;
    static int OUTPUT_TARGET_FIRE = -1;
    static int OUTPUT_TARGET_MENU = -1;
    switch(action_state_output){
    case AS_OUTPUT_IDLE:
    {
        if(ROBOT_OCCUPY != RO_FREE)
            break;
        if(robot->RobotMoving == true)
            break;

        int target_output = GetFreeOutput();
        int target_fire = GetDoneFire();
        if((target_output != -1) && (target_fire != -1)){
            int target_menu = pfires->at(target_fire)->GetMenuNum();
            OUTPUT_TARGET_MENU = target_menu;
            OUTPUT_TARGET_OUTPUT = target_output;
            OUTPUT_TARGET_FIRE = target_fire;
            ROBOT_OCCUPY = RO_OUTPUT;
            action_state_output = AS_OUTPUT_GET_BASKET_AT_FIRE;
        }
        break;
    }

    case AS_OUTPUT_GET_BASKET_AT_FIRE:
        if(robot->RobotMoving == true)
            break;

        qDebug() << "AS_OUTPUT_GET_BASKET_AT_FIRE";

        if(OUTPUT_TARGET_FIRE == 0){
            keymotion = "GET_FIRE_1";
        }else if(OUTPUT_TARGET_FIRE == 1){
            keymotion = "GET_FIRE_2";
        }else if(OUTPUT_TARGET_FIRE == 2){
            keymotion = "GET_FIRE_3";
        }else if(OUTPUT_TARGET_FIRE == 3){
            keymotion = "GET_FIRE_4";
        }else if(OUTPUT_TARGET_FIRE == 4){
            keymotion = "GET_FIRE_5";
        }else if(OUTPUT_TARGET_FIRE == 5){
            keymotion = "GET_FIRE_6";
        }else{
            qDebug() << "Error (AS_OUTPUT_GET_BASKET_AT_FIRE) Wrong TARGET_FIRE " << OUTPUT_TARGET_FIRE;
            ROBOT_OCCUPY = RO_FREE;
            action_state_output = AS_OUTPUT_IDLE;
            break;
        }
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        action_state_output = AS_OUTPUT_PUT_BASKET_TO_OUTPUT;
        break;

    case AS_OUTPUT_PUT_BASKET_TO_OUTPUT:
        if(robot->RobotMoving == true)
            break;

        qDebug() << "AS_OUTPUT_PUT_BASKET_TO_OUTPUT";


        // clear fire information
        pfires->at(OUTPUT_TARGET_FIRE)->ClearFire();


        if(OUTPUT_TARGET_OUTPUT == 0){
            keymotion = "PUT_OUTPUT_1";
        }else if(OUTPUT_TARGET_OUTPUT == 1){
            keymotion = "PUT_OUTPUT_2";
        }else{
            qDebug() << "Error (AS_OUTPUT_PUT_BASKET_TO_OUTPUT) Wrong TARGET_OUTPUT " << OUTPUT_TARGET_OUTPUT;
            ROBOT_OCCUPY = RO_FREE;
            action_state_output = AS_OUTPUT_IDLE;
            break;
        }
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        action_state_output = AS_OUTPUT_RETURN;
        break;

    case AS_OUTPUT_RETURN:
        if(robot->RobotMoving == true)
            break;

        qDebug() << "AS_OUTPUT_RETURN";

        // apply new result data to output information
        poutputs->at(OUTPUT_TARGET_OUTPUT)->SetNewOutput(OUTPUT_TARGET_MENU);

        // for debugging
        if(OUTPUT_TARGET_OUTPUT == 0){
            sys_status.sdata.digital_in[4] = 1;
        }else if(OUTPUT_TARGET_OUTPUT == 1){
            sys_status.sdata.digital_in[5] = 1;
        }

//        keymotion = "OUTPUT_RETURN";
//        robot->RobotMoving = true;
//        robot->MotionServerCommand(keymotion);

        action_state_output = AS_OUTPUT_WAIT_DONE;
        break;

    case AS_OUTPUT_WAIT_DONE:
        if(robot->RobotMoving == true)
            break;

        qDebug() << "AS_OUTPUT_WAIT_DONE";

        OUTPUT_TARGET_OUTPUT = -1;
        OUTPUT_TARGET_FIRE = -1;
        ROBOT_OCCUPY = RO_FREE;
        action_state_output = AS_OUTPUT_IDLE;
        return;
        break;
    }
    //==========================================================================================




    //==========================================================================================
    static int SHAKE_TARGET_FIRE = -1;
    switch(action_state_shake){
    case AS_SHAKE_IDLE:
    {
        if(ROBOT_OCCUPY != RO_FREE)
            break;
        if(robot->RobotMoving == true)
            break;

        int target_fire = GetShakeFire();

        if(target_fire != -1){
            SHAKE_TARGET_FIRE = target_fire;

            ROBOT_OCCUPY = RO_SHAKE;
            action_state_shake = AS_SHAKE_BASKET;
        }
        break;
    }

    case AS_SHAKE_BASKET:
        if(robot->RobotMoving == true)
            break;

        qDebug() << "AS_SHAKE_BASKET";


        if(SHAKE_TARGET_FIRE == 0){
            keymotion = "SHAKE_FIRE_1";
        }else if(SHAKE_TARGET_FIRE == 1){
            keymotion = "SHAKE_FIRE_2";
        }else if(SHAKE_TARGET_FIRE == 2){
            keymotion = "SHAKE_FIRE_3";
        }else if(SHAKE_TARGET_FIRE == 3){
            keymotion = "SHAKE_FIRE_4";
        }else if(SHAKE_TARGET_FIRE == 4){
            keymotion = "SHAKE_FIRE_5";
        }else if(SHAKE_TARGET_FIRE == 5){
            keymotion = "SHAKE_FIRE_6";
        }else{
            qDebug() << "Error (AS_SHAKE_BASKET) Wrong TARGET_FIRE " << SHAKE_TARGET_FIRE;
            ROBOT_OCCUPY = RO_FREE;
            action_state_shake = AS_SHAKE_IDLE;
            break;
        }
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        action_state_shake = AS_SHAKE_WAIT_DONE;
        break;

    case AS_SHAKE_WAIT_DONE:
        if(robot->RobotMoving == true)
            break;

        qDebug() << "AS_SHAKE_WAIT_DONE";

        // apply shake done to to fire information
        pfires->at(SHAKE_TARGET_FIRE)->ShakeDone();

        SHAKE_TARGET_FIRE = -1;
        ROBOT_OCCUPY = RO_FREE;
        action_state_shake = AS_SHAKE_IDLE;
        return;
        break;
    }
    //==========================================================================================




    //==========================================================================================
    static int INPUT_TARGET_INPUT = -1;
    static int INPUT_TARGET_FIRE = -1;
    static int INPUT_TARGET_MENU = -1;
    switch(action_state_input){
    case AS_INPUT_IDLE:
    {
        if(ROBOT_OCCUPY != RO_FREE)
            break;
        if(robot->RobotMoving == true)
            break;

        int target_input = GetNewInput();
        int target_fire = GetFreeFire();
//        qDebug() << target_input << ", " << target_fire;
        if((target_input != -1) && (target_fire != -1)){
            int target_menu = pinputs->at(target_input)->GetMenuSelected();
            if(target_menu != -1){
                INPUT_TARGET_MENU = target_menu;
                INPUT_TARGET_INPUT = target_input;
                INPUT_TARGET_FIRE = target_fire;

                ROBOT_OCCUPY = RO_INPUT;
                action_state_input = AS_INPUT_GET_BASKET;
            }
        }
        break;
    }

    case AS_INPUT_GET_BASKET:
        if(robot->RobotMoving == true)
            break;

        qDebug() << "AS_INPUT_GET_BASKET";


        if(INPUT_TARGET_INPUT == 0){
            keymotion = "GET_INPUT_1";
        }else if(INPUT_TARGET_INPUT == 1){
            keymotion = "GET_INPUT_2";
        }else if(INPUT_TARGET_INPUT == 2){
            keymotion = "GET_INPUT_3";
        }else{
            qDebug() << "Error (AS_INPUT_GET_BASKET) Wrong TARGET_INPUT " << INPUT_TARGET_INPUT;
            ROBOT_OCCUPY = RO_FREE;
            action_state_input = AS_INPUT_IDLE;
            break;
        }
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        action_state_input = AS_INPUT_PUT_BASKET_TO_FIRE;
        break;

    case AS_INPUT_PUT_BASKET_TO_FIRE:
        if(robot->RobotMoving == true)
            break;

        qDebug() << "AS_INPUT_PUT_BASKET_TO_FIRE";
        // for debugging
//        if(INPUT_TARGET_INPUT == 0){
//            sys_status.sdata.digital_in[0] = 0;
//        }else if(INPUT_TARGET_INPUT == 1){
//            sys_status.sdata.digital_in[1] = 0;
//        }

        pinputs->at(INPUT_TARGET_INPUT)->ClearMenu();


        if(INPUT_TARGET_FIRE == 0){
            keymotion = "PUT_FIRE_1";
        }else if(INPUT_TARGET_FIRE == 1){
            keymotion = "PUT_FIRE_2";
        }else if(INPUT_TARGET_FIRE == 2){
            keymotion = "PUT_FIRE_3";
        }else if(INPUT_TARGET_FIRE == 3){
            keymotion = "PUT_FIRE_4";
        }else if(INPUT_TARGET_FIRE == 4){
            keymotion = "PUT_FIRE_5";
        }else if(INPUT_TARGET_FIRE == 5){
            keymotion = "PUT_FIRE_6";
        }else{
            qDebug() << "Error (AS_INPUT_PUT_BASKET_TO_FIRE) Wrong TARGET_FIRE " << INPUT_TARGET_FIRE;
            ROBOT_OCCUPY = RO_FREE;
            action_state_input = AS_INPUT_IDLE;
            break;
        }
        robot->RobotMoving = true;
        robot->MotionServerCommand(keymotion);

        action_state_input = AS_INPUT_RETURN;
        break;

    case AS_INPUT_RETURN:
        if(robot->RobotMoving == true)
            break;

        qDebug() << "AS_INPUT_RETURN";

        // apply new input data to fire information
        pfires->at(INPUT_TARGET_FIRE)->SetNewInput(INPUT_TARGET_MENU);


//        keymotion = "FIRE_RETURN";
//        robot->RobotMoving = true;
//        robot->MotionServerCommand(keymotion);

        action_state_input = AS_INPUT_WAIT_DONE;
        break;

    case AS_INPUT_WAIT_DONE:
        if(robot->RobotMoving == true)
            break;


        qDebug() << "AS_INPUT_WAIT_DONE";


        INPUT_TARGET_INPUT = -1;
        INPUT_TARGET_FIRE = -1;
        ROBOT_OCCUPY = RO_FREE;
        action_state_input = AS_INPUT_IDLE;
        return;
        break;
    }
    //==========================================================================================



    // for test
//    static int test_timer = 0;
//    if(robot->RobotMoving == true){
//        test_timer++;
//        if(test_timer > 3){
//            robot->RobotMoving = false;
//            test_timer = 0;
//        }
//    }
//    robot->RobotMoving = false;
}



QString Scheduler::GetActionStrInput(){
    return strlist_input[action_state_input];
}
QString Scheduler::GetActionStrShake(){
    return strlist_shake[action_state_shake];
}
QString Scheduler::GetActionStrOutput(){
    return strlist_output[action_state_output];
}
