#include "glwidget.h"

#include<math.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<QtGui>
#include<QtOpenGL>

glwidget::glwidget(QWidget *parent):QGLWidget(QGLFormat(QGL::SampleBuffers),parent)
{

}

void glwidget::initializeGL()
{
    qglClearColor(Qt::black);
    glClearDepth(1.0f);
    glMatrixMode(GL_PROJECTION);
    glDepthFunc(GL_LEQUAL);
    //glEnable(GL_LIGHTING);
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    gluPerspective(60,(double)500/500,1,1000);
    gluLookAt(0,0,5,0,0,0,0,5,0);
    glFrustum(-2.0,2.0,-2.0,2.0,-2.0,2.0);
}

void glwidget::resizeGL(int width, int height)
{
    glViewport(0,0,width,height);
}

void glwidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    firstLightDetails();
    glPopMatrix();
    draw();
    glFlush();
}

void glwidget::draw(){

    textures[0] = bindTexture(QPixmap(QString("/home/csdept/qt_workspace/AssignmentS4/flower1.ppm")),GL_TEXTURE_2D);
    textures[1] = bindTexture(QPixmap(QString("/home/csdept/qt_workspace/AssignmentS4/flower2.ppm")),GL_TEXTURE_2D);
    textures[2] = bindTexture(QPixmap(QString("/home/csdept/qt_workspace/AssignmentS4/back.ppm")),GL_TEXTURE_2D);
    textures[3] = bindTexture(QPixmap(QString("/home/csdept/qt_workspace/AssignmentS4/top.ppm")),GL_TEXTURE_2D);
    textures[4] = bindTexture(QPixmap(QString("/home/csdept/qt_workspace/AssignmentS4/floor.ppm")),GL_TEXTURE_2D);

    //right
        glEnable(GL_TEXTURE_2D);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, textures[0]);
        firstLight();
        glBegin(GL_POLYGON);
        glColor3f(1.0,1.0,1.0);
        glTexCoord2f(0.0, 0.0);
        glVertex3f (5.5, -5.5, -5.5);
        glTexCoord2f(1.0, 0.0);
        glVertex3f (2.0, -2.0, -2.0);
        glTexCoord2f(1.0, 1.0);
        glVertex3f (2.0, 2.0, -2.0);
        glTexCoord2f(0.0, 1.0);
        glVertex3f (5.5, 5.5, -5.5);
        glEnd();
        glPopMatrix();


      //left
        glPushMatrix();
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
            glBindTexture(GL_TEXTURE_2D, textures[1]);
            firstLight();
            glBegin(GL_POLYGON);
            glTexCoord2f(0.0, 0.0);
            glVertex3f (-5.5, -5.5, -5.5);
            glTexCoord2f(1.0, 0.0);
            glVertex3f (-2.0, -2.0, -2.0);
            glTexCoord2f(1.0, 1.0);
            glVertex3f (-2.0, 2.0, -2.0);
            glTexCoord2f(0.0, 1.0);
            glVertex3f (-5.5, 5.5, -5.5);
            glEnd();
                glPopMatrix();

    //back
        glPushMatrix();
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glBindTexture(GL_TEXTURE_2D, textures[2]);
        firstLight();

        glBegin(GL_POLYGON);
        glTexCoord2f(0.0, 0.0);
        glVertex3f (-2.0, -2.0, -2.0);
        glTexCoord2f(1.0, 0.0);
        glVertex3f (2.0, -2.0, -2.0);
        glTexCoord2f(1.0, 1.0);
        glVertex3f (2.0, 2.0, -2.0);
        glTexCoord2f(0.0, 1.0);
        glVertex3f (-2.0, 2.0, -2.0);
        glEnd();
            glPopMatrix();

    //top

        glPushMatrix();
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glBindTexture(GL_TEXTURE_2D, textures[3]);
        firstLight();

        glBegin(GL_POLYGON);
        glTexCoord2f(0.0, 0.0);
        glVertex3f (5.5, 5.5, -5.5);
        glTexCoord2f(1.0, 0.0);
        glVertex3f (2.0, 2.0, -2.0);
        glTexCoord2f(1.0, 1.0);
        glVertex3f (-2.0, 2.0, -2.0);
        glTexCoord2f(0.0, 1.0);
        glVertex3f (-5.5, 5.5, -5.5);
        glEnd();
        glPopMatrix();

    //floor

        glPushMatrix();
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glBindTexture(GL_TEXTURE_2D, textures[4]);
        shadowLight();

        glBegin(GL_POLYGON);
        glTexCoord2f(0.0,0.0);
        glVertex3f (5.5, -5.5, -5.5);
        glTexCoord2f(1.0,1.0);
        glVertex3f (2.0, -2.0, -2.0);
        glTexCoord2f(0.0,1.0);
        glVertex3f (-2.0, -2.0, -2.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f (-5.5, -5.5, -5.5);
        glEnd();
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);


    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D, textures[2]);
    glTranslatef(1.4,1.9,0.0);
    //glScalef(0.65,0.65,0.65);
    glRotatef(70,1.0,-1.0,0.0);
    firstLight();
    drawTriangle();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D, textures[3]);
    //glTranslatef(-1.0,1.6,0.0);
    //glScalef(0.75,0.75,0.75);
    glRotatef(60,1.0,-1.0,0.0);
    firstLight();
    drawSquare();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D, textures[1]);
    glTranslatef(0,-1.4,0.0);
    glScalef(0.84,0.64,0.32);
    glRotatef(195,1.0,-1.0,0.0);
    firstLight();
    drawHexagon();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D, textures[0]);
    glTranslatef(1.5,-1.4,0.0);
    glScalef(0.75,0.56,0.82);
    glRotatef(300,1.0,-1.0,0.0);
    firstLight();
    drawCircle();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glPushMatrix();
    glTranslatef(-1.0,1.4,0.0);
