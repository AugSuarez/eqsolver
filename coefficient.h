#ifndef COEFFICIENT_H
#define COEFFICIENT_H
#include <QString>

class Coefficient{

    public:
        double doubleRep;// actual decimal representation
        QString numerString;
        QString denomString;
        QString fractionRep;
        int numerInt {0};
        int denomInt {1};//to avoid undefined div by 0
        bool hasDenom = false;//is true if denom != 1;

        QString getFractionRep();//fractional representation in string form

        Coefficient(QString s);
        Coefficient(int numer, int denom);

    private:
        void getNumer(QString& fractionRep, int& numerInt, bool& hasDenom);
        void getDenom(QString& fractionRep, int& denomInt);

};

#endif // COEFFICIENT_H
