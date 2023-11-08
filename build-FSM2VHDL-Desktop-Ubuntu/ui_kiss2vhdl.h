/********************************************************************************
** Form generated from reading UI file 'kiss2vhdl.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KISS2VHDL_H
#define UI_KISS2VHDL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Kiss2VHDL
{
public:
    QLabel *label;

    void setupUi(QDialog *Kiss2VHDL)
    {
        if (Kiss2VHDL->objectName().isEmpty())
            Kiss2VHDL->setObjectName(QString::fromUtf8("Kiss2VHDL"));
        Kiss2VHDL->resize(400, 300);
        label = new QLabel(Kiss2VHDL);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 140, 91, 31));

        retranslateUi(Kiss2VHDL);

        QMetaObject::connectSlotsByName(Kiss2VHDL);
    } // setupUi

    void retranslateUi(QDialog *Kiss2VHDL)
    {
        Kiss2VHDL->setWindowTitle(QCoreApplication::translate("Kiss2VHDL", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Kiss2VHDL", "Kiss2VHDL", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Kiss2VHDL: public Ui_Kiss2VHDL {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KISS2VHDL_H
