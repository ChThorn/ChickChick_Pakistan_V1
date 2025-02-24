#include "DialogOutput.h"
#include "ui_DialogOutput.h"

#define OUTPUT_TIMER_MS  200


DialogOutput::DialogOutput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogOutput)
{
    ui->setupUi(this);

    stable_count = 0;
    SENSOR_OFF_FLAG = 0;


    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer->start(OUTPUT_TIMER_MS);
}

DialogOutput::~DialogOutput()
{
    delete ui;
}

void DialogOutput::onTimer(){
    if(sys_status.sdata.digital_in[SensorDIO] == 1){
        this->setStyleSheet("border: 0px solid #595959;\
                            background-color: #60D88D;\
                            border-radius: 16px;");

//        ui->LE_OUTPUT_SENSE->setStyleSheet("QLineEdit{background-color:lightgreen};");
        ui->LE_MENU_NAME->setEnabled(true);
        SENSOR_OFF_FLAG = 0;
        stable_count = 0;
    }else{
        this->setStyleSheet("border: 0px solid #595959;\
                            background-color: lightgray;\
                            border-radius: 16px;");

//        ui->LE_OUTPUT_SENSE->setStyleSheet("QLineEdit{background-color:lightgray};");
        ui->LE_MENU_NAME->setEnabled(false);
        SENSOR_OFF_FLAG = 1;
        stable_count++;
    }
    ui->LE_MENU_NAME->setText(LastMenuName);
}


void DialogOutput::SetOutputNumber(int output_num){
    OutputNumber = output_num;
}
void DialogOutput::SetSensorDIO(int dio){
    SensorDIO = dio;
}

bool DialogOutput::IsEmpty(){
    if((SENSOR_OFF_FLAG == 1) && (stable_count > 2000/OUTPUT_TIMER_MS)){
        return true;
    }else{
        return false;
    }
}

int DialogOutput::GetWaitSec(){
    return stable_count/(1000/OUTPUT_TIMER_MS);
}

void DialogOutput::SetNewOutput(int menu_num){
    LastMenuName = MENUS[menu_num].menu_name;
}
