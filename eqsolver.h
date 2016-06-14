#ifndef EQSOLVER_H
#define EQSOLVER_H

#include <QMainWindow>
#include <QPushButton>
#include "ui_eqsolver.h"
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

    int lcm(int a = 1, int b = 1);
    std::vector<int> getPrimeFact(int n, std::vector<int> factorVector = {1});


    static int btnCount;
    static int btny;
    ~eqsolver();

private slots:
    void on_quit_clicked();

    void on_calculate_clicked();

    void on_lcm_clicked();

private:
    Ui::eqsolver *ui;
};


#endif // EQSOLVER_H
