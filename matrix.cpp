#include "matrix.h"
#include "ui_eqsolver.h"
#include "eqsolver.h"
void Matrix::makeLinear(int i, std::vector<Coefficient>& v)
{
    for(i = 0; i<v.size(); i++)
    {
        v[i].numerInt = i*eq1->x->numerInt/eq1->x->denomInt;
        v[i].denomInt = eq1->x->denomInt/eq1->x->denomInt;
    }
    return;
}

Equation Matrix::isolateVar(Coefficient isoVar, std::vector<Coefficient>& v)
{
    int lcm = lcmVector(v);
    makeLinear(lcm, v);
    Equation *e = new Equation(v);
    return e;
}
