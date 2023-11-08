#include "dot2vhdl.h"
#include "ui_dot2vhdl.h"
#include "mainwindow.h"




Dot2VHDL::Dot2VHDL(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dot2VHDL)
{
    ui->setupUi(this);
}

Dot2VHDL::~Dot2VHDL()
{
    delete ui;
}

void Dot2VHDL::on_pushButton_clicked()
{
    hide();
    MainWindow *mainWindow = new MainWindow(this);
    mainWindow->show();
}


void Dot2VHDL::on_pushButton_2_clicked()
{
    QString dotInp = ui->plainTextEdit->toPlainText();
    Dot2KissConverter d2k;
    d2k.setInput(dotInp);
    d2k.isDotSyntaxValid();
    qDebug()<<d2k.isValid();
    if (!d2k.isValid()) {
            QMessageBox::critical(this, "Validation Result", "DOT syntax has errors. Please correct it and try again.");
    }
    else {
        QString kiss2Content = d2k.convertDotToKISS2();
        KISS2VHDL k2v;
        k2v.setKiss2Content(kiss2Content);
        QString vhdl = k2v.Kiss2VHDLConverter();
        ui->plainTextEdit->clear();
        ui->label->clear();
        ui->label->setText("Your Converted VHDL code is as following:");
        ui->plainTextEdit->appendPlainText(vhdl.toUtf8());

    }

}


