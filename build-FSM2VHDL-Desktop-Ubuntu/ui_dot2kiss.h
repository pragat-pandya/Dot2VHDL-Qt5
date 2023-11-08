/********************************************************************************
** Form generated from reading UI file 'dot2kiss.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOT2KISS_H
#define UI_DOT2KISS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Dot2Kiss
{
public:
    QLabel *label;

    void setupUi(QDialog *Dot2Kiss)
    {
        if (Dot2Kiss->objectName().isEmpty())
            Dot2Kiss->setObjectName(QString::fromUtf8("Dot2Kiss"));
        Dot2Kiss->resize(400, 300);
        label = new QLabel(Dot2Kiss);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 130, 67, 17));

        retranslateUi(Dot2Kiss);

        QMetaObject::connectSlotsByName(Dot2Kiss);
    } // setupUi

    void retranslateUi(QDialog *Dot2Kiss)
    {
        Dot2Kiss->setWindowTitle(QCoreApplication::translate("Dot2Kiss", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dot2Kiss", "Dot2Kiss", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dot2Kiss: public Ui_Dot2Kiss {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOT2KISS_H
