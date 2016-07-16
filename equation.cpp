#include "equation.h"
#include "coefficient.h"
#include <QLineEdit>

Equation::Equation(int n, QWidget *w)
{
    this->x = new Coefficient(w->findChild<QLineEdit *>("x_" + QString::number(n))->text());
    this->y = new Coefficient(w->findChild<QLineEdit *>("y_" + QString::number(n))->text());
    this->z = new Coefficient(w->findChild<QLineEdit *>("z_" + QString::number(n))->text());
    this->c = new Coefficient(w->findChild<QLineEdit *>("c_" + QString::number(n))->text());

    coefVector.push_back(*x);
    coefVector.push_back(*y);
    coefVector.push_back(*z);
    coefVector.push_back(*c);
}

Equation::Equation(Coefficient *xx, Coefficient *yy, Coefficient *zz, Coefficient *cc) : x{xx}, y{yy}, z{zz}, c{cc}
{
    coefVector.push_back(*x);
    coefVector.push_back(*y);
    coefVector.push_back(*z);
    coefVector.push_back(*c);
}

Equation::Equation(std::vector<Coefficient> v) : coefVector{v}
{
    if(v.size()==4)
    {
        this->x = &v[0];
        this->y = &v[1];
        this->z = &v[2];
        this->c = &v[3];
    }
}

QString Equation::toString(){
    QString s;
    for(int i = 0; i<coefVector.size()-1; i++)
    {
        if(coefVector[i].numerInt > 0)
            s += "+";
        else
            s += coefVector[0].getFractionRep();
        switch (i) {
        case 0:
            s += "x";
            break;
        case 1:
            s += "y";
            break;
        case 2:
            s += "z";
            break;
        default:
            break;
        }
    }
    s += "c" + coefVector[coefVector.size()-1].getFractionRep();
    return s;
}

QString Equation::toStringIso(){
    QString s;
    s += "x" + coefVector[0].getFractionRep();
    for(int i = 1; i<coefVector.size(); i++)
    {
        if(coefVector[i].numerInt > 0)
            s += "+";
        else
            s += coefVector[0].getFractionRep();
        switch (i) {
        case 1:
            s += "x";
            break;
        case 2:
            s += "y";
            break;
        case 3:
            s += "z";
            break;
        default:
            break;
        }
    }
    return s;
}
