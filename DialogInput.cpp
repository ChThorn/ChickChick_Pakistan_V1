#include "DialogInput.h"
#include "ui_DialogInput.h"

#define INPUT_TIMER_MS  200

DialogInput::DialogInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogInput)
{
    ui->setupUi(this);

    SensorDIO = 0;

    buttons.push_back(ui->BTN_MENU_1);
    buttons.push_back(ui->BTN_MENU_2);
    buttons.push_back(ui->BTN_MENU_3);
    buttons.push_back(ui->BTN_MENU_4);
    buttons.push_back(ui->BTN_MENU_5);
    for(int i=0; i<MENU_TYPE_NUM; i++){
        buttons[i]->setText(MENUS[i].menu_name);
    }

    MenuSelected = -1;

    prev_sensor = 0;
    stable_count = 0;
    SENSOR_ON_FLAG = 0;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer->start(INPUT_TIMER_MS);
}

DialogInput::~DialogInput()
{
    delete ui;
}

void DialogInput::onTimer(){
    if(sys_status.sdata.digital_in[SensorDIO] == 1){
        ui->LE_INPUT_SENSE->setStyleSheet("QLineEdit{background-color:lightgreen; font: 15pt \"함초롬돋움\"; }");

        if(prev_sensor == 0){
            // new triggered
            SENSOR_ON_FLAG = 1;

            for(int i=0; i<MENU_TYPE_NUM; i++){
                buttons[i]->setEnabled(true);
            }
        }else{
            // stable count
            if(MenuSelected != -1){
                stable_count++;
            }
        }
    }else{
        // nothing to fry
        ui->LE_INPUT_SENSE->setStyleSheet("QLineEdit{background-color:lightgray; font: 15pt \"함초롬돋움\"; }");

        for(int i=0; i<MENU_TYPE_NUM; i++){
            buttons[i]->setEnabled(false);
        }
        SENSOR_ON_FLAG = 0;
        MenuSelected = -1;
        stable_count = 0;
    }
    prev_sensor = sys_status.sdata.digital_in[SensorDIO];


    if(SENSOR_ON_FLAG == 1){
        for(int i=0; i<MENU_TYPE_NUM; i++){
            if(i == MenuSelected){
                buttons[i]->setStyleSheet("QPushButton{background-color:orange};");
            }else{
                buttons[i]->setStyleSheet("QPushButton{background-color:lightgray};");
            }
        }
    }else{
        for(int i=0; i<MENU_TYPE_NUM; i++){
            buttons[i]->setStyleSheet("QPushButton{background-color:lightgray};");
        }
    }

}


void DialogInput::SetInputNumber(int input_num){
    InputNumber = input_num;
}
void DialogInput::SetSensorDIO(int dio){
    SensorDIO = dio;
}

void DialogInput::on_BTN_MENU_1_clicked(){
    SelectMenu(0);
}
void DialogInput::on_BTN_MENU_2_clicked(){
    SelectMenu(1);
}
void DialogInput::on_BTN_MENU_3_clicked(){
    SelectMenu(2);
}
void DialogInput::on_BTN_MENU_4_clicked(){
    SelectMenu(3);
}
void DialogInput::on_BTN_MENU_5_clicked(){
    SelectMenu(4);
}

void DialogInput::SelectMenu(int menu){
    if(MenuSelected == menu){
        MenuSelected = -1;
    }else{
        MenuSelected = menu;
    }
    stable_count = 0;
}

bool DialogInput::HasOrder(){
//    qDebug() << SENSOR_ON_FLAG << ", " << MenuSelected << ", " << stable_count;
    if((SENSOR_ON_FLAG == 1) && (MenuSelected != -1) && (stable_count > 2000/INPUT_TIMER_MS)){
        return true;
    }else{
        return false;
    }
}

int DialogInput::GetWaitSec(){
    return stable_count/(1000/INPUT_TIMER_MS);
}

int DialogInput::GetMenuSelected(){
    return MenuSelected;
}

void DialogInput::ClearMenu(){
    MenuSelected = -1;
}

void DialogInput::SetInputName(QString str){
    ui->LE_INPUT_SENSE->setText(str);
}


