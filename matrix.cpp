#include "matrix.h"

Matrix::Matrix(Equation *e1, Equation *e2, Equation *e3) : eq1{e1}, eq2{e2}, eq3{e3}
{
    eqVector.push_back(*eq1);
    eqVector.push_back(*eq2);
    eqVector.push_back(*eq3);
}

void Matrix::isolateVar(std::vector<Equation> &eqVector)
{
    for(int i = 0; i<eqVector.size(); i++)
    {

        for(int x = 1; x<eqVector[i].coefVector.size(); x++)//applies to all members of vector other than the first one
        {
            eqVector[i].coefVector[x].numerInt *= -1;//simulates subraction for isolation of variable
            eqVector[i].coefVector[x].numerInt *= eqVector[i].x->denomInt;
            eqVector[i].coefVector[x].denomInt *= eqVector[i].x->numerInt;
            eqVector[i].coefVector[eqVector[i].coefVector.size()-1].numerInt *= -1;//multiply constant value (the last element in coefVector) by -1 again -> unaffected by previous *(-1)
        }

    if(eqVector[i].coefVector[0].numerInt != 0)
        eqVector[i].coefVector[0].numerInt /= eqVector[i].coefVector[0].numerInt;

    if(eqVector[i].coefVector[0].denomInt != 0)
        eqVector[i].coefVector[0].denomInt /= eqVector[i].coefVector[0].denomInt;

    }
//    eqVector[0].coefVector.erase(eqVector[0].coefVector.begin());
    //s1 = QString("x*") + eqVector[0].coefVector[0].getFractionRep() + (" = ") + QString(" y*") + eqVector[0].coefVector[3].getFractionRep() + QString(" z*") + eqVector[0].coefVector[2].getFractionRep() + QString(" ") + eqVector[0].coefVector[1].getFractionRep();
}

Matrix Matrix::compareToFixed(std::vector<Equation> eqVector){

    Equation e1 = eqVector[0];
    std::vector<Coefficient> v;

    for(int i = 1; i<eqVector.size(); i++)
    {
        std::vector<Coefficient>;
        Equation e2 = eqVector[i];
        for(int x = 1; i<eqVector[i].coefVector.size(); x++)
        {
            int lcm = eqsolver::lcm(eqVector[0].coefVector[x].denomInt, eqVector[i].coefVector[x].denomInt);
            eqVector[0].coefVector[x].numerInt *= (lcm/eqVector[0].coefVector[x].denomInt);
            eqVector[i].coefVector[x].numerInt *= (lcm/eqVector[i].coefVector[x].denomInt);
            eqVector[0].coefVector[x].denomInt  = lcm;
            eqVector[i].coefVector[x].denomInt  = lcm;
            int newNumer = eqVector[0].coefVector[x].numerInt - eqVector[i].coefVector[x].numerInt;
            v.push_back(Coefficient(newNumer, lcm));

            if(v.size() == eqVector[i].coefVector.size())
            {
                Equation e = Equation(v);

            }
        }

    }

}

/*compare to fixed
 * copy both equations into new equations eq4 and eq5
 * for eqVector.size
 * eqVector[0].coefVector[x].denomInt and eqVector[i].coefVector[x].denomInt = lcm // in copied vectors
 * eqVector[0].coefVector[x].numerInt  and eqVector[i].coefVector[x].numerInt *= lcm/demomInt // in copied vectors
 * */
