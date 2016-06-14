#include "equation.h"
#include "coefficient.h"
Equation::Equation(QString xstr, QString ystr, QString zstr, QString cstr)
{
    this->x = new Coefficient(xstr);
    this->y = new Coefficient(ystr);
    this->z = new Coefficient(zstr);
    this->c = new Coefficient(cstr);

//    this->y->fractionRep = ystr;
//    this->z->fractionRep = zstr;
    coefVector.push_back(*x);
    coefVector.push_back(*y);
    coefVector.push_back(*z);
    coefVector.push_back(*c);
}
