/********************************************************************************
** Form generated from reading UI file 'DialogOutput.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGOUTPUT_H
#define UI_DIALOGOUTPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogOutput
{
public:
    QLineEdit *LE_MENU_NAME;

    void setupUi(QDialog *DialogOutput)
    {
        if (DialogOutput->objectName().isEmpty())
            DialogOutput->setObjectName(QString::fromUtf8("DialogOutput"));
        DialogOutput->resize(261, 321);
        DialogOutput->setStyleSheet(QString::fromUtf8("border: 0px solid #595959;\n"
"background-color: #60D88D;\n"
"border-radius: 16px;\n"
""));
        LE_MENU_NAME = new QLineEdit(DialogOutput);
        LE_MENU_NAME->setObjectName(QString::fromUtf8("LE_MENU_NAME"));
        LE_MENU_NAME->setGeometry(QRect(10, 10, 241, 301));
        QFont font;
        font.setFamily(QString::fromUtf8("\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200"));
        font.setPointSize(35);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        LE_MENU_NAME->setFont(font);
        LE_MENU_NAME->setStyleSheet(QString::fromUtf8("font: 35pt \"\355\225\250\354\264\210\353\241\254\353\217\213\354\233\200\";\n"
"font-weight: bold;"));
        LE_MENU_NAME->setAlignment(Qt::AlignCenter);
        LE_MENU_NAME->setReadOnly(true);

        retranslateUi(DialogOutput);

        QMetaObject::connectSlotsByName(DialogOutput);
    } // setupUi

    void retranslateUi(QDialog *DialogOutput)
    {
        DialogOutput->setWindowTitle(QCoreApplication::translate("DialogOutput", "Dialog", nullptr));
        LE_MENU_NAME->setText(QCoreApplication::translate("DialogOutput", "d", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogOutput: public Ui_DialogOutput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOUTPUT_H
