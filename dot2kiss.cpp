#include "dot2kiss.h"
#include "ui_dot2kiss.h"

Dot2Kiss::Dot2Kiss(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dot2Kiss)
{
    ui->setupUi(this);
}

Dot2Kiss::~Dot2Kiss()
{
    delete ui;
}
