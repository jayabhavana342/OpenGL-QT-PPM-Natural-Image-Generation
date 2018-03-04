#-------------------------------------------------
#
# Project created by QtCreator 2017-04-07T11:45:32
#
#-------------------------------------------------

QT       += core gui opengl

LIBS += -lglut -lGLU

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AssignmentS4
TEMPLATE = app


SOURCES += main.cpp \
    glwidget.cpp \
    control.cpp

HEADERS  += \
    glwidget.h \
    control.h

DISTFILES += \
    stars.ppm \
    img.png