//    glScalef(0.55,0.55,0.55);
    glRotatef(85,1.0,1.0,1.0);
//    glTranslatef(-1.5,0,0.0);
    firstLight();
    drawCube();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

     glEnable(GL_TEXTURE_2D);
     glPushMatrix();
     glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTranslatef(-1.0,-0.5,0.0);
    glRotatef(85,1.0,1.0,1.0);
    firstLight();
    //glShadeModel(GL_FLAT);
    drawSphere(0.5);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glColor3f(1.3,1.3,1.3);
    glBegin(GL_QUADS);
    glVertex3f(-2,-2, 0);
    glVertex3f(-2,-2,2);
    glVertex3f(2,-2,2);
    glVertex3f(2,-2, 0);
    glEnd();


    GLfloat floor[4] = {2,2,-2};
    GLfloat light[4] = {2.0, 2.0, 2.0};
    glPushMatrix();
    shadowMatrix(floor,light);
    glTranslatef(2,-3,-2);
    shadowLight();
    drawshadowCircle();
    glPopMatrix();

    glPushMatrix();
    shadowMatrix(floor,light);
    glTranslatef(2,-3,-2);
    //shadowLight();
    drawshadowTriangle();
    glPopMatrix();

    glPushMatrix();
    shadowMatrix(floor,light);
    glTranslatef(3,-1,-2);
    //firstLight();
    drawshadowHexagon();
    glPopMatrix();

    glPushMatrix();
    shadowMatrix(floor,light);
    glTranslatef(3,-1,-7);
    //firstLight();
    drawshadowSphere(2.0);
    glPopMatrix();

    glPushMatrix();
    shadowMatrix(floor,light);
    glTranslatef(3,-1,-12);
    //firstLight();
    drawshadowCube();
    glPopMatrix();

    glPushMatrix();
    shadowMatrix(floor,light);
    glTranslatef(3,-1,-4);
    //firstLight();
    drawshadowSquare();
    glPopMatrix();

}


void glwidget::ngon(int n){
    double rotate = 360.0 / n;
    double degree = rotate/2 +180;
    double radians = 180/3.14159;

    GLfloat x,y,z = 0;
    double r,g,b;

    //hexagon
    if(n == 6){
         glBegin(GL_POLYGON);
        for(int i = 0;i < n;i++,degree += rotate){
//            r = (double)(rand() % (100-0+1)+0)/100;
//            g = (double)(rand() % (100-0+1)+0)/100;
//            b = (double)(rand() % (100-0+1)+0)/100;
//            glColor3f(r,g,b);

            x = 0.5 * sin(degree/radians);
            y = 0.5 * sin((90 - degree)/radians);
            glTexCoord2f(x,y);
            calculateNormals(&x,&y,&z,&xNormal,&yNormal,&zNormal);
            glNormal3f(xNormal,yNormal,zNormal);
            glVertex3f(x,y,0);
        }
        glEnd();
    }else if(n == 100){ //circle
         glBegin(GL_POLYGON);
        for(int i = 0;i < n;i++,degree += rotate){
            x = 1.0 * sin(degree/radians);
            y = 1.0 * sin((90 - degree)/radians);
//            r = (double)(rand() % (100-0+1)+0)/100;
//            g = (double)(rand() % (100-0+1)+0)/100;
//            b = (double)(rand() % (100-0+1)+0)/100;
//            glColor3f(r,g,b);
            glTexCoord2f(x,y);
            glVertex3f(x,y,0);

        }
        calculateNormals(&x,&y,&z,&xNormal,&yNormal,&zNormal);
        glNormal3f(xNormal,yNormal,zNormal);
        glEnd();
    }
}

