/********************************************************************************
** Form generated from reading UI file 'DialogFire.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGFIRE_H
#define UI_DIALOGFIRE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogFire
{
public:
    QPushButton *BTN_FORCED_STOP;
    QLabel *LB_POINT;
    QProgressBar *PB_PROGRESS;
    QLineEdit *LE_MENU;
    QLabel *LB_BASKET_NAME;

    void setupUi(QDialog *DialogFire)
    {
        if (DialogFire->objectName().isEmpty())
            DialogFire->setObjectName(QString::fromUtf8("DialogFire"));
        DialogFire->resize(261, 261);
        DialogFire->setStyleSheet(QString::fromUtf8("border: 0px solid #595959;\n"
"background-color: #FCA6A6;\n"
"border-radius: 16px;\n"
""));
        BTN_FORCED_STOP = new QPushButton(DialogFire);
        BTN_FORCED_STOP->setObjectName(QString::fromUtf8("BTN_FORCED_STOP"));
        BTN_FORCED_STOP->setGeometry(QRect(10, 220, 241, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        BTN_FORCED_STOP->setFont(font);
        BTN_FORCED_STOP->setStyleSheet(QString::fromUtf8("font: 10pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"background-color: #999999;\n"
"border-radius: 10px;"));
        LB_POINT = new QLabel(DialogFire);
        LB_POINT->setObjectName(QString::fromUtf8("LB_POINT"));
        LB_POINT->setGeometry(QRect(10, 150, 241, 20));
        LB_POINT->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid\n"
"} "));
        PB_PROGRESS = new QProgressBar(DialogFire);
        PB_PROGRESS->setObjectName(QString::fromUtf8("PB_PROGRESS"));
        PB_PROGRESS->setGeometry(QRect(10, 170, 241, 41));
        QFont font1;
        font1.setPointSize(13);
        PB_PROGRESS->setFont(font1);
        PB_PROGRESS->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"     border: 2px solid grey;\n"
"     border-radius: 5px;\n"
"     text-align: center;\n"
" }\n"
"\n"
" QProgressBar::chunk {\n"
"     background-color: #FFFFFF;\n"
"     border-radius: 5px;\n"
" }"));
        PB_PROGRESS->setValue(24);
        LE_MENU = new QLineEdit(DialogFire);
        LE_MENU->setObjectName(QString::fromUtf8("LE_MENU"));
        LE_MENU->setGeometry(QRect(10, 70, 241, 71));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font2.setPointSize(25);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        LE_MENU->setFont(font2);
        LE_MENU->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"  background-color:lightyellow;\n"
"  font: 25pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\"; \n"
"  font-weight: bold;\n"
"}"));
        LE_MENU->setAlignment(Qt::AlignCenter);
        LE_MENU->setReadOnly(true);
        LB_BASKET_NAME = new QLabel(DialogFire);
        LB_BASKET_NAME->setObjectName(QString::fromUtf8("LB_BASKET_NAME"));
        LB_BASKET_NAME->setGeometry(QRect(100, 10, 61, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font3.setPointSize(15);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        LB_BASKET_NAME->setFont(font3);
        LB_BASKET_NAME->setStyleSheet(QString::fromUtf8("QLabel{ \n"
"   border: 0px solid;\n"
"   font: 15pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"   background-color:white;\n"
"  border-radius: 20px;\n"
"} \n"
""));
        LB_BASKET_NAME->setAlignment(Qt::AlignCenter);

        retranslateUi(DialogFire);

        QMetaObject::connectSlotsByName(DialogFire);
    } // setupUi

    void retranslateUi(QDialog *DialogFire)
    {
        DialogFire->setWindowTitle(QCoreApplication::translate("DialogFire", "Dialog", nullptr));
        BTN_FORCED_STOP->setText(QCoreApplication::translate("DialogFire", "\352\260\225\354\240\234\354\242\205\353\243\214", nullptr));
        LB_POINT->setText(QString());
        LE_MENU->setText(QString());
        LB_BASKET_NAME->setText(QCoreApplication::translate("DialogFire", "#1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogFire: public Ui_DialogFire {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGFIRE_H
