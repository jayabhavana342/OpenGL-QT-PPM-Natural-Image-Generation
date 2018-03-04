#include "control.h"
#include<GL/glut.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    glutInit(&argc,argv);
    QApplication a(argc, argv);
    control w;
    w.resize(800,600);

//    QGraphicsBlurEffect *effect = new QGraphicsBlurEffect();
//    effect->setBlurRadius(5);
//    w.setGraphicsEffect(effect);

    w.show();
    return a.exec();
}
