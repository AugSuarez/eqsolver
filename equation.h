#ifndef EQUATION_H
#define EQUATION_H

#include "coefficient.h"
#include <QWidget>
#include <vector>

class Equation
{
    public:
        Equation(int n, QWidget *w);
        Equation(Coefficient *xx, Coefficient *yy, Coefficient *zz, Coefficient *cc);
        Equation(std::vector<Coefficient> v);
        std::vector<Coefficient> coefVector;
        QString toString();
        QString toStringIso();

    //make private?
        Coefficient *x;
        Coefficient *y;
        Coefficient *z;
        Coefficient *c;
};

#endif // EQUATION_H
