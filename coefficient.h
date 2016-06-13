#ifndef COEFFICIENT_H
#define COEFFICIENT_H
#include "eqsolver.h"
#include <QString>
class Coefficient{

    public:
        QString fractionRep;//fractional representation in string form
        double doubleRep;// actual decimal representation
        QString numerString;
        QString denomString;
        int numerInt {0};
        int denomInt {1};//to avoid undefined div by 0
        bool hasDenom = false;//is true if denom != 1;

        Coefficient(QString s);

        void getNumer(QString& fractionRep, int& numerInt, bool& hasDenom);
        void getDenom(QString& fractionRep, int& denomInt);

};

#endif // COEFFICIENT_H
