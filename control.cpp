#include "control.h"
#include <QLabel>

control::control()
{
    this->setWindowTitle("Assignment 4 Application");

    glWidget =new glwidget;

//    image = new QImage("/home/csdept/qt_workspace/t/stars.ppm");
//    label = new QLabel;
//    label->setPixmap(QPixmap::fromImage(*image));


    setCentralWidget(glWidget);
}

control::~control()
{

}
