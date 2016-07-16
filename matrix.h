#ifndef MATRIX_H
#define MATRIX_H
#include "equation.h"
#include "eqsolver.h"
class Matrix{};//forward declaration for compare to fixed

class Matrix
{

    public:
        Equation *eq1, *eq2, *eq3;
        std::vector<Equation> eqVector;
        Matrix(Equation *e1, Equation *e2, Equation *e3);

        void solveMatrix(std::vector<Equation>& eqVector);

        void isolateVar(std::vector<Equation>& eqVector);//isolate variable function, returns an equation with new coefficients
                        //and the isolated var's coefficient is turned to 1

        Matrix compareToFixed(std::vector<Equation> eqVector);

        QString s1;
};
#endif // MATRIX_H
