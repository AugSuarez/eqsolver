#ifndef MATRIX_H
#define MATRIX_H
#include "equation.h"
class Matrix
{

    public:
        Equation *eq1, *eq2, *eq3;
        void createEquation1();
        void createEquation2();
        void createEquation3();//function to initialize the equations, which in turn initialize the coefficients
        Equation isolateVar(Coefficient isoVar, std::vector<Coefficient> v);//isolate variable function, returns an equation with new coefficients
                        //and the isolated var's coefficient is turned to 1
        void solveMatrix(std::vector<Coefficient> v1, std::vector<Coefficient> v2, std::vector<Coefficient> v3);

};
#endif // MATRIX_H
