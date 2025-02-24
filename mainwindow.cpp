#include "mainwindow.h"
#include "ui_mainwindow.h"


int FIRE_NUM = 4;
int CLOSE_HOUR = 3;

int IS_UI_LOCK = false;
int OP_STATUS_OPERATING = PLATFORM_OPERATION_IDLE;


Logger *plog;
QString appPath;

QVector<DialogFire*>    *pfires;
QVector<DialogInput*>   *pinputs;
QVector<DialogOutput*>  *poutputs;
History *phistory;


int FIRE_DEVICE_FLAG_1 = true;
int FIRE_DEVICE_FLAG_2 = true;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    appPath = QApplication::applicationDirPath()+"/";

    plog->init();
    plog->write("[운영] 프로그램 시작");
//    plog->write("A::" + QApplication::applicationDirPath());
//    plog->write("B::" + QDir::currentPath());

    QImage logo;
    QString build_path = BUILD_PATH;
    QString logo_path = appPath + "SETTING/logo.jpg";
    logo.load(logo_path, "jpg");
    ui->LB_LOGO->setPixmap(QPixmap::fromImage(logo).scaled(ui->LB_LOGO->size()));

    SetFireBtnStylesheet(ui->BTN_FIRE_DEVICE_1, 1);
    SetFireBtnStylesheet(ui->BTN_FIRE_DEVICE_2, 1);
//    SetBTNColor(ui->BTN_FIRE_DEVICE_1, COLOR_GOOD);
//    SetBTNColor(ui->BTN_FIRE_DEVICE_2, COLOR_GOOD);
//    SetBTNColor(ui->BTN_INPUT_DEVICE, COLOR_GOOD);
//    SetBTNColor(ui->BTN_OUTPUT_DEVICE, COLOR_GOOD);


    QString setting_path = appPath + "SETTING/setting.ini";
    QSettings setting(setting_path, QSettings::IniFormat);
