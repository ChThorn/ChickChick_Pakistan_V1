/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *FRAME_DEVICE;
    QFrame *MAIN_FRAME;
    QFrame *FRAME_OIL_1;
    QFrame *FRAME_FIRE_2;
    QFrame *FRAME_FIRE_1;
    QPushButton *BTN_FIRE_DEVICE_1;
    QLabel *LB_FRY_NUM_1;
    QPushButton *BTN_OIL_RESET_1;
    QFrame *FRAME_OIL_2;
    QFrame *FRAME_FIRE_4;
    QFrame *FRAME_FIRE_3;
    QPushButton *BTN_FIRE_DEVICE_2;
    QLabel *LB_FRY_NUM_2;
    QPushButton *BTN_OIL_RESET_2;
    QFrame *FRAME_INPUT_ALL;
    QPushButton *BTN_INPUT_DEVICE;
    QFrame *FRAME_INPUT_1;
    QFrame *FRAME_INPUT_2;
    QFrame *FRAME_INPUT_3;
    QFrame *FRAME_OUTPUT_ALL;
    QPushButton *BTN_OUTPUT_DEVICE;
    QFrame *FRAME_OUTPUT_2;
    QFrame *FRAME_OUTPUT_1;
    QLineEdit *LE_OUTPUT_SENSE;
    QLineEdit *LE_OUTPUT_SENSE_2;
    QFrame *FRAME_HISTORY;
    QPushButton *BTN_HISTORY_DEVICE;
    QLabel *LB_HISTORY_MENU_NAME_1;
    QLineEdit *LE_HISTORY_MENU_NUM_1;
    QLabel *LB_HISTORY_MENU_NAME_2;
    QLineEdit *LE_HISTORY_MENU_NUM_2;
    QLabel *LB_HISTORY_MENU_NAME_3;
    QLineEdit *LE_HISTORY_MENU_NUM_3;
    QLabel *LB_HISTORY_MENU_NAME_4;
    QLineEdit *LE_HISTORY_MENU_NUM_4;
    QLabel *LB_HISTORY_MENU_NAME_5;
    QLineEdit *LE_HISTORY_MENU_NUM_5;
    QLabel *LB_HISTORY_MENU_NAME_ALL;
    QLineEdit *LE_HISTORY_MENU_NUM_ALL;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QFrame *FRAME_HISTORY_SHADOW;
    QFrame *FRAME_HISTORY_SHADOW_2;
    QFrame *FRAME_HISTORY_SHADOW_3;
    QFrame *FRAME_HISTORY_SHADOW_4;
    QFrame *FRAME_HISTORY_SHADOW_13;
    QLabel *LB_LOGO;
    QPushButton *BTN_TEST_SEN_ON_4;
    QPushButton *BTN_TEST_SEN_ON_1;
    QPushButton *BTN_TEST_SEN_OFF_1;
    QPushButton *BTN_TEST_SEN_ON_5;
    QPushButton *BTN_TEST_SEN_OFF_4;
    QPushButton *BTN_TEST_SEN_OFF_2;
    QPushButton *BTN_TEST_SEN_OFF_3;
    QPushButton *BTN_TEST_SEN_ON_2;
    QPushButton *BTN_TEST_SEN_OFF_5;
    QPushButton *BTN_TEST_SEN_ON_3;
    QLabel *LB_OUTPUT_STATE;
    QLabel *LB_SHAKE_STATE;
    QLabel *LB_INPUT_STATE;
    QPushButton *BTN_EXIT;
    QPushButton *BTN_RESTART;
    QPushButton *BTN_MINIMIZE;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1920, 1100);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        FRAME_DEVICE = new QFrame(centralwidget);
        FRAME_DEVICE->setObjectName(QString::fromUtf8("FRAME_DEVICE"));
        FRAME_DEVICE->setGeometry(QRect(0, 0, 300, 690));
        FRAME_DEVICE->setStyleSheet(QString::fromUtf8("background-color: rgb(217, 217, 217);\n"
""));
        FRAME_DEVICE->setFrameShape(QFrame::NoFrame);
        FRAME_DEVICE->setFrameShadow(QFrame::Raised);
        MAIN_FRAME = new QFrame(centralwidget);
        MAIN_FRAME->setObjectName(QString::fromUtf8("MAIN_FRAME"));
        MAIN_FRAME->setGeometry(QRect(300, 0, 1621, 1071));
        MAIN_FRAME->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        MAIN_FRAME->setFrameShape(QFrame::StyledPanel);
        MAIN_FRAME->setFrameShadow(QFrame::Raised);
        FRAME_OIL_1 = new QFrame(MAIN_FRAME);
        FRAME_OIL_1->setObjectName(QString::fromUtf8("FRAME_OIL_1"));
        FRAME_OIL_1->setGeometry(QRect(30, 110, 561, 411));
        FRAME_OIL_1->setStyleSheet(QString::fromUtf8("QFrame { \n"
"   border: 0px solid #595959;\n"
"   background-color: #ECC6C6;\n"
"   border-radius:20px;\n"
"} \n"
"QLabel {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}\n"
"QPushButton {\n"
"	border:2px solid #595959;\n"
"	font: 25pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\"; \n"
"    font-weight: bold;\n"
"}\n"
"QLineEdit {\n"
"	font: 8pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}"));
        FRAME_OIL_1->setFrameShape(QFrame::Box);
        FRAME_OIL_1->setFrameShadow(QFrame::Raised);
        FRAME_OIL_1->setLineWidth(2);
        FRAME_FIRE_2 = new QFrame(FRAME_OIL_1);
        FRAME_FIRE_2->setObjectName(QString::fromUtf8("FRAME_FIRE_2"));
        FRAME_FIRE_2->setGeometry(QRect(290, 140, 261, 261));
        FRAME_FIRE_2->setStyleSheet(QString::fromUtf8("QFrame { \n"
"   border: 0px solid #595959;\n"
"   background-color: #FCA6A6;\n"
"   border-radius:16px;\n"
"} "));
        FRAME_FIRE_2->setFrameShape(QFrame::StyledPanel);
        FRAME_FIRE_2->setFrameShadow(QFrame::Raised);
        FRAME_FIRE_1 = new QFrame(FRAME_OIL_1);
        FRAME_FIRE_1->setObjectName(QString::fromUtf8("FRAME_FIRE_1"));
        FRAME_FIRE_1->setGeometry(QRect(10, 140, 261, 261));
        FRAME_FIRE_1->setStyleSheet(QString::fromUtf8("QFrame { \n"
"   border: 0px solid #595959;\n"
"   background-color: #FCA6A6;\n"
"   border-radius:16px;\n"
"} "));
        FRAME_FIRE_1->setFrameShape(QFrame::StyledPanel);
        FRAME_FIRE_1->setFrameShadow(QFrame::Raised);
        BTN_FIRE_DEVICE_1 = new QPushButton(FRAME_OIL_1);
        BTN_FIRE_DEVICE_1->setObjectName(QString::fromUtf8("BTN_FIRE_DEVICE_1"));
        BTN_FIRE_DEVICE_1->setGeometry(QRect(0, 0, 561, 70));
        QFont font;
        font.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font.setPointSize(25);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        BTN_FIRE_DEVICE_1->setFont(font);
        BTN_FIRE_DEVICE_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border:0px solid #595959;\n"
