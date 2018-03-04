#ifndef GLWIDGET_H
#define GLWIDGET_H

#include<QColor>
#include<QtWidgets>
#include<QGLWidget>
#include<QtOpenGL/QGLWidget>
#include<QOpenGLTexture>

class glwidget : public QGLWidget
{
private:
    GLfloat xNormal,yNormal,zNormal;
public:
    glwidget(QWidget *parent=0);

protected:
    void initializeGL();
    void resizeGL(int width,int height);
    void paintGL();

public:

    GLuint textures[5];

    void draw();
    void ngon(int);
    void shadowngon(int);
    void drawPoint();
    void drawLine();
    void drawCircle();
    void drawshadowCircle();
    void drawSquare();
    void drawshadowSquare();
    void drawHexagon();
    void drawshadowHexagon();
    void drawCube();
    void drawshadowCube();
    void drawshadowTriangle();
    void drawTriangle();
    void drawSphere(double );
    void drawshadowSphere(double );

    void firstLight();
    void shadowLight();
    void firstLightDetails();
    void calculateNormals(GLfloat [],GLfloat [],GLfloat [],GLfloat *,GLfloat *,GLfloat *);
    void Normalize3(GLdouble *);
    void SphereFace(int , double , GLdouble *, GLdouble *, GLdouble *);
    void shadowMatrix(GLfloat [], GLfloat []);

};

#endif // GLWIDGET_H