void glwidget::shadowngon(int n){
    double rotate = 360.0 / n;
    double degree = rotate/2 +180;
    double radians = 180/3.14159;

    GLfloat x,y,z = 0;

    //hexagon
    if(n == 6){
         glBegin(GL_POLYGON);
        for(int i = 0;i < n;i++,degree += rotate){
            glColor3f(0.3,0.3,0.3);
            x = 0.5 * sin(degree/radians);
            y = 0.5 * sin((90 - degree)/radians);
            calculateNormals(&x,&y,&z,&xNormal,&yNormal,&zNormal);
            glNormal3f(xNormal,yNormal,zNormal);
            glVertex3f(x,y,0);
        }
        glEnd();
    }else if(n == 100){ //circle
         glBegin(GL_POLYGON);
        for(int i = 0;i < n;i++,degree += rotate){
            x = 1.0 * sin(degree/radians);
            y = 1.0 * sin((90 - degree)/radians);
            glColor3f(0.3,0.3,0.3);
            glVertex3f(x,y,0);

        }
        calculateNormals(&x,&y,&z,&xNormal,&yNormal,&zNormal);
        glNormal3f(xNormal,yNormal,zNormal);
        glEnd();
    }
}


void glwidget::drawSphere(double p_radius){
    int color = 0;
    float PI = atan(1.0)*4.0;
    GLdouble a,b,x,y,z;
    float da = 6.0,db = 6.0;
    double radius = p_radius;

    for(a = -90.0; a+da <= 90.0; a+=da){
        if(a < 0)
            glBindTexture(GL_TEXTURE_2D, textures[1]);
        else
            glBindTexture(GL_TEXTURE_2D, textures[0]);
        glBegin(GL_QUAD_STRIP);
        for(b = 0.0;b <= 360; b += db){
            if(color){
                //glIndexi(Qt::red);
                //glTexCoord2d(1,0);
            }else {
                //glIndexi(Qt::black);
                //glTexCoord2d(1,1);
            }
            x = radius * cos(b * PI/180) * cos(a * PI/180);
            y = radius * sin(b * PI/180) * cos(a * PI/180);
            z = radius * sin(a * PI/180);
            int recurse = 1;


            SphereFace(recurse, p_radius,&x, &y, &z);
            glTexCoord3d(x,y,z);
            glVertex3f(x,y,z);

            x = radius * cos(b * PI/180) * cos((a+da) * PI/180);
            y = radius * sin(b * PI/180) * cos((a+da) * PI/180);
            z = radius * sin((a+da) * PI/180);
            SphereFace(recurse, p_radius,&x, &y, &z);
            glTexCoord3d(x,y,z);
            glVertex3f(x,y,z);
            color = 1-color;
        }
        glEnd();
    }

}

void glwidget::drawshadowSphere(double p_radius){
    float PI = atan(1.0)*4.0;
    GLdouble a,b,x,y,z;
    float da = 6.0,db = 6.0;
    double radius = p_radius;

    for(a = -90.0; a+da <= 90.0; a+=da){
        glBegin(GL_QUAD_STRIP);
        glColor3f(0.3,0.3,0.3);
        for(b = 0.0;b <= 360; b += db){
            x = radius * cos(b * PI/180) * cos(a * PI/180);
            y = radius * sin(b * PI/180) * cos(a * PI/180);
            z = radius * sin(a * PI/180);
            int recurse = 1;

            SphereFace(recurse, p_radius,&x, &y, &z);
            glVertex3f(x,y,z);

            x = radius * cos(b * PI/180) * cos((a+da) * PI/180);
            y = radius * sin(b * PI/180) * cos((a+da) * PI/180);
            z = radius * sin((a+da) * PI/180);
            SphereFace(recurse, p_radius,&x, &y, &z);
            glVertex3f(x,y,z);
        }
        glEnd();
    }

}