"	font: 25pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\"; \n"
"   font-weight: bold;\n"
"   background-color: #DC6666;\n"
"   border-top-left-radius: 20px; \n"
"   border-top-right-radius: 20px;\n"
"}"));
        LB_FRY_NUM_1 = new QLabel(FRAME_OIL_1);
        LB_FRY_NUM_1->setObjectName(QString::fromUtf8("LB_FRY_NUM_1"));
        LB_FRY_NUM_1->setGeometry(QRect(80, 80, 241, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font1.setPointSize(20);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        LB_FRY_NUM_1->setFont(font1);
        LB_FRY_NUM_1->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid;\n"
"   font: 20pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"} \n"
""));
        LB_FRY_NUM_1->setAlignment(Qt::AlignCenter);
        BTN_OIL_RESET_1 = new QPushButton(FRAME_OIL_1);
        BTN_OIL_RESET_1->setObjectName(QString::fromUtf8("BTN_OIL_RESET_1"));
        BTN_OIL_RESET_1->setGeometry(QRect(420, 80, 131, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        BTN_OIL_RESET_1->setFont(font2);
        BTN_OIL_RESET_1->setStyleSheet(QString::fromUtf8("font: 12pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"background-color: #999999;\n"
"border-radius: 10px;\n"
"border: 0px solid #595959;\n"
""));
        FRAME_OIL_2 = new QFrame(MAIN_FRAME);
        FRAME_OIL_2->setObjectName(QString::fromUtf8("FRAME_OIL_2"));
        FRAME_OIL_2->setGeometry(QRect(620, 110, 561, 411));
        FRAME_OIL_2->setStyleSheet(QString::fromUtf8("QFrame { \n"
"   border: 0px solid #595959;\n"
"   background-color: #ECC6C6;\n"
"   border-radius:20px;\n"
"} \n"
"QLabel {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}\n"
"QPushButton {\n"
"	border:2px solid #595959;\n"
"	font: 25pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\"; \n"
"    font-weight: bold;\n"
"}\n"
"QLineEdit {\n"
"	font: 8pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}"));
        FRAME_OIL_2->setFrameShape(QFrame::Box);
        FRAME_OIL_2->setFrameShadow(QFrame::Raised);
        FRAME_OIL_2->setLineWidth(2);
        FRAME_FIRE_4 = new QFrame(FRAME_OIL_2);
        FRAME_FIRE_4->setObjectName(QString::fromUtf8("FRAME_FIRE_4"));
        FRAME_FIRE_4->setGeometry(QRect(290, 140, 261, 261));
        FRAME_FIRE_4->setStyleSheet(QString::fromUtf8("QFrame { \n"
"   border: 0px solid #595959;\n"
"   background-color: #FCA6A6;\n"
"   border-radius:16px;\n"
"} "));
        FRAME_FIRE_4->setFrameShape(QFrame::StyledPanel);
        FRAME_FIRE_4->setFrameShadow(QFrame::Raised);
        FRAME_FIRE_3 = new QFrame(FRAME_OIL_2);
        FRAME_FIRE_3->setObjectName(QString::fromUtf8("FRAME_FIRE_3"));
        FRAME_FIRE_3->setGeometry(QRect(10, 140, 261, 261));
        FRAME_FIRE_3->setStyleSheet(QString::fromUtf8("QFrame { \n"
"   border: 0px solid #595959;\n"
"   background-color: #FCA6A6;\n"
"   border-radius:16px;\n"
"} "));
        FRAME_FIRE_3->setFrameShape(QFrame::StyledPanel);
        FRAME_FIRE_3->setFrameShadow(QFrame::Raised);
        BTN_FIRE_DEVICE_2 = new QPushButton(FRAME_OIL_2);
        BTN_FIRE_DEVICE_2->setObjectName(QString::fromUtf8("BTN_FIRE_DEVICE_2"));
        BTN_FIRE_DEVICE_2->setGeometry(QRect(0, 0, 561, 70));
        BTN_FIRE_DEVICE_2->setFont(font);
        BTN_FIRE_DEVICE_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border:0px solid #595959;\n"
"	font: 25pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\"; \n"
"   font-weight: bold;\n"
"   background-color: #DC6666;\n"
"   border-top-left-radius: 20px; \n"
"   border-top-right-radius: 20px;\n"
"}"));
        LB_FRY_NUM_2 = new QLabel(FRAME_OIL_2);
        LB_FRY_NUM_2->setObjectName(QString::fromUtf8("LB_FRY_NUM_2"));
        LB_FRY_NUM_2->setGeometry(QRect(70, 80, 241, 51));
        LB_FRY_NUM_2->setFont(font1);
        LB_FRY_NUM_2->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid;\n"
