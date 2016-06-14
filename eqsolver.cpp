#include "eqsolver.h"
#include <QLabel>
#include <QGraphicsDropShadowEffect>
#include "matrix.h"//will be replaced by matrix.h or eqsolver.h

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

//    Coefficient *x1 = new Coefficient(ui->x_1->text());//makes a fractional representation of the inputed text using string
//    Coefficient *y1 = new Coefficient(ui->y_1->text());
//    Coefficient *z1 = new Coefficient(ui->z_1->text());

//    getLCD(x1,y1,z1);

    Equation *eq1 = new Equation(ui->x_1->text(), ui->y_1->text(), ui->z_1->text(), ui->c_1->text());

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
    int aProduct = 1;
    int bProduct = 1;

    std::vector<int> aCopy = getPrimeFact(a);

    std::vector<int> bCopy = getPrimeFact(b);

QString s;
    for(int i = 0; i<aCopy.size(); i++)
    {
        aProduct *= aCopy[i];

        for(int x = 0; x<bCopy.size(); x++)
        {
            bProduct *= bCopy[x];

            if(aCopy[i]==bCopy[x])
            {
                s += "Common Factor: " + QString::number(bCopy[x]) + ". ";
                ui->lcm_3->setText(s);
                commonFactors *= bCopy[x];
            }
        }

    }

    return aProduct*bProduct/commonFactors;
}

void eqsolver::on_lcm_clicked()
{
    Equation *eq1 = new Equation(ui->x_1->text(), ui->y_1->text(), ui->z_1->text(), ui->c_1->text());
    int i = lcm(eq1->x->numerInt, eq1->y->numerInt);
    ui->lcm_1->setText(QString::number(i));
}
