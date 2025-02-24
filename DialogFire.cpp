#include "DialogFire.h"
#include "ui_DialogFire.h"
#include "History.h"

#define FIRE_TIMER_MS  200

extern History *phistory;

DialogFire::DialogFire(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogFire)
{
    ui->setupUi(this);

    state = FIRE_STATE_IDLE;
    fry_num_count = 0;
    frying_menu_num = -1;
    frying_time_count = 0;

    FIRE_AVAILABLE = true;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer->start(FIRE_TIMER_MS);
}

DialogFire::~DialogFire()
{
    delete ui;
}

void DialogFire::onTimer(){
    if(state == FIRE_STATE_IDLE || state == FIRE_STATE_JUST_OCCUPIED){
        ui->LE_MENU->setEnabled(false);
        ui->PB_PROGRESS->setEnabled(false);
        ui->BTN_FORCED_STOP->setEnabled(false);
//        ui->LB_FRY_NUM->setEnabled(false);
    }else{
        ui->LE_MENU->setEnabled(true);
        ui->PB_PROGRESS->setEnabled(true);
        ui->BTN_FORCED_STOP->setEnabled(true);
//        ui->LB_FRY_NUM->setEnabled(true);
    }

//    ui->LB_FRY_NUM->setText(QString().sprintf("%d 번째 튀김", fry_num_count));

    switch(state){
    case FIRE_STATE_IDLE:
        ui->PB_PROGRESS->setMaximum(100);
        ui->PB_PROGRESS->setValue(0);
        ui->PB_PROGRESS->setFormat("대기중");
        ui->LE_MENU->setStyleSheet("QLineEdit{background-color:lightgray; font: 25pt \"함초롬돋움\"; font-weight: bold;}");
        break;
    case FIRE_STATE_JUST_OCCUPIED:
        break;
    case FIRE_STATE_FRYING:
    {
        frying_time_count++;
//        frying_time_count += 40;
        int time_sec = frying_time_count/(1000/FIRE_TIMER_MS);

        ui->LE_MENU->setText(current_menu_name);

        int recipe_size = current_menu_recipe.size();
        int out_time = current_menu_recipe[recipe_size-1].action_time;

        for(int i=0; i<recipe_size-1; i++){
            if(current_menu_recipe[i].action_done == 0){
                if(time_sec > current_menu_recipe[i].action_time){
                    current_menu_recipe[i].action_done = 1;

                    QString current_action_str = current_menu_recipe[i].action;
                    if(current_action_str == "SHAKE"){
                        pending_action_type = PENDING_ACTION_SHAKE;
                    }
                    stop_watch.restart();
                    has_pending_action_flag = 1;
                }
            }
        }

        if(time_sec >= out_time){
            pending_action_type = PENDING_ACTION_OUT;
            done_wait_count = 0;
            state = FIRE_STATE_WAIT_REMOVING;
        }

        ui->PB_PROGRESS->setValue(time_sec);
        ui->PB_PROGRESS->setFormat(QString().sprintf("남은시간 : %d초", out_time-time_sec));
        ui->LE_MENU->setStyleSheet("QLineEdit{background-color:lightyellow; font: 25pt \"함초롬돋움\"; font-weight: bold;}");
        break;
    }

    case FIRE_STATE_WAIT_REMOVING:
    {
        ui->PB_PROGRESS->setValue(ui->PB_PROGRESS->maximum());
        ui->PB_PROGRESS->setFormat(QString().sprintf("남은시간 : %d초", 0));
        ui->LE_MENU->setStyleSheet("QLineEdit{background-color:lightgreen; font: 25pt \"함초롬돋움\"; font-weight: bold;}");
        done_wait_count++;
        break;
    }

    case FIRE_STATE_WAIT_EMERGENCY_REMOVING:
    {
        ui->BTN_FORCED_STOP->setStyleSheet("font: 10pt \"함초롬돋움\"; background-color: #DD3939; border-radius: 10px");
        ui->PB_PROGRESS->setFormat("강제종료 대기");
        ui->LE_MENU->setStyleSheet("QLineEdit{background-color:lightgreen; font: 25pt \"함초롬돋움\"; font-weight: bold;}");
        break;
    }

    default:
        break;
    }

}


