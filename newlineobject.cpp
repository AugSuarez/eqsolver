#include <QVBoxLayout>
#include <QLabel>
#include "newlineobject.h"

void New_Line_Object::newLine(){
    QVBoxLayout *newLine = new QVBoxLayout;
    QLabel *z = new QLabel;
    newLine->addWidget(z);
    z->setStyleSheet("QLabel{background-color:#daf;}");
}
