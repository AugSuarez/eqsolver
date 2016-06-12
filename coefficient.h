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
        ~Coefficient();

        QString getNumer(QString& fractionRep, QString& numerString, bool& hasDenom);
        QString getDenom(QString& fractionRep, QString& denomString);

};

#endif // COEFFICIENT_H
