#ifndef EQUATION_H
#define EQUATION_H

#include "coefficient.h"
#include "eqsolver.h"
#include <vector>

class Equation
{
    public:
        Equation(QString xstr, QString ystr, QString zstr, QString cstr);
        ~Equation();
        std::vector<Coefficient> coefVector;

    //make private?
        Coefficient *x;
        Coefficient *y;
        Coefficient *z;
        Coefficient *c;
};

#endif // EQUATION_H
