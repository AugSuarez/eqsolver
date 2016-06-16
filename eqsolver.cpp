#include "eqsolver.h"
#include <QLabel>
#include <QGraphicsDropShadowEffect>
#include "matrix.h"

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

void eqsolver::newEqBtn()
{

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
    ui->lcm->setStyleSheet("QPushButton{ background-color:#EF5350; color: #fff; border-style: solid ; border-color: #777777; } QPushButton:pressed{ background-color: #ffdbbd; color:#000;}");

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
    Equation *eq1 = new Equation(1, ui->centralWidget);

    ui->x_r->setText(QString::number(eq1->x->numerInt));
    ui->y_r->setText(QString::number(eq1->y->numerInt));
    ui->z_r->setText(QString::number(eq1->z->numerInt));
}

std::vector<int> eqsolver::getPrimeFact(int n, std::vector<int> factorVector)
{
    while(n!=1)
    {
        for(int i = 2; i<=n; i++)
        {
            if(n%i==0)
            {
                if(factorVector[0]==1)
                    factorVector.pop_back();

                factorVector.push_back(i);
                n /= i;
                i = 1;
            }
        }
    }
    return factorVector;
}

int eqsolver::lcm(int a, int b)
{
    if(a%b==0 && a!=b)
        return a;
    else if(b%a==0 && a!=b)
        return b;

    int commonFactors=1;

    std::vector<int> aCopy = getPrimeFact(a);
    std::vector<int> bCopy = getPrimeFact(b);
    QString aS, bS;
    for(int i = 0; i<aCopy.size(); i++) { aS += QString::number(aCopy[i]) + " "; }
    for(int x = 0; x<bCopy.size(); x++) { bS += QString::number(bCopy[x]) + " "; }

    for(int i = 0; i<aCopy.size(); i++)
    {
        for(int x = 0; x<bCopy.size(); x++)
        {
            if(aCopy[i]==bCopy[x])
            {
                commonFactors *= bCopy[x];
                bCopy[x] = 1;
                aCopy[i] = 1;
            }
        }
    }
    ui->label->setText(aS);
    ui->label_2->setText(bS);
    return (a*b)/commonFactors;//parentheses there for the sake of the algorithm
}

int eqsolver::lcmVector(std::vector<Coefficient> v)
{
    int cumulLCM = 1;

    for(int i = 0; i<v.size(); i++)
    {
        if(i == v.size())
           return cumulLCM;
        else
           cumulLCM = lcm(cumulLCM, v[i].denomInt);
    }

    return cumulLCM;
}

void eqsolver::on_lcm_clicked()
{
    Equation *eq1 = new Equation(1, ui->centralWidget);
    ui->lcm_1->setText(QString::number(lcmVector(eq1->coefVector)));

    Equation *eq2 = new Equation(2, ui->centralWidget);
    ui->lcm_2->setText(QString::number(lcmVector(eq2->coefVector)));

    Equation *eq3 = new Equation(3, ui->centralWidget);
    ui->lcm_3->setText(QString::number(lcmVector(eq3->coefVector)));
}