bool DialogFire::IsAvailable(){
    if(FIRE_AVAILABLE == true && state == FIRE_STATE_IDLE){
        return true;
    }else{
        return false;
    }
}

int DialogFire::GetFryNum(){
    return fry_num_count;
}
void DialogFire::SetFryNum(int num){
    fry_num_count = num;
}

void DialogFire::SetStateOccupied(){
    state = FIRE_STATE_JUST_OCCUPIED;
}
void DialogFire::SetNewInput(int menu_num){
    has_pending_action_flag = 0;
    stop_watch.restart();

    frying_menu_num = menu_num;
    frying_time_count = 0;
    fry_num_count++;


    current_menu_name = MENUS[frying_menu_num].menu_name;
    current_menu_recipe = MENUS[frying_menu_num].recipe;
    int recipe_size = current_menu_recipe.size();
    int out_time = current_menu_recipe[recipe_size-1].action_time;
    QVector<int> draw_info;
    for(int i=0; i<recipe_size; i++){
        current_menu_recipe[i].action_done = 0;
        if(i != recipe_size-1){
            draw_info.push_back(current_menu_recipe[i].action_time);
        }
    }
    DrawPoint(draw_info, out_time);

    ui->PB_PROGRESS->setMaximum(out_time);
    ui->PB_PROGRESS->setValue(0);

    state = FIRE_STATE_FRYING;
}

bool DialogFire::IsDone(){
    if(state == FIRE_STATE_WAIT_REMOVING){
        return true;
    }else{
        return false;
    }
}
bool DialogFire::IsEmergencyStop(){
    if(state == FIRE_STATE_WAIT_EMERGENCY_REMOVING){
        return true;
    }else{
        return false;
    }
}

int DialogFire::GetDoneWaitSec(){
    return done_wait_count/(1000/FIRE_TIMER_MS);
}

int DialogFire::GetMenuNum(){
    return frying_menu_num;
}

void DialogFire::ClearFire(){
    state = FIRE_STATE_IDLE;
    ui->PB_PROGRESS->setMaximum(100);
    ui->PB_PROGRESS->setValue(0);

    phistory->AddResult(current_menu_name, 1);

    ui->BTN_FORCED_STOP->setStyleSheet("font: 10pt \"함초롬돋움\"; background-color: #999999; border-radius: 10px");
}


bool DialogFire::NeedShake(){
    if((state == FIRE_STATE_FRYING) && (has_pending_action_flag == 1)){
        if((stop_watch.elapsed()/1000) < 60){
            return true;
        }
    }
    return false;
}

int DialogFire::GetShakeWaitSec(){
    return stop_watch.elapsed()/1000;
}

void DialogFire::ShakeDone(){
    has_pending_action_flag = 0;
    stop_watch.restart();
}


void DialogFire::DrawPoint(QVector<int> target, int total){
    int h = ui->LB_POINT->height();
    int w = ui->LB_POINT->width();

    QPixmap pix(w, h);
    QPainter paint(&pix);
    pix.fill(QColor(this->palette().background().color()));
    paint.setBrush(QBrush(QColor(255, 0, 0)));
    paint.setPen(QColor(255, 0, 0));

    for(int i=0; i<target.size(); i++){
        int pp = w*target[i]/total;
        paint.fillRect(QRect(pp-1,5,2,15), QColor(255, 0, 0));
    }
    ui->LB_POINT->setPixmap(pix);
}

void DialogFire::ClearPoint(){
    int h = ui->LB_POINT->height();
    int w = ui->LB_POINT->width();
    QPixmap pix(w, h);
    QPainter paint(&pix);
    pix.fill(QColor(this->palette().background().color()));
    ui->LB_POINT->setPixmap(pix);
}


void DialogFire::SetFireAvailable(int available){
    FIRE_AVAILABLE = available;
}

void DialogFire::SetBasketName(QString str){
    ui->LB_BASKET_NAME->setText(str);
}

void DialogFire::on_BTN_FORCED_STOP_clicked(){
    state = FIRE_STATE_WAIT_EMERGENCY_REMOVING;
    qDebug() << "Force Out";
}
