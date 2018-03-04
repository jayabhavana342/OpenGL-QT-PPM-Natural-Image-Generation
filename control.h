#ifndef CONTROL_H
#define CONTROL_H

#include "glwidget.h"

#include <QWidget>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QGroupBox>
#include<QRadioButton>
#include<QButtonGroup>
#include<QMainWindow>
#include<QAction>
#include<QLabel>
#include<QActionGroup>
#include<QtGui>
#include<QImage>
#include<QPixmap>

class control : public QMainWindow
{
    Q_OBJECT
public:
    control();

    glwidget *glWidget;
    QImage *image;
    QLabel *label;

    QGroupBox *main_gbox;
    QHBoxLayout *hlayout1;

    ~control();
};

#endif // CONTROL_H