void glwidget::Normalize3(GLdouble *v)
{
   GLdouble len = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
   v[0] /= len;
   v[1] /= len;
   v[2] /= len;
}

void glwidget::SphereFace(int p_recurse, double p_radius, GLdouble *a, GLdouble *b, GLdouble *c)
{
    if(p_recurse > 1)
    {
       GLdouble d[3] = {a[0] + b[0], a[1] + b[1], a[2] + b[2]};
       GLdouble e[3] = {b[0] + c[0], b[1] + c[1], b[2] + c[2]};
       GLdouble f[3] = {c[0] + a[0], c[1] + a[1], c[2] + a[2]};

       Normalize3(d);
       Normalize3(e);
       Normalize3(f);

       SphereFace(p_recurse-1, p_radius, a, d, f);
       SphereFace(p_recurse-1, p_radius, d, b, e);
       SphereFace(p_recurse-1, p_radius, f, e, c);
       SphereFace(p_recurse-1, p_radius, f, d, e);
    }
}

void glwidget::drawPoint(){
    //point
    glPointSize(4.0f);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glNormal3f(0.0, 0.0, 0.0);
    glVertex3f(0.0,0.0,0.0);
    glEnd();
}

void glwidget::drawLine(){
    //line
    glBegin(GL_LINES);
    glColor3f(0.0f,2.0f,0.0f);
    //    glColor3f(0.0f,0.0f,1.0f);
    glNormal3f(0.0, -0.5, 0.0);
    glVertex3f(0.0,-0.5,0.0);
    glColor3f(0.0f,2.0f,0.0f);
    glNormal3f(0.0, 0.5, 0.0);
    glVertex3f(0.0,0.5,0.0);
    glEnd();
}

void glwidget::drawTriangle(){
    //Triangle
    glBegin(GL_TRIANGLES);
    glTexCoord2f(0.0,0.0);
    glVertex3f(-0.5,-0.5,0.0);
    glTexCoord2f(1.0,0.0);
    glVertex3f(0.5,-0.5,0.0);
    glTexCoord2f(1.0,1.0);
    glVertex3f(0.0,0.5,0.0);
    GLfloat vertex1[3] = {-0.5,-0.5,0.0};
    GLfloat vertex2[3] = {0.5,-0.5,0.0};
    GLfloat vertex3[3] = {0.0,0.5,0.0};
    calculateNormals(vertex1,vertex2,vertex3,&xNormal,&yNormal,&zNormal);
    glNormal3f(xNormal,yNormal,zNormal);
    glEnd();
}

void glwidget::drawshadowTriangle(){
    //Triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.3f,0.3f,0.3f);
    glVertex3f(-0.5,-0.5,0.0);
    //glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(0.5,-0.5,0.0);
    //glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(0.0,0.5,0.0);
    GLfloat vertex1[3] = {-0.5,-0.5,0.0};
    GLfloat vertex2[3] = {0.5,-0.5,0.0};
    GLfloat vertex3[3] = {0.0,0.5,0.0};
    calculateNormals(vertex1,vertex2,vertex3,&xNormal,&yNormal,&zNormal);
    glNormal3f(xNormal,yNormal,zNormal);
    glEnd();
}

void glwidget::drawshadowSquare(){
    //Square
    glBegin(GL_QUADS);
    glColor3f(0.3f,0.3f,0.3f);
    glVertex3f(0.5,0.5,0.0);
    glNormal3f(0.5,0.5,0.0);
    //glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(0.5,-0.5,0.0);
    glNormal3f(0.5,-0.5,0.0);
    //glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(-0.5,-0.5,0.0);
    glNormal3f(-0.5,-0.5,0.0);
    //glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(-0.5,0.5,0.0);
    glNormal3f(-0.5,0.5,0.0);
    glEnd();
}

