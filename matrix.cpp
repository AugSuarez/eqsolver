#include "matrix.h"
#include "ui_eqsolver.h"
#include "eqsolver.h"

void Matrix::createEquation1(){
    this->eq1 = new Equation(eqsolver::ui->x_1, eqsolver::ui->y_1, eqsolver::ui->z_1, eqsolver::ui->c_1);
}

void Matrix::createEquation2(){
    this->eq2 = new Equation(eqsolver::ui->x_2, eqsolver::ui->y_2, eqsolver::ui->z_2, eqsolver::ui->c_2);
}

void Matrix::createEquation3(){
    this->eq3 = new Equation(eqsolver::ui->x_3, eqsolver::ui->y_3, eqsolver::ui->z_3, eqsolver::ui->c_3);
}
