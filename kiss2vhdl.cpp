#include "kiss2vhdl.h"
#include "ui_kiss2vhdl.h"

Kiss2VHDL::Kiss2VHDL(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Kiss2VHDL)
{
    ui->setupUi(this);
}

Kiss2VHDL::~Kiss2VHDL()
{
    delete ui;
}