"   font: 20pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"} \n"
""));
        LB_FRY_NUM_2->setAlignment(Qt::AlignCenter);
        BTN_OIL_RESET_2 = new QPushButton(FRAME_OIL_2);
        BTN_OIL_RESET_2->setObjectName(QString::fromUtf8("BTN_OIL_RESET_2"));
        BTN_OIL_RESET_2->setGeometry(QRect(420, 80, 131, 51));
        BTN_OIL_RESET_2->setFont(font2);
        BTN_OIL_RESET_2->setStyleSheet(QString::fromUtf8("font: 12pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"background-color: #999999;\n"
"border-radius: 10px;\n"
"border: 0px solid #595959;\n"
""));
        FRAME_INPUT_ALL = new QFrame(MAIN_FRAME);
        FRAME_INPUT_ALL->setObjectName(QString::fromUtf8("FRAME_INPUT_ALL"));
        FRAME_INPUT_ALL->setGeometry(QRect(30, 550, 961, 491));
        FRAME_INPUT_ALL->setStyleSheet(QString::fromUtf8("QFrame { \n"
"   border: 0px solid #595959 ;\n"
"   background-color: #FFFF95;\n"
"   border-radius:20px;\n"
"} \n"
"QLabel {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}\n"
"\n"
"QLineEdit {\n"
"	font: 8pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}"));
        FRAME_INPUT_ALL->setFrameShape(QFrame::Box);
        FRAME_INPUT_ALL->setFrameShadow(QFrame::Raised);
        FRAME_INPUT_ALL->setLineWidth(2);
        BTN_INPUT_DEVICE = new QPushButton(FRAME_INPUT_ALL);
        BTN_INPUT_DEVICE->setObjectName(QString::fromUtf8("BTN_INPUT_DEVICE"));
        BTN_INPUT_DEVICE->setGeometry(QRect(0, 0, 961, 71));
        BTN_INPUT_DEVICE->setFont(font);
        BTN_INPUT_DEVICE->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border:0px solid #595959;\n"
"	font: 25pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\"; \n"
"   font-weight: bold;\n"
"   background-color: #CCAC36;\n"
"   border-top-left-radius: 20px; \n"
"   border-top-right-radius: 20px;\n"
"}"));
        FRAME_INPUT_1 = new QFrame(FRAME_INPUT_ALL);
        FRAME_INPUT_1->setObjectName(QString::fromUtf8("FRAME_INPUT_1"));
        FRAME_INPUT_1->setGeometry(QRect(10, 80, 301, 401));
        FRAME_INPUT_1->setStyleSheet(QString::fromUtf8("QFrame { \n"
"   border: 0px solid #595959;\n"
"   background-color: #ECDC26;\n"
"   border-radius:16px;\n"
"} "));
        FRAME_INPUT_1->setFrameShape(QFrame::Box);
        FRAME_INPUT_1->setFrameShadow(QFrame::Raised);
        FRAME_INPUT_1->setLineWidth(2);
        FRAME_INPUT_2 = new QFrame(FRAME_INPUT_ALL);
        FRAME_INPUT_2->setObjectName(QString::fromUtf8("FRAME_INPUT_2"));
        FRAME_INPUT_2->setGeometry(QRect(330, 80, 301, 401));
        FRAME_INPUT_2->setStyleSheet(QString::fromUtf8("QFrame { \n"
"   border: 0px solid #595959;\n"
"   background-color: #ECDC26;\n"
"   border-radius:16px;\n"
"} "));
        FRAME_INPUT_2->setFrameShape(QFrame::Box);
        FRAME_INPUT_2->setFrameShadow(QFrame::Raised);
        FRAME_INPUT_3 = new QFrame(FRAME_INPUT_ALL);
        FRAME_INPUT_3->setObjectName(QString::fromUtf8("FRAME_INPUT_3"));
        FRAME_INPUT_3->setGeometry(QRect(650, 80, 301, 401));
        FRAME_INPUT_3->setStyleSheet(QString::fromUtf8("QFrame { \n"
"   border: 0px solid #595959;\n"
"   background-color: #ECDC26;\n"
"   border-radius:16px;\n"
"} "));
        FRAME_INPUT_3->setFrameShape(QFrame::Box);
        FRAME_INPUT_3->setFrameShadow(QFrame::Raised);
        FRAME_OUTPUT_ALL = new QFrame(MAIN_FRAME);
        FRAME_OUTPUT_ALL->setObjectName(QString::fromUtf8("FRAME_OUTPUT_ALL"));
        FRAME_OUTPUT_ALL->setGeometry(QRect(1027, 550, 561, 491));
        FRAME_OUTPUT_ALL->setStyleSheet(QString::fromUtf8("QFrame { \n"
"   border: 0px solid #595959 ;\n"
"   background-color: #B5FFB5;\n"
"   border-radius:20px;\n"
"} \n"
"QLabel {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}\n"
"\n"
"QLineEdit {\n"
"	font: 8pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}"));
        FRAME_OUTPUT_ALL->setFrameShape(QFrame::Box);
        FRAME_OUTPUT_ALL->setFrameShadow(QFrame::Raised);
        FRAME_OUTPUT_ALL->setLineWidth(2);
        BTN_OUTPUT_DEVICE = new QPushButton(FRAME_OUTPUT_ALL);
        BTN_OUTPUT_DEVICE->setObjectName(QString::fromUtf8("BTN_OUTPUT_DEVICE"));
        BTN_OUTPUT_DEVICE->setGeometry(QRect(0, 0, 561, 71));
        BTN_OUTPUT_DEVICE->setFont(font);
        BTN_OUTPUT_DEVICE->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border:0px solid #595959;\n"