//    FIRE_NUM = setting.value("FIRE_NUM").toInt();
    CLOSE_HOUR = setting.value("CLOSE_HOUR").toInt();

    robot = new DialogRobot(ui->FRAME_DEVICE);
    robot->setWindowFlags(Qt::Widget);
    robot->move(0, 0);

    recipe = new Recipe();
    history = new History();
    phistory = history;
    schedule = new Scheduler(robot);


    ui->LB_HISTORY_MENU_NAME_1->setText(MENUS[0].menu_name);
    ui->LB_HISTORY_MENU_NAME_2->setText(MENUS[1].menu_name);
    ui->LB_HISTORY_MENU_NAME_3->setText(MENUS[2].menu_name);
    ui->LB_HISTORY_MENU_NAME_4->setText(MENUS[3].menu_name);
    ui->LB_HISTORY_MENU_NAME_5->setText(MENUS[4].menu_name);


    //--------------------------------
    DialogFire *tempFire1 = new DialogFire(ui->FRAME_FIRE_1);
    DialogFire *tempFire2 = new DialogFire(ui->FRAME_FIRE_2);
    DialogFire *tempFire3 = new DialogFire(ui->FRAME_FIRE_3);
    DialogFire *tempFire4 = new DialogFire(ui->FRAME_FIRE_4);

    fires.push_back(tempFire1);
    fires.push_back(tempFire2);
    fires.push_back(tempFire3);
    fires.push_back(tempFire4);

    for(int i=0; i<4; i++){
        fires[i]->setWindowFlags(Qt::Widget);
        fires[i]->move(0, 0);
        fires[i]->SetBasketName(QString().sprintf("#%d", i+1));
        if(i<FIRE_NUM){
            fires[i]->setVisible(true);
        }else{
            fires[i]->setVisible(false);
        }
    }
    pfires = &fires;


    //--------------------------------
    DialogInput *tempInput1 = new DialogInput(ui->FRAME_INPUT_1);
    DialogInput *tempInput2 = new DialogInput(ui->FRAME_INPUT_2);
    DialogInput *tempInput3 = new DialogInput(ui->FRAME_INPUT_3);

    tempInput1->SetInputNumber(0);
    tempInput2->SetInputNumber(1);
    tempInput3->SetInputNumber(2);
    tempInput1->SetSensorDIO(0);
    tempInput2->SetSensorDIO(1);
    tempInput3->SetSensorDIO(12);

    tempInput1->setWindowFlags(Qt::Widget);
    tempInput2->setWindowFlags(Qt::Widget);
    tempInput3->setWindowFlags(Qt::Widget);

    tempInput1->move(0, 0);
    tempInput2->move(0, 0);
    tempInput3->move(0, 0);

    tempInput1->SetInputName("#1");
    tempInput2->SetInputName("#2");
    tempInput3->SetInputName("#3");

    inputs.push_back(tempInput1);
    inputs.push_back(tempInput2);
    inputs.push_back(tempInput3);

    pinputs = &inputs;


    //--------------------------------
    DialogOutput *tempOutput1 = new DialogOutput(ui->FRAME_OUTPUT_1);
    DialogOutput *tempOutput2 = new DialogOutput(ui->FRAME_OUTPUT_2);

    tempOutput1->SetOutputNumber(0);
    tempOutput2->SetOutputNumber(1);
    tempOutput1->SetSensorDIO(2);
    tempOutput2->SetSensorDIO(3);

    tempOutput1->setWindowFlags(Qt::Widget);
    tempOutput2->setWindowFlags(Qt::Widget);

    tempOutput1->move(0, 0);
    tempOutput2->move(0, 0);

    outputs.push_back(tempOutput1);
    outputs.push_back(tempOutput2);

    poutputs = &outputs;


    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()), this, SLOT(onTimer()));
    timer->start(500);

    showFullScreen();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onTimer(){
    ui->LB_INPUT_STATE->setText(schedule->GetActionStrInput());
    ui->LB_SHAKE_STATE->setText(schedule->GetActionStrShake());
    ui->LB_OUTPUT_STATE->setText(schedule->GetActionStrOutput());

    ui->LB_FRY_NUM_1->setText(QString().sprintf("%d times", fires[0]->GetFryNum()+fires[1]->GetFryNum()));
    ui->LB_FRY_NUM_2->setText(QString().sprintf("%d times", fires[2]->GetFryNum()+fires[3]->GetFryNum()));

    int menu_num_1 = history->GetResult(MENUS[0].menu_name);
    int menu_num_2 = history->GetResult(MENUS[1].menu_name);
    int menu_num_3 = history->GetResult(MENUS[2].menu_name);
    int menu_num_4 = history->GetResult(MENUS[3].menu_name);
    int menu_num_5 = history->GetResult(MENUS[4].menu_name);
    int menu_num_all = menu_num_1+menu_num_2+menu_num_3+menu_num_4+menu_num_5;

    ui->LE_HISTORY_MENU_NUM_1->setText(QString().sprintf("%d", menu_num_1));
    ui->LE_HISTORY_MENU_NUM_2->setText(QString().sprintf("%d", menu_num_2));
    ui->LE_HISTORY_MENU_NUM_3->setText(QString().sprintf("%d", menu_num_3));
    ui->LE_HISTORY_MENU_NUM_4->setText(QString().sprintf("%d", menu_num_4));
    ui->LE_HISTORY_MENU_NUM_5->setText(QString().sprintf("%d", menu_num_5));
    ui->LE_HISTORY_MENU_NUM_ALL->setText(QString().sprintf("%d", menu_num_all));
}


void MainWindow::on_BTN_TEST_SEN_ON_1_clicked(){
    sys_status.sdata.digital_in[0] = 1;
}
void MainWindow::on_BTN_TEST_SEN_OFF_1_clicked(){
    sys_status.sdata.digital_in[0] = 0;
}
void MainWindow::on_BTN_TEST_SEN_ON_2_clicked(){
    sys_status.sdata.digital_in[1] = 1;
}
void MainWindow::on_BTN_TEST_SEN_OFF_2_clicked(){
    sys_status.sdata.digital_in[1] = 0;
}
void MainWindow::on_BTN_TEST_SEN_ON_3_clicked(){
    sys_status.sdata.digital_in[2] = 1;
}
void MainWindow::on_BTN_TEST_SEN_OFF_3_clicked(){
    sys_status.sdata.digital_in[2] = 0;
}

//-----------------
//void MainWindow::on_BTN_TEST_SEN_ON_4_clicked(){
//    sys_status.sdata.digital_in[3] = 1;
//}
//void MainWindow::on_BTN_TEST_SEN_OFF_4_clicked(){
//    sys_status.sdata.digital_in[3] = 0;
//}
//-----------------


//void MainWindow::on_BTN_TEST_SEN_ON_5_clicked(){
//    sys_status.sdata.digital_in[4] = 1;
//}
//void MainWindow::on_BTN_TEST_SEN_OFF_5_clicked(){
//    sys_status.sdata.digital_in[4] = 0;
//}

