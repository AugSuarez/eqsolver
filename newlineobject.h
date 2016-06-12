#ifndef NEWLINEOBJECT_H
#define NEWLINEOBJECT_H
#include "eqsolver.h"
namespace Ui {
    class New_Line_Object;
}
class New_Line_Object: public QPushButton
{
    Q_OBJECT

    public:
        New_Line_Object(QWidget *parent);

    public slots:
        void newLine();
};

#endif // NEWLINEOBJECT_H