"	font: 25pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\"; \n"
"   font-weight: bold;\n"
"   background-color: #30A85D;\n"
"   border-top-left-radius: 20px; \n"
"   border-top-right-radius: 20px;\n"
"}"));
        FRAME_OUTPUT_2 = new QFrame(FRAME_OUTPUT_ALL);
        FRAME_OUTPUT_2->setObjectName(QString::fromUtf8("FRAME_OUTPUT_2"));
        FRAME_OUTPUT_2->setGeometry(QRect(290, 160, 261, 321));
        FRAME_OUTPUT_2->setStyleSheet(QString::fromUtf8("QFrame { \n"
"   border: 0px solid #595959;\n"
"   background-color: #60D88D;\n"
"   border-radius:16px;\n"
"} "));
        FRAME_OUTPUT_2->setFrameShape(QFrame::StyledPanel);
        FRAME_OUTPUT_2->setFrameShadow(QFrame::Raised);
        FRAME_OUTPUT_1 = new QFrame(FRAME_OUTPUT_ALL);
        FRAME_OUTPUT_1->setObjectName(QString::fromUtf8("FRAME_OUTPUT_1"));
        FRAME_OUTPUT_1->setGeometry(QRect(10, 160, 261, 321));
        FRAME_OUTPUT_1->setStyleSheet(QString::fromUtf8("QFrame { \n"
"   border: 0px solid #595959;\n"
"   background-color: #60D88D;\n"
"   border-radius:16px;\n"
"} "));
        FRAME_OUTPUT_1->setFrameShape(QFrame::StyledPanel);
        FRAME_OUTPUT_1->setFrameShadow(QFrame::Raised);
        LE_OUTPUT_SENSE = new QLineEdit(FRAME_OUTPUT_ALL);
        LE_OUTPUT_SENSE->setObjectName(QString::fromUtf8("LE_OUTPUT_SENSE"));
        LE_OUTPUT_SENSE->setGeometry(QRect(100, 90, 81, 51));
        LE_OUTPUT_SENSE->setStyleSheet(QString::fromUtf8("QLineEdit{ \n"
"   border: 0px solid;\n"
"   font: 15pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"   background-color:white;\n"
"  border-radius: 20px;\n"
"} \n"
""));
        LE_OUTPUT_SENSE->setAlignment(Qt::AlignCenter);
        LE_OUTPUT_SENSE->setReadOnly(true);
        LE_OUTPUT_SENSE_2 = new QLineEdit(FRAME_OUTPUT_ALL);
        LE_OUTPUT_SENSE_2->setObjectName(QString::fromUtf8("LE_OUTPUT_SENSE_2"));
        LE_OUTPUT_SENSE_2->setGeometry(QRect(380, 90, 81, 51));
        LE_OUTPUT_SENSE_2->setStyleSheet(QString::fromUtf8("QLineEdit{ \n"
"   border: 0px solid;\n"
"   font: 15pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"   background-color:white;\n"
"  border-radius: 20px;\n"
"} \n"
""));
        LE_OUTPUT_SENSE_2->setAlignment(Qt::AlignCenter);
        LE_OUTPUT_SENSE_2->setReadOnly(true);
        FRAME_HISTORY = new QFrame(MAIN_FRAME);
        FRAME_HISTORY->setObjectName(QString::fromUtf8("FRAME_HISTORY"));
        FRAME_HISTORY->setGeometry(QRect(1210, 110, 381, 411));
        FRAME_HISTORY->setStyleSheet(QString::fromUtf8("QFrame { \n"
"   border: 0px solid #595959 ;\n"
"   background-color: #95CFFF;\n"
"   border-radius:20px;\n"
"} \n"
"QLabel {\n"
"	font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}\n"
"\n"
"QLineEdit {\n"
"	font: 8pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"}"));
        FRAME_HISTORY->setFrameShape(QFrame::Box);
        FRAME_HISTORY->setFrameShadow(QFrame::Plain);
        FRAME_HISTORY->setLineWidth(2);
        BTN_HISTORY_DEVICE = new QPushButton(FRAME_HISTORY);
        BTN_HISTORY_DEVICE->setObjectName(QString::fromUtf8("BTN_HISTORY_DEVICE"));
        BTN_HISTORY_DEVICE->setGeometry(QRect(0, 0, 381, 70));
        BTN_HISTORY_DEVICE->setFont(font);
        BTN_HISTORY_DEVICE->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border:0px solid #595959;\n"
"	font: 25pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\"; \n"
"   font-weight: bold;\n"
"   background-color: #76A6CC;\n"
"   border-top-left-radius: 20px; \n"
"   border-top-right-radius: 20px;\n"
"}"));
        LB_HISTORY_MENU_NAME_1 = new QLabel(FRAME_HISTORY);
        LB_HISTORY_MENU_NAME_1->setObjectName(QString::fromUtf8("LB_HISTORY_MENU_NAME_1"));
        LB_HISTORY_MENU_NAME_1->setGeometry(QRect(40, 80, 161, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font3.setPointSize(18);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        LB_HISTORY_MENU_NAME_1->setFont(font3);
        LB_HISTORY_MENU_NAME_1->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid;\n"
"   font: 18pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"  color: white;\n"
"  background-color: #76A6DC;\n"
"  border-radius: 10px\n"
"} \n"
""));
        LB_HISTORY_MENU_NAME_1->setAlignment(Qt::AlignCenter);
        LE_HISTORY_MENU_NUM_1 = new QLineEdit(FRAME_HISTORY);
        LE_HISTORY_MENU_NUM_1->setObjectName(QString::fromUtf8("LE_HISTORY_MENU_NUM_1"));
        LE_HISTORY_MENU_NUM_1->setGeometry(QRect(180, 80, 171, 41));
        LE_HISTORY_MENU_NUM_1->setFont(font1);
        LE_HISTORY_MENU_NUM_1->setStyleSheet(QString::fromUtf8("font: 20pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"color: white;\n"
"background-color: #76A6DC;\n"
"border-radius: 10px\n"
""));
        LE_HISTORY_MENU_NUM_1->setAlignment(Qt::AlignCenter);
        LB_HISTORY_MENU_NAME_2 = new QLabel(FRAME_HISTORY);
        LB_HISTORY_MENU_NAME_2->setObjectName(QString::fromUtf8("LB_HISTORY_MENU_NAME_2"));
        LB_HISTORY_MENU_NAME_2->setGeometry(QRect(40, 130, 161, 41));
        LB_HISTORY_MENU_NAME_2->setFont(font3);
        LB_HISTORY_MENU_NAME_2->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid;\n"
