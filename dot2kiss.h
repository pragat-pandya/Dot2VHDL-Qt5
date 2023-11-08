#ifndef DOT2KISS_H
#define DOT2KISS_H

#include <QDialog>

namespace Ui {
class Dot2Kiss;
}

class Dot2Kiss : public QDialog
{
    Q_OBJECT

public:
    explicit Dot2Kiss(QWidget *parent = nullptr);
    ~Dot2Kiss();

private:
    Ui::Dot2Kiss *ui;
};

#endif // DOT2KISS_H
