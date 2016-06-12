#ifndef EQSOLVER_H
#define EQSOLVER_H

#include <QMainWindow>
#include <QPushButton>
#include "ui_eqsolver.h"

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
    static int btnCount;
    static int btny;
    ~eqsolver();

private slots:
    void on_quit_clicked();

    void on_calculate_clicked();

private:
    Ui::eqsolver *ui;
};


#endif // EQSOLVER_H
