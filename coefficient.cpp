#include "coefficient.h"
#include <QTextStream>
#include <QChar>

Coefficient::Coefficient(QString s) : fractionRep{s}
{
    getNumer(fractionRep, numerInt, hasDenom);

    if(hasDenom)
        getDenom(fractionRep, denomInt);
}

void Coefficient::getNumer(QString& fractionRep, int& numerInt, bool& hasDenom)
{
    QString numerString;

    int numeratorSize = 0;

    for(int i = 0; i<fractionRep.size(); i++)
    {
        QChar ch = fractionRep.at(i);

        if(ch.isNumber() || (ch=='-' || ch=='+') )
            numerString += ch;

        else if (ch=='/' || ch=='\\')
        {
            hasDenom = true;
            numerInt = numerString.toInt();
            fractionRep.remove(0,numeratorSize);
            return;
        }

        else
            numerInt = 0;

        numeratorSize++;

    }

    numerInt = numerString.toInt();
}

void Coefficient::getDenom(QString& fractionRep, int& denomInt)
{
    QString denomString;

    for(int i = 0; i<fractionRep.size(); i++)
    {
        QChar ch = fractionRep.at(i);

        if(ch.isNumber())
            denomString += ch;

        else
            denomInt = 1;
    }

    denomInt = denomString.toInt();
}