"   font: 18pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"  color: white;\n"
"  background-color: #76A6DC;\n"
"  border-radius: 10px\n"
"} \n"
""));
        LB_HISTORY_MENU_NAME_2->setAlignment(Qt::AlignCenter);
        LE_HISTORY_MENU_NUM_2 = new QLineEdit(FRAME_HISTORY);
        LE_HISTORY_MENU_NUM_2->setObjectName(QString::fromUtf8("LE_HISTORY_MENU_NUM_2"));
        LE_HISTORY_MENU_NUM_2->setGeometry(QRect(180, 130, 171, 41));
        LE_HISTORY_MENU_NUM_2->setFont(font1);
        LE_HISTORY_MENU_NUM_2->setStyleSheet(QString::fromUtf8("font: 20pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"color: white;\n"
"background-color: #76A6DC;\n"
"border-radius: 10px\n"
""));
        LE_HISTORY_MENU_NUM_2->setAlignment(Qt::AlignCenter);
        LB_HISTORY_MENU_NAME_3 = new QLabel(FRAME_HISTORY);
        LB_HISTORY_MENU_NAME_3->setObjectName(QString::fromUtf8("LB_HISTORY_MENU_NAME_3"));
        LB_HISTORY_MENU_NAME_3->setGeometry(QRect(40, 180, 161, 41));
        LB_HISTORY_MENU_NAME_3->setFont(font3);
        LB_HISTORY_MENU_NAME_3->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid;\n"
"   font: 18pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"  color: white;\n"
"  background-color: #76A6DC;\n"
"  border-radius: 10px\n"
"} \n"
""));
        LB_HISTORY_MENU_NAME_3->setAlignment(Qt::AlignCenter);
        LE_HISTORY_MENU_NUM_3 = new QLineEdit(FRAME_HISTORY);
        LE_HISTORY_MENU_NUM_3->setObjectName(QString::fromUtf8("LE_HISTORY_MENU_NUM_3"));
        LE_HISTORY_MENU_NUM_3->setGeometry(QRect(180, 180, 171, 41));
        LE_HISTORY_MENU_NUM_3->setFont(font1);
        LE_HISTORY_MENU_NUM_3->setStyleSheet(QString::fromUtf8("font: 20pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"color: white;\n"
"background-color: #76A6DC;\n"
"border-radius: 10px\n"
""));
        LE_HISTORY_MENU_NUM_3->setAlignment(Qt::AlignCenter);
        LB_HISTORY_MENU_NAME_4 = new QLabel(FRAME_HISTORY);
        LB_HISTORY_MENU_NAME_4->setObjectName(QString::fromUtf8("LB_HISTORY_MENU_NAME_4"));
        LB_HISTORY_MENU_NAME_4->setGeometry(QRect(40, 230, 161, 41));
        LB_HISTORY_MENU_NAME_4->setFont(font3);
        LB_HISTORY_MENU_NAME_4->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid;\n"
"   font: 18pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"  color: white;\n"
"  background-color: #76A6DC;\n"
"  border-radius: 10px\n"
"} \n"
""));
        LB_HISTORY_MENU_NAME_4->setAlignment(Qt::AlignCenter);
        LE_HISTORY_MENU_NUM_4 = new QLineEdit(FRAME_HISTORY);
        LE_HISTORY_MENU_NUM_4->setObjectName(QString::fromUtf8("LE_HISTORY_MENU_NUM_4"));
        LE_HISTORY_MENU_NUM_4->setGeometry(QRect(180, 230, 171, 41));
        LE_HISTORY_MENU_NUM_4->setFont(font1);
        LE_HISTORY_MENU_NUM_4->setStyleSheet(QString::fromUtf8("font: 20pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"color: white;\n"
"background-color: #76A6DC;\n"
"border-radius: 10px\n"
""));
        LE_HISTORY_MENU_NUM_4->setAlignment(Qt::AlignCenter);
        LB_HISTORY_MENU_NAME_5 = new QLabel(FRAME_HISTORY);
        LB_HISTORY_MENU_NAME_5->setObjectName(QString::fromUtf8("LB_HISTORY_MENU_NAME_5"));
        LB_HISTORY_MENU_NAME_5->setGeometry(QRect(40, 280, 161, 41));
        LB_HISTORY_MENU_NAME_5->setFont(font3);
        LB_HISTORY_MENU_NAME_5->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid;\n"
"   font: 18pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"  color: white;\n"
"  background-color: #76A6DC;\n"
"  border-radius: 10px\n"
"} \n"
""));
        LB_HISTORY_MENU_NAME_5->setAlignment(Qt::AlignCenter);
        LE_HISTORY_MENU_NUM_5 = new QLineEdit(FRAME_HISTORY);
        LE_HISTORY_MENU_NUM_5->setObjectName(QString::fromUtf8("LE_HISTORY_MENU_NUM_5"));
        LE_HISTORY_MENU_NUM_5->setGeometry(QRect(180, 280, 171, 41));
        LE_HISTORY_MENU_NUM_5->setFont(font1);
        LE_HISTORY_MENU_NUM_5->setStyleSheet(QString::fromUtf8("font: 20pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"color: white;\n"
"background-color: #76A6DC;\n"
"border-radius: 10px\n"
""));
        LE_HISTORY_MENU_NUM_5->setAlignment(Qt::AlignCenter);
        LB_HISTORY_MENU_NAME_ALL = new QLabel(FRAME_HISTORY);
        LB_HISTORY_MENU_NAME_ALL->setObjectName(QString::fromUtf8("LB_HISTORY_MENU_NAME_ALL"));
        LB_HISTORY_MENU_NAME_ALL->setGeometry(QRect(40, 340, 161, 51));
        LB_HISTORY_MENU_NAME_ALL->setFont(font1);
        LB_HISTORY_MENU_NAME_ALL->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid;\n"
