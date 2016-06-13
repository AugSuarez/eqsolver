#ifndef EQUATION_H
#define EQUATION_H

#include "coefficient.h"
#include "eqsolver.h"
#include <vector>

class Equation
{
    public:
        Equation(QString xstr, QString ystr, QString zstr);
        ~Equation();
        std::vector<Coefficient> coefVector;
        Coefficient *x;
        Coefficient *y;
        Coefficient *z;
};

#endif // EQUATION_H
