#include "eqsolver.h"
#include <QLabel>
#include <QGraphicsDropShadowEffect>
#include "coefficient.h"

//#include <QtWebEngine>
//#include <QtWebEngineWidgets>

eqsolver::eqsolver(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::eqsolver)
{
    ui->setupUi(this);
    setStyles();
}

eqsolver::~eqsolver()
{
    delete ui;
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
    QString style = "QLineEdit{ background-color:#fff; border: 1px solid #ddd; border-radius:3px;} QLineEdit:focus { background-color:#eee;}";
    ui->matrixframe->setStyleSheet("QLabel { color:#fff; }" + style);
    ui->quit->setStyleSheet("QPushButton{ background-color:#EF5350; color: #fff; border-style: solid ; border-color: #777777; } QPushButton:pressed{ background-color: #ffdbbd; color:#000;}");
    ui->calculate->setStyleSheet("QPushButton{ background-color:#EF5350; color: #fff; border-style: solid ; border-color: #777777; } QPushButton:pressed{ background-color: #ffdbbd; color:#000;}");

    QGraphicsDropShadowEffect *mainshadow = new QGraphicsDropShadowEffect();
    mainshadow->setXOffset(1);
    mainshadow->setYOffset(2);
    mainshadow->setBlurRadius(5);
    mainshadow->setColor(QColor(90, 90, 90, 80));
    ui->mainframe->setGraphicsEffect(mainshadow);


    QGraphicsDropShadowEffect *nameshadow = new QGraphicsDropShadowEffect();
    nameshadow->setXOffset(0);
    nameshadow->setYOffset(2);
    nameshadow->setBlurRadius(5);
    nameshadow->setColor(QColor(120, 90, 90, 40));
    ui->nameframe->setGraphicsEffect(nameshadow);
}

void eqsolver::on_quit_clicked()
{
    QApplication::quit();
}

void eqsolver::on_calculate_clicked()
{

    Coefficient *x1 = new Coefficient(ui->x_1->text());//makes a fractional representation of the inputed text using string

    ui->x_r->setText(QString::number(x1->denomInt));
}