"   font: 20pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"  color: white;\n"
"  background-color: #76DCA6;\n"
"  border-radius: 10px\n"
"} \n"
""));
        LB_HISTORY_MENU_NAME_ALL->setAlignment(Qt::AlignCenter);
        LE_HISTORY_MENU_NUM_ALL = new QLineEdit(FRAME_HISTORY);
        LE_HISTORY_MENU_NUM_ALL->setObjectName(QString::fromUtf8("LE_HISTORY_MENU_NUM_ALL"));
        LE_HISTORY_MENU_NUM_ALL->setGeometry(QRect(180, 340, 171, 51));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font4.setPointSize(28);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(50);
        LE_HISTORY_MENU_NUM_ALL->setFont(font4);
        LE_HISTORY_MENU_NUM_ALL->setStyleSheet(QString::fromUtf8("font: 28pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"color: white;\n"
"background-color: #76DCA6;\n"
"border-radius: 10px"));
        LE_HISTORY_MENU_NUM_ALL->setAlignment(Qt::AlignCenter);
        label = new QLabel(FRAME_HISTORY);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(35, 335, 321, 61));
        label->setStyleSheet(QString::fromUtf8("font: 20pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"background-color: #FFFFFF;\n"
"border-radius: 14px"));
        label_3 = new QLabel(FRAME_HISTORY);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(37, 277, 317, 47));
        label_3->setStyleSheet(QString::fromUtf8("font: 20pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"background-color: #D4D4D4;\n"
"border-radius: 14px   "));
        label_4 = new QLabel(FRAME_HISTORY);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(37, 227, 317, 47));
        label_4->setStyleSheet(QString::fromUtf8("font: 20pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"background-color: #D4D4D4;\n"
"border-radius: 14px   "));
        label_5 = new QLabel(FRAME_HISTORY);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(37, 177, 317, 47));
        label_5->setStyleSheet(QString::fromUtf8("font: 20pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"background-color: #D4D4D4;\n"
"border-radius: 14px   "));
        label_6 = new QLabel(FRAME_HISTORY);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(37, 127, 317, 47));
        label_6->setStyleSheet(QString::fromUtf8("font: 20pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"background-color: #D4D4D4;\n"
"border-radius: 14px   "));
        label_7 = new QLabel(FRAME_HISTORY);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(37, 77, 317, 47));
        label_7->setStyleSheet(QString::fromUtf8("font: 20pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"background-color: #D4D4D4;\n"
"border-radius: 14px   "));
        label_5->raise();
        label_6->raise();
        label_7->raise();
        label_4->raise();
        label_3->raise();
        label->raise();
        BTN_HISTORY_DEVICE->raise();
        LE_HISTORY_MENU_NUM_1->raise();
        LB_HISTORY_MENU_NAME_2->raise();
        LE_HISTORY_MENU_NUM_2->raise();
        LB_HISTORY_MENU_NAME_3->raise();
        LE_HISTORY_MENU_NUM_3->raise();
        LB_HISTORY_MENU_NAME_4->raise();
        LE_HISTORY_MENU_NUM_4->raise();
        LB_HISTORY_MENU_NAME_5->raise();
        LE_HISTORY_MENU_NUM_5->raise();
        LB_HISTORY_MENU_NAME_ALL->raise();
        LE_HISTORY_MENU_NUM_ALL->raise();
        LB_HISTORY_MENU_NAME_1->raise();
        FRAME_HISTORY_SHADOW = new QFrame(MAIN_FRAME);
        FRAME_HISTORY_SHADOW->setObjectName(QString::fromUtf8("FRAME_HISTORY_SHADOW"));
        FRAME_HISTORY_SHADOW->setGeometry(QRect(1213, 113, 381, 411));
        FRAME_HISTORY_SHADOW->setStyleSheet(QString::fromUtf8("QFrame { \n"
"   border: 0px solid #595959 ;\n"
"   background-color: #B4B4B4;\n"
"   border-radius:20px;\n"
"} \n"
""));
        FRAME_HISTORY_SHADOW->setFrameShape(QFrame::Box);
        FRAME_HISTORY_SHADOW->setFrameShadow(QFrame::Plain);
        FRAME_HISTORY_SHADOW->setLineWidth(2);
        FRAME_HISTORY_SHADOW_2 = new QFrame(MAIN_FRAME);
        FRAME_HISTORY_SHADOW_2->setObjectName(QString::fromUtf8("FRAME_HISTORY_SHADOW_2"));
        FRAME_HISTORY_SHADOW_2->setGeometry(QRect(623, 113, 561, 411));
        FRAME_HISTORY_SHADOW_2->setStyleSheet(QString::fromUtf8("QFrame { \n"
"   border: 0px solid #595959 ;\n"
"   background-color: #B4B4B4;\n"
"   border-radius:20px;\n"
"} \n"
""));
        FRAME_HISTORY_SHADOW_2->setFrameShape(QFrame::Box);
        FRAME_HISTORY_SHADOW_2->setFrameShadow(QFrame::Plain);
        FRAME_HISTORY_SHADOW_2->setLineWidth(2);
        FRAME_HISTORY_SHADOW_3 = new QFrame(MAIN_FRAME);
        FRAME_HISTORY_SHADOW_3->setObjectName(QString::fromUtf8("FRAME_HISTORY_SHADOW_3"));
        FRAME_HISTORY_SHADOW_3->setGeometry(QRect(33, 113, 561, 411));
        FRAME_HISTORY_SHADOW_3->setStyleSheet(QString::fromUtf8("QFrame { \n"
"   border: 0px solid #595959 ;\n"
"   background-color: #B4B4B4;\n"
"   border-radius:20px;\n"
"} \n"
""));
        FRAME_HISTORY_SHADOW_3->setFrameShape(QFrame::Box);
        FRAME_HISTORY_SHADOW_3->setFrameShadow(QFrame::Plain);
        FRAME_HISTORY_SHADOW_3->setLineWidth(2);
        FRAME_HISTORY_SHADOW_4 = new QFrame(MAIN_FRAME);
        FRAME_HISTORY_SHADOW_4->setObjectName(QString::fromUtf8("FRAME_HISTORY_SHADOW_4"));
        FRAME_HISTORY_SHADOW_4->setGeometry(QRect(33, 553, 961, 491));
        FRAME_HISTORY_SHADOW_4->setStyleSheet(QString::fromUtf8("QFrame { \n"
"   border: 0px solid #595959 ;\n"
"   background-color: #B4B4B4;\n"
"   border-radius:20px;\n"
"} \n"
""));
        FRAME_HISTORY_SHADOW_4->setFrameShape(QFrame::Box);
        FRAME_HISTORY_SHADOW_4->setFrameShadow(QFrame::Plain);
        FRAME_HISTORY_SHADOW_4->setLineWidth(2);
        FRAME_HISTORY_SHADOW_13 = new QFrame(MAIN_FRAME);
        FRAME_HISTORY_SHADOW_13->setObjectName(QString::fromUtf8("FRAME_HISTORY_SHADOW_13"));
        FRAME_HISTORY_SHADOW_13->setGeometry(QRect(1030, 553, 561, 491));
        FRAME_HISTORY_SHADOW_13->setStyleSheet(QString::fromUtf8("QFrame { \n"
"   border: 0px solid #595959 ;\n"
"   background-color: #B4B4B4;\n"
"   border-radius:20px;\n"
"} \n"
""));
        FRAME_HISTORY_SHADOW_13->setFrameShape(QFrame::Box);
        FRAME_HISTORY_SHADOW_13->setFrameShadow(QFrame::Plain);
        FRAME_HISTORY_SHADOW_13->setLineWidth(2);
        LB_LOGO = new QLabel(MAIN_FRAME);
        LB_LOGO->setObjectName(QString::fromUtf8("LB_LOGO"));
        LB_LOGO->setGeometry(QRect(0, 0, 1621, 91));
        LB_LOGO->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        FRAME_HISTORY_SHADOW_13->raise();
        FRAME_HISTORY_SHADOW_4->raise();
        FRAME_HISTORY_SHADOW_3->raise();
        FRAME_HISTORY_SHADOW_2->raise();
        FRAME_HISTORY_SHADOW->raise();
        FRAME_OIL_1->raise();
        FRAME_OIL_2->raise();
        FRAME_INPUT_ALL->raise();
        FRAME_OUTPUT_ALL->raise();
        FRAME_HISTORY->raise();
        LB_LOGO->raise();
        BTN_TEST_SEN_ON_4 = new QPushButton(centralwidget);
        BTN_TEST_SEN_ON_4->setObjectName(QString::fromUtf8("BTN_TEST_SEN_ON_4"));
        BTN_TEST_SEN_ON_4->setGeometry(QRect(10, 710, 89, 35));
        BTN_TEST_SEN_ON_1 = new QPushButton(centralwidget);
        BTN_TEST_SEN_ON_1->setObjectName(QString::fromUtf8("BTN_TEST_SEN_ON_1"));
        BTN_TEST_SEN_ON_1->setGeometry(QRect(10, 890, 89, 35));
        BTN_TEST_SEN_OFF_1 = new QPushButton(centralwidget);
        BTN_TEST_SEN_OFF_1->setObjectName(QString::fromUtf8("BTN_TEST_SEN_OFF_1"));
        BTN_TEST_SEN_OFF_1->setGeometry(QRect(10, 930, 89, 35));
        BTN_TEST_SEN_ON_5 = new QPushButton(centralwidget);
        BTN_TEST_SEN_ON_5->setObjectName(QString::fromUtf8("BTN_TEST_SEN_ON_5"));
        BTN_TEST_SEN_ON_5->setGeometry(QRect(110, 710, 89, 35));
        BTN_TEST_SEN_OFF_4 = new QPushButton(centralwidget);
        BTN_TEST_SEN_OFF_4->setObjectName(QString::fromUtf8("BTN_TEST_SEN_OFF_4"));
        BTN_TEST_SEN_OFF_4->setGeometry(QRect(10, 750, 89, 35));
        BTN_TEST_SEN_OFF_2 = new QPushButton(centralwidget);
        BTN_TEST_SEN_OFF_2->setObjectName(QString::fromUtf8("BTN_TEST_SEN_OFF_2"));
        BTN_TEST_SEN_OFF_2->setGeometry(QRect(110, 930, 89, 35));
        BTN_TEST_SEN_OFF_3 = new QPushButton(centralwidget);
        BTN_TEST_SEN_OFF_3->setObjectName(QString::fromUtf8("BTN_TEST_SEN_OFF_3"));
        BTN_TEST_SEN_OFF_3->setGeometry(QRect(210, 930, 89, 35));
        BTN_TEST_SEN_ON_2 = new QPushButton(centralwidget);
        BTN_TEST_SEN_ON_2->setObjectName(QString::fromUtf8("BTN_TEST_SEN_ON_2"));
        BTN_TEST_SEN_ON_2->setGeometry(QRect(110, 890, 89, 35));
        BTN_TEST_SEN_OFF_5 = new QPushButton(centralwidget);
        BTN_TEST_SEN_OFF_5->setObjectName(QString::fromUtf8("BTN_TEST_SEN_OFF_5"));
        BTN_TEST_SEN_OFF_5->setGeometry(QRect(110, 750, 89, 35));
        BTN_TEST_SEN_ON_3 = new QPushButton(centralwidget);
        BTN_TEST_SEN_ON_3->setObjectName(QString::fromUtf8("BTN_TEST_SEN_ON_3"));
        BTN_TEST_SEN_ON_3->setGeometry(QRect(210, 890, 89, 35));
        LB_OUTPUT_STATE = new QLabel(centralwidget);
        LB_OUTPUT_STATE->setObjectName(QString::fromUtf8("LB_OUTPUT_STATE"));
        LB_OUTPUT_STATE->setGeometry(QRect(20, 800, 241, 17));
        LB_SHAKE_STATE = new QLabel(centralwidget);
        LB_SHAKE_STATE->setObjectName(QString::fromUtf8("LB_SHAKE_STATE"));
        LB_SHAKE_STATE->setGeometry(QRect(20, 830, 241, 17));
        LB_INPUT_STATE = new QLabel(centralwidget);
        LB_INPUT_STATE->setObjectName(QString::fromUtf8("LB_INPUT_STATE"));
        LB_INPUT_STATE->setGeometry(QRect(20, 860, 241, 17));
        BTN_EXIT = new QPushButton(centralwidget);
        BTN_EXIT->setObjectName(QString::fromUtf8("BTN_EXIT"));
        BTN_EXIT->setGeometry(QRect(10, 980, 91, 61));
        BTN_EXIT->setStyleSheet(QString::fromUtf8("font: 12pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"background-color: #FF9999;\n"
"border-radius: 10px;\n"
"border: 0px solid #595959;\n"
""));
        BTN_RESTART = new QPushButton(centralwidget);
        BTN_RESTART->setObjectName(QString::fromUtf8("BTN_RESTART"));
        BTN_RESTART->setGeometry(QRect(110, 980, 91, 61));
        BTN_RESTART->setStyleSheet(QString::fromUtf8("font: 12pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"background-color: #9999FF;\n"
"border-radius: 10px;\n"
"border: 0px solid #595959;\n"
""));
        BTN_MINIMIZE = new QPushButton(centralwidget);
        BTN_MINIMIZE->setObjectName(QString::fromUtf8("BTN_MINIMIZE"));
        BTN_MINIMIZE->setGeometry(QRect(210, 980, 81, 61));
        BTN_MINIMIZE->setStyleSheet(QString::fromUtf8("font: 12pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"background-color: #99FF99;\n"
"border-radius: 10px;\n"
"border: 0px solid #595959;\n"
""));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1920, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "We-ing Chicken", nullptr));
        BTN_FIRE_DEVICE_1->setText(QCoreApplication::translate("MainWindow", "Cooking 1", nullptr));
        LB_FRY_NUM_1->setText(QString());
        BTN_OIL_RESET_1->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        BTN_FIRE_DEVICE_2->setText(QCoreApplication::translate("MainWindow", "Cooking 2", nullptr));
        LB_FRY_NUM_2->setText(QString());
        BTN_OIL_RESET_2->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        BTN_INPUT_DEVICE->setText(QCoreApplication::translate("MainWindow", "Order Menu", nullptr));
        BTN_OUTPUT_DEVICE->setText(QCoreApplication::translate("MainWindow", "Finished Cooking", nullptr));
        LE_OUTPUT_SENSE->setText(QCoreApplication::translate("MainWindow", "#1", nullptr));
        LE_OUTPUT_SENSE_2->setText(QCoreApplication::translate("MainWindow", "#2", nullptr));
        BTN_HISTORY_DEVICE->setText(QCoreApplication::translate("MainWindow", "Completed Menu", nullptr));
        LB_HISTORY_MENU_NAME_1->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        LB_HISTORY_MENU_NAME_2->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        LB_HISTORY_MENU_NAME_3->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        LB_HISTORY_MENU_NAME_4->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        LB_HISTORY_MENU_NAME_5->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        LB_HISTORY_MENU_NAME_ALL->setText(QCoreApplication::translate("MainWindow", "Total", nullptr));
        label->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        label_7->setText(QString());
        LB_LOGO->setText(QString());
        BTN_TEST_SEN_ON_4->setText(QCoreApplication::translate("MainWindow", "Sen 4 On", nullptr));
        BTN_TEST_SEN_ON_1->setText(QCoreApplication::translate("MainWindow", "Sen 0 On", nullptr));
        BTN_TEST_SEN_OFF_1->setText(QCoreApplication::translate("MainWindow", "Sen 0 Off", nullptr));
        BTN_TEST_SEN_ON_5->setText(QCoreApplication::translate("MainWindow", "Sen 5 On", nullptr));
        BTN_TEST_SEN_OFF_4->setText(QCoreApplication::translate("MainWindow", "Sen 4 Off", nullptr));
        BTN_TEST_SEN_OFF_2->setText(QCoreApplication::translate("MainWindow", "Sen 1 Off", nullptr));
        BTN_TEST_SEN_OFF_3->setText(QCoreApplication::translate("MainWindow", "Sen 2 Off", nullptr));
        BTN_TEST_SEN_ON_2->setText(QCoreApplication::translate("MainWindow", "Sen 1 On", nullptr));
        BTN_TEST_SEN_OFF_5->setText(QCoreApplication::translate("MainWindow", "Sen 5 Off", nullptr));
        BTN_TEST_SEN_ON_3->setText(QCoreApplication::translate("MainWindow", "Sen 2 On", nullptr));
        LB_OUTPUT_STATE->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        LB_SHAKE_STATE->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        LB_INPUT_STATE->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        BTN_EXIT->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        BTN_RESTART->setText(QCoreApplication::translate("MainWindow", "Restart", nullptr));
        BTN_MINIMIZE->setText(QCoreApplication::translate("MainWindow", "Minimize", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
