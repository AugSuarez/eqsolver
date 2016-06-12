#include "eqsolver.h"
#include <QLabel>
#include "newlineobject.h"

eqsolver::eqsolver(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::eqsolver)
{
    ui->setupUi(this);
    setStyles();
}

int eqsolver::btnCount = 1;
int eqsolver::btny = 50;

void eqsolver::newEqBtn(){

    QString newEqBtnName = "newEqBtn_" + QString::number(btnCount);
    btnCount++;

    ui->quit->setObjectName(newEqBtnName);

//    newEqBtn->setGeometry(50, btny, 100, 50);

    btny+=60;
}

void eqsolver::setStyles(){
    QString style = "QLineEdit{ background-color:#fff; border-style:none; border-radius:5px;}";
    QVector <QLineEdit*> v{ui->x_1, ui->y_1, ui->z_1, ui->x_2, ui->y_2, ui->z_2, ui->x_3, ui->y_3, ui->z_3};
    for(int i = 0; i<v.size(); i++)
    {
        v[i]->setStyleSheet(style);

    }
}

eqsolver::~eqsolver()
{
    delete ui;
}

void eqsolver::on_quit_clicked()
{
    QApplication::quit();
}

void eqsolver::on_quit_2_clicked()
{
    return;
}