void MainWindow::on_BTN_FIRE_DEVICE_1_clicked(){
    if(FIRE_DEVICE_FLAG_1 == true){
        FIRE_DEVICE_FLAG_1 = false;
        fires[0]->SetFireAvailable(false);
        fires[1]->SetFireAvailable(false);
        SetFireBtnStylesheet(ui->BTN_FIRE_DEVICE_1, 0);
//        SetBTNColor(ui->BTN_FIRE_DEVICE_1, COLOR_UNDETERMINED);
    }else{
        FIRE_DEVICE_FLAG_1 = true;
        fires[0]->SetFireAvailable(true);
        fires[1]->SetFireAvailable(true);
        SetFireBtnStylesheet(ui->BTN_FIRE_DEVICE_1, 1);
//        SetBTNColor(ui->BTN_FIRE_DEVICE_1, COLOR_GOOD);
    }
}

void MainWindow::on_BTN_FIRE_DEVICE_2_clicked(){
    if(FIRE_DEVICE_FLAG_2 == true){
        FIRE_DEVICE_FLAG_2 = false;
        fires[2]->SetFireAvailable(false);
        fires[3]->SetFireAvailable(false);
        SetFireBtnStylesheet(ui->BTN_FIRE_DEVICE_2, 0);
//        SetBTNColor(ui->BTN_FIRE_DEVICE_2, COLOR_UNDETERMINED);
    }else{
        FIRE_DEVICE_FLAG_2 = true;
        fires[2]->SetFireAvailable(true);
        fires[3]->SetFireAvailable(true);
        SetFireBtnStylesheet(ui->BTN_FIRE_DEVICE_2, 1);
//        SetBTNColor(ui->BTN_FIRE_DEVICE_2, COLOR_GOOD);
    }
}

void MainWindow::on_BTN_OIL_RESET_1_clicked(){
    fires[0]->SetFryNum(0);
    fires[1]->SetFryNum(0);
}

void MainWindow::on_BTN_OIL_RESET_2_clicked(){
    fires[2]->SetFryNum(0);
    fires[3]->SetFryNum(0);
}


void MainWindow::SetFireBtnStylesheet(QPushButton *btn, int onoff){
    if(onoff == 1){
        btn->setStyleSheet("QPushButton {\
            border:0px solid #595959;\
            font: 25pt \"함초롬돋움\";\
           font-weight: bold;\
           background-color: #DC6666;\
           border-top-left-radius: 20px;\
           border-top-right-radius: 20px;}");
    }else{
        btn->setStyleSheet("QPushButton {\
        border:0px solid #595959;\
        font: 25pt \"함초롬돋움\";\
        font-weight: bold;\
        background-color: #9F9F9F;\
        border-top-left-radius: 20px;\
        border-top-right-radius: 20px;}");
    }
}

void MainWindow::on_BTN_EXIT_pressed(){
    exit_time.restart();
    ui->BTN_EXIT->setStyleSheet("font: 12pt \"함초롬돋움\"; background-color: #FF5555; border-radius: 10px; border: 0px solid #595959;");
}

void MainWindow::on_BTN_RESTART_pressed(){
    restart_time.restart();
    ui->BTN_RESTART->setStyleSheet("font: 12pt \"함초롬돋움\"; background-color: #5555FF; border-radius: 10px; border: 0px solid #595959;");
}

void MainWindow::on_BTN_EXIT_released(){
    if(exit_time.elapsed() > 1000){
        plog->write("[사용자 입력] 프로그램 종료");
        QApplication::quit();
    }
    ui->BTN_EXIT->setStyleSheet("font: 12pt \"함초롬돋움\"; background-color: #FF9999; border-radius: 10px; border: 0px solid #595959;");
}

void MainWindow::on_BTN_RESTART_released(){
    if(restart_time.elapsed() > 1000){
        plog->write("[사용자 입력] 프로그램 재시작");
        QProcess::startDetached(QApplication::applicationFilePath());
        QApplication::exit(12);
    }
    ui->BTN_RESTART->setStyleSheet("font: 12pt \"함초롬돋움\"; background-color: #9999FF; border-radius: 10px; border: 0px solid #595959;");
}

void MainWindow::on_BTN_MINIMIZE_pressed(){
    minimize_time.restart();
    ui->BTN_MINIMIZE->setStyleSheet("font: 12pt \"함초롬돋움\"; background-color: #55FF55; border-radius: 10px; border: 0px solid #595959;");
}

void MainWindow::on_BTN_MINIMIZE_released(){
    if(minimize_time.elapsed() > 1000){
        plog->write("[사용자 입력] 프로그램 최소화");
        showMinimized();
    }
    ui->BTN_MINIMIZE->setStyleSheet("font: 12pt \"함초롬돋움\"; background-color: #99FF99; border-radius: 10px; border: 0px solid #595959;");
}
