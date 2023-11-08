#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dot2kiss.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::aboutQt(this, "About the TechStack");
}


void MainWindow::on_pushButton_3_clicked()
{
//    Dot2Kiss dot2kiss;
//    dot2kiss.setModal(true);
//    dot2kiss.exec();
//    hide();
//    d2k = new Dot2Kiss(this);
//    d2k->show();
}


void MainWindow::on_pushButton_5_clicked()
{
    hide();
    d2v = new Dot2VHDL(this);
    d2v->show();
}

