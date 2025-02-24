/********************************************************************************
** Form generated from reading UI file 'DialogInput.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGINPUT_H
#define UI_DIALOGINPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogInput
{
public:
    QPushButton *BTN_MENU_5;
    QPushButton *BTN_MENU_4;
    QPushButton *BTN_MENU_3;
    QLineEdit *LE_INPUT_SENSE;
    QPushButton *BTN_MENU_2;
    QPushButton *BTN_MENU_1;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QDialog *DialogInput)
    {
        if (DialogInput->objectName().isEmpty())
            DialogInput->setObjectName(QString::fromUtf8("DialogInput"));
        DialogInput->resize(301, 401);
        DialogInput->setStyleSheet(QString::fromUtf8("border: 0px solid #595959;\n"
"background-color: #ECDC26;\n"
"border-radius: 16px;\n"
""));
        BTN_MENU_5 = new QPushButton(DialogInput);
        BTN_MENU_5->setObjectName(QString::fromUtf8("BTN_MENU_5"));
        BTN_MENU_5->setGeometry(QRect(10, 320, 281, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font.setPointSize(18);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        BTN_MENU_5->setFont(font);
        BTN_MENU_5->setStyleSheet(QString::fromUtf8("font: 18pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"font-weight: bold;\n"
"background-color: #898989;\n"
"border-radius: 16px;"));
        BTN_MENU_4 = new QPushButton(DialogInput);
        BTN_MENU_4->setObjectName(QString::fromUtf8("BTN_MENU_4"));
        BTN_MENU_4->setGeometry(QRect(160, 200, 131, 101));
        BTN_MENU_4->setFont(font);
        BTN_MENU_4->setStyleSheet(QString::fromUtf8("font: 18pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"font-weight: bold;\n"
"background-color: #898989;\n"
"border-radius: 16px;"));
        BTN_MENU_3 = new QPushButton(DialogInput);
        BTN_MENU_3->setObjectName(QString::fromUtf8("BTN_MENU_3"));
        BTN_MENU_3->setGeometry(QRect(10, 200, 131, 101));
        BTN_MENU_3->setFont(font);
        BTN_MENU_3->setStyleSheet(QString::fromUtf8("font: 18pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"font-weight: bold;\n"
"background-color: #898989;\n"
"border-radius: 16px;"));
        LE_INPUT_SENSE = new QLineEdit(DialogInput);
        LE_INPUT_SENSE->setObjectName(QString::fromUtf8("LE_INPUT_SENSE"));
        LE_INPUT_SENSE->setGeometry(QRect(105, 20, 91, 41));
        LE_INPUT_SENSE->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"  background-color:lightyellow;\n"
"  font: 25pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\"; \n"
"  font-weight: bold;\n"
"  border-radius: 16px;\n"
"}\n"
""));
        LE_INPUT_SENSE->setAlignment(Qt::AlignCenter);
        LE_INPUT_SENSE->setReadOnly(true);
        BTN_MENU_2 = new QPushButton(DialogInput);
        BTN_MENU_2->setObjectName(QString::fromUtf8("BTN_MENU_2"));
        BTN_MENU_2->setGeometry(QRect(160, 80, 131, 101));
        BTN_MENU_2->setFont(font);
        BTN_MENU_2->setStyleSheet(QString::fromUtf8("font: 18pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"font-weight: bold;\n"
"background-color: #898989;\n"
"border-radius: 16px;"));
        BTN_MENU_1 = new QPushButton(DialogInput);
        BTN_MENU_1->setObjectName(QString::fromUtf8("BTN_MENU_1"));
        BTN_MENU_1->setGeometry(QRect(10, 80, 131, 101));
        BTN_MENU_1->setFont(font);
        BTN_MENU_1->setStyleSheet(QString::fromUtf8("font: 18pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"font-weight: bold;\n"
"background-color: #898989;\n"
"border-radius: 16px;"));
        label = new QLabel(DialogInput);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 15, 101, 51));
        label->setStyleSheet(QString::fromUtf8("font: 20pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"background-color: #FFFFFF;\n"
"border-radius: 20px"));
        label_2 = new QLabel(DialogInput);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(5, 75, 141, 111));
        label_2->setStyleSheet(QString::fromUtf8("font: 20pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"background-color: #FFFFFF;\n"
"border-radius: 20px"));
        label_3 = new QLabel(DialogInput);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(155, 75, 141, 111));
        label_3->setStyleSheet(QString::fromUtf8("font: 20pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"background-color: #FFFFFF;\n"
"border-radius: 20px"));
        label_4 = new QLabel(DialogInput);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(155, 195, 141, 111));
        label_4->setStyleSheet(QString::fromUtf8("font: 20pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"background-color: #FFFFFF;\n"
"border-radius: 20px"));
        label_5 = new QLabel(DialogInput);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(5, 195, 141, 111));
        label_5->setStyleSheet(QString::fromUtf8("font: 20pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"background-color: #FFFFFF;\n"
"border-radius: 20px"));
        label_6 = new QLabel(DialogInput);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(5, 315, 291, 71));
        label_6->setStyleSheet(QString::fromUtf8("font: 20pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"background-color: #FFFFFF;\n"
"border-radius: 20px"));
        label_6->raise();
        label_5->raise();
        label_4->raise();
        label_3->raise();
        label_2->raise();
        label->raise();
        BTN_MENU_5->raise();
        BTN_MENU_4->raise();
        BTN_MENU_3->raise();
        LE_INPUT_SENSE->raise();
        BTN_MENU_2->raise();
        BTN_MENU_1->raise();

        retranslateUi(DialogInput);

        QMetaObject::connectSlotsByName(DialogInput);
    } // setupUi

    void retranslateUi(QDialog *DialogInput)
    {
        DialogInput->setWindowTitle(QCoreApplication::translate("DialogInput", "Dialog", nullptr));
        BTN_MENU_5->setText(QCoreApplication::translate("DialogInput", "\353\257\270\354\240\225", nullptr));
        BTN_MENU_4->setText(QCoreApplication::translate("DialogInput", "\354\271\230\354\246\210\353\263\274", nullptr));
        BTN_MENU_3->setText(QCoreApplication::translate("DialogInput", "\352\260\220\354\236\220\355\212\200\352\271\200", nullptr));
        LE_INPUT_SENSE->setText(QString());
        BTN_MENU_2->setText(QCoreApplication::translate("DialogInput", "\353\274\210", nullptr));
        BTN_MENU_1->setText(QCoreApplication::translate("DialogInput", "\354\210\234\354\202\264", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogInput: public Ui_DialogInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGINPUT_H
