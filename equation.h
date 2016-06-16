#ifndef EQUATION_H
#define EQUATION_H

#include "coefficient.h"
#include <QWidget>
#include <vector>

class Equation
{
    public:
        Equation(int n, QWidget *f);
        ~Equation();
        std::vector<Coefficient> coefVector;

    //make private?
        Coefficient *x;
        Coefficient *y;
        Coefficient *z;
        Coefficient *c;
};

#endif // EQUATION_H
