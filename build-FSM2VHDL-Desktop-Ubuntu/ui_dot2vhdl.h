/********************************************************************************
** Form generated from reading UI file 'dot2vhdl.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOT2VHDL_H
#define UI_DOT2VHDL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_Dot2VHDL
{
public:
    QPushButton *pushButton;
    QSplitter *splitter;
    QLabel *label;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Dot2VHDL)
    {
        if (Dot2VHDL->objectName().isEmpty())
            Dot2VHDL->setObjectName(QString::fromUtf8("Dot2VHDL"));
        pushButton = new QPushButton(Dot2VHDL);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 89, 25));
        splitter = new QSplitter(Dot2VHDL);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(80, 40, 751, 751));
        splitter->setOrientation(Qt::Vertical);
        label = new QLabel(splitter);
        label->setObjectName(QString::fromUtf8("label"));
        splitter->addWidget(label);
        plainTextEdit = new QPlainTextEdit(splitter);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        splitter->addWidget(plainTextEdit);
        pushButton_2 = new QPushButton(splitter);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        splitter->addWidget(pushButton_2);

        retranslateUi(Dot2VHDL);

        QMetaObject::connectSlotsByName(Dot2VHDL);
    } // setupUi

    void retranslateUi(QDialog *Dot2VHDL)
    {
        Dot2VHDL->setWindowTitle(QCoreApplication::translate("Dot2VHDL", "Dot Input", nullptr));
        pushButton->setText(QCoreApplication::translate("Dot2VHDL", "<-- Back", nullptr));
        label->setText(QCoreApplication::translate("Dot2VHDL", "Input .dot code for FSM in following textbox:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Dot2VHDL", "Convert To VHDL", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dot2VHDL: public Ui_Dot2VHDL {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOT2VHDL_H
