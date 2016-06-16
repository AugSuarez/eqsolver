#include "equation.h"
#include "coefficient.h"
#include <QLineEdit>

Equation::Equation(int n, QWidget *f)
{
    this->x = new Coefficient(f->findChild<QLineEdit *>("x_" + QString::number(n))->text());
    this->y = new Coefficient(f->findChild<QLineEdit *>("y_" + QString::number(n))->text());
    this->z = new Coefficient(f->findChild<QLineEdit *>("z_" + QString::number(n))->text());
    this->c = new Coefficient(f->findChild<QLineEdit *>("c_" + QString::number(n))->text());

    coefVector.push_back(*x);
    coefVector.push_back(*y);
    coefVector.push_back(*z);
    coefVector.push_back(*c);
}