void glwidget::drawSquare(){
    //Square
    glBegin(GL_QUADS);
    glTexCoord2f(1.0,0.0);
    //glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(0.5,0.5,0.0);
    glNormal3f(0.5,0.5,0.0);
    glTexCoord2f(0.0,1.0);
    //glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(0.5,-0.5,0.0);
    glNormal3f(0.5,-0.5,0.0);
    glTexCoord2f(1.0,1.0);
    //glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(-0.5,-0.5,0.0);
    glNormal3f(-0.5,-0.5,0.0);
    //glColor3f(1.0f,0.0f,0.0f);
    glTexCoord2f(0.0,0.0);
    glVertex3f(-0.5,0.5,0.0);
    glNormal3f(-0.5,0.5,0.0);
    glEnd();
}

//Hexagon function which calls ngon(int n) function where n = 6
void glwidget::drawHexagon(){
    //Hexagon
    glBegin(GL_POLYGON);
    ngon(6);
    glEnd();
}

void glwidget::drawshadowHexagon(){
    //Hexagon
    glBegin(GL_POLYGON);
    shadowngon(6);
    glEnd();
}

void glwidget::drawCube()
{
    static const GLfloat coords[6][4][3] = {


        { { -0.5,-0.5,-0.5 }, {-0.5,0.5,-0.5},//back side coordinates
        {0.5,0.5,-0.5}, {0.5,-0.5,-0.5} },

        { {-0.5,-0.5,-0.5 }, { +0.5, -0.5, -0.5 },//bottom side coordinates
        {0.5,-0.5,0.5}, {-0.5,-0.5,0.5} },

        { {-0.5,-0.5,-0.5}, { -0.5, -0.5, +0.5 },//left side coordinates
        {-0.5,0.5,0.5}, {-0.5,0.5,-0.5} },

        { {0.5,-0.5,-0.5}, {0.5,0.5,-0.5},//right side coordinates
        {0.5,0.5,0.5}, {0.5,-0.5,0.5} },

        { {-0.5,0.5,-0.5}, {-0.5,0.5,0.5},//top side coordinates
        {0.5,0.5,0.5}, {0.5,0.5,-0.5} },

        { { -0.5, -0.5, +0.5}, { +0.5, -0.5, +0.5 },//front side coordinates
        { +0.5, +0.5, +0.5 }, { -0.5, +0.5, +0.5 } }
    };


    for (int i = 0; i<6 ; ++i)
    {

        if(i == 0)
            glBindTexture(GL_TEXTURE_2D, textures[0]);
        else if(i == 1)
            glBindTexture(GL_TEXTURE_2D, textures[1]);
        else if(i==2)
            glBindTexture(GL_TEXTURE_2D, textures[4]);
        else if(i==3)
            glBindTexture(GL_TEXTURE_2D, textures[2]);
        else if(i==4)
            glBindTexture(GL_TEXTURE_2D, textures[3]);
        else
            glBindTexture(GL_TEXTURE_2D, textures[0]);

        glBegin(GL_POLYGON);

        switch(i){
        case 0:
            glNormal3f(0.0,-0.5,0.0);
            //glTexCoord2f(1.0,1.0);
            break;
        case 1:
            glNormal3f(-0.5,0.0,0.0);
            //glTexCoord2f(0.0,0.0);
            break;
        case 2:
            glNormal3f(0.0,0.0,-0.5);
            //glTexCoord2f(0.0,1.0);
            break;
        case 3:
            glNormal3f(0.0,0.0,0.5);
            //glTexCoord2f(1.0,0.0);
            break;
        case 4:
            glNormal3f(0.0,0.5,0.0);
            //glColor3f(1.0f,0.0f,1.0f);
            break;
        case 5:
            glNormal3f(0.5,0.0,0.0);
            //glColor3f(0.0f,1.0f,1.0f);
            break;
        }



        for (int j = 0; j < 4; ++j)
        {

            glTexCoord2f(coords[i][j][0],coords[i][j][1]);
            glNormal3f(coords[i][j][0], coords[i][j][1],coords[i][j][2]);
            glVertex3f(coords[i][j][0], coords[i][j][1],coords[i][j][2]);
        }
        glEnd();
    }
}

