#include "coefficient.h"
#include <QTextStream>
#include <QChar>

Coefficient::Coefficient(QString s) : fractionRep{s}, numerString {getNumer(fractionRep, numerString, hasDenom)}
{
    if(hasDenom)
        getDenom(fractionRep, denomString);
}

QString Coefficient::getNumer(QString& fractionRep, QString& numerString, bool& hasDenom)
{
    QTextStream in(stdin);


    for(int i = 0; i<fractionRep.size(); i++)
    {

        QChar ch = fractionRep.at(0);
        in >> ch;



        if(ch.isNumber() || (ch.isSymbol() && (ch=='-' || ch=='+')) )
            numerString += ch;

        else if (ch.isSymbol() && (ch=='/' || ch=='\\'))
        {
            hasDenom = true;
            fractionRep.remove(0, 1);
            return numerString;
        }

        else
            return "Non-math char found";

        fractionRep.remove(0, 1);

    }

    return numerString;
}


QString Coefficient::getDenom(QString& fractionRep, QString& denomString)
{
    QTextStream in(stdin);

    QChar ch = fractionRep.at(0);
    in >> ch;

    if(ch.isNumber())
        numerString += ch;

    else
        return "Non math char found";

    fractionRep.remove(0, 1);

    return denomString;
}
