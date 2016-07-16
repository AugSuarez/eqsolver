#ifndef EQSOLVER_H
#define EQSOLVER_H

#include <QMainWindow>
#include <QPushButton>
#include "ui_eqsolver.h"

#include "matrix.h"

#include <vector>

namespace Ui {
class eqsolver;
}

class eqsolver : public QMainWindow
{
    Q_OBJECT

public:
    explicit eqsolver(QWidget *parent = 0);
    void newEqBtn();
    void setStyles();

    static int lcm(int a = 1, int b = 1);
    static int lcmVector(std::vector<Coefficient> v);
    static std::vector<int> getPrimeFact(int n, std::vector<int> factorVector = {1});

    ~eqsolver();


//private:
    Ui::eqsolver *ui;

private slots:
    void on_quit_clicked();

    void on_calculate_clicked();

    void on_lcm_clicked();

};


#endif // EQSOLVER_H