void glwidget::drawshadowCube()
{
    static const GLfloat coords[6][4][3] = {
        { {-0.5,-0.5,-0.5 }, { +0.5, -0.5, -0.5 },//bottom side coordinates
        {0.5,-0.5,0.5}, {-0.5,-0.5,0.5} },

        { {-0.5,-0.5,-0.5}, { -0.5, -0.5, +0.5 },//left side coordinates
        {-0.5,0.5,0.5}, {-0.5,0.5,-0.5} },

        { { -0.5,-0.5,-0.5 }, {-0.5,0.5,-0.5},//back side coordinates
        {0.5,0.5,-0.5}, {0.5,-0.5,-0.5} },

        { { -0.5, -0.5, +0.5}, { +0.5, -0.5, +0.5 },//front side coordinates
        { +0.5, +0.5, +0.5 }, { -0.5, +0.5, +0.5 } },

        { {-0.5,0.5,-0.5}, {-0.5,0.5,0.5},//top side coordinates
        {0.5,0.5,0.5}, {0.5,0.5,-0.5} },

        { {0.5,-0.5,-0.5}, {0.5,0.5,-0.5},//right side coordinates
        {0.5,0.5,0.5}, {0.5,-0.5,0.5} }
    };

    for (int i = 1; i<6 ; ++i)
    {
        glBegin(GL_POLYGON);
        glColor3f(0.3,0.3,0.3);
        switch(i){
        case 0:
            glNormal3f(0.0,-0.5,0.0);
            break;
        case 1:
            glNormal3f(-0.5,0.0,0.0);
            break;
        case 2:
            glNormal3f(0.0,0.0,-0.5);
            break;
        case 3:
            glNormal3f(0.0,0.0,0.5);
            break;
        case 4:
            glNormal3f(0.0,0.5,0.0);
            break;
        case 5:
            glNormal3f(0.5,0.0,0.0);
            break;
        }

        for (int j = 0; j < 4; ++j)
        {
            glVertex3f(coords[i][j][0], coords[i][j][1],coords[i][j][2]);
        }
        glEnd();
    }
}


//circle which calls ngon(int n) function where n is 100
void glwidget::drawCircle(){
    //circle
    ngon(100);
}

void glwidget::drawshadowCircle(){
    //circle
    shadowngon(100);
}

void glwidget::shadowMatrix(GLfloat floor[4], GLfloat light[4])
{
    float  shadow[4][4];

    for(int i =0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i == j){
                shadow[i][j] = (floor[0] * light[0] + floor[1] * light[1] + floor[2] * light[2] + floor[3] * light[3]) - light[i] * floor[i];
            }else{
                shadow[i][j] = 0.0 - light[j] * floor[i];
            }
        }
    }
    glMultMatrixf((const GLfloat*)shadow);
}

void glwidget::calculateNormals(GLfloat v1[],GLfloat v2[],GLfloat v3[],GLfloat *xNormal,GLfloat *yNormal,GLfloat *zNormal){
        *xNormal = (v2[1]-v1[1])*(v3[2]-v1[2]) - (v2[2]-v1[2])*(v3[1]-v1[1]);
        *yNormal = (v2[0]-v1[0])*(v3[2]-v1[2]) - (v2[2]-v1[2])*(v3[0]-v1[0]);
        *zNormal = (v2[0]-v1[0])*(v3[1]-v1[1]) - (v2[1]-v1[1])*(v3[0]-v1[0]);
}
void glwidget::firstLightDetails(){

    // Lighting set up
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glShadeModel(GL_SMOOTH);

    // Set lighting intensity and color
    GLfloat qaAmbientLight[]	= {0.2, 0.2, 0.2, 1.0};
    GLfloat qaDiffuseLight[]	= {0.8, 0.8, 0.8, 1.0};
    GLfloat qaSpecularLight[]	= {1.0, 1.0, 1.0, 1.0};
    glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);

    glLightfv(GL_LIGHT1, GL_AMBIENT, qaAmbientLight);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, qaDiffuseLight);
    glLightfv(GL_LIGHT1, GL_SPECULAR, qaSpecularLight);

    // Set the light position
    GLfloat lightPosition[]	= {2.0, 2.0, 2.0, 1.0};
    GLfloat lightDirection[] = {0.55,-0.25,0.0,1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, lightDirection);
}

void glwidget::firstLight(){
    // Set material properties
    GLfloat qaBlack[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat qaGreen[] = {0.0, 1.0, 0.0, 1.0};
    GLfloat qaWhite[] = {1.0, 1.0, 1.0, 1.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaBlack);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaGreen);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaWhite);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.2);
}

void glwidget::shadowLight(){
    GLfloat qaBlack[] = {0.0, 0.0, 0.0, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, qaBlack);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, qaBlack);
    glMaterialfv(GL_FRONT, GL_SPECULAR, qaBlack);
    glMaterialf(GL_FRONT, GL_SHININESS, 0);
}
