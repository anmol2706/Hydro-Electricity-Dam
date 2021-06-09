#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <freeglut.h>

void display();
void specialKeys();

double rotate_y=0;
double rotate_x=0;
bool dash=false;

void modify()
{
    glBegin(GL_LINES);
    glPointSize(8.0);
    glColor3f(1,0,0.0);
    glVertex3f(0.0,0.0,0.1);
    glVertex3f(0.0,0.0,0.8);
    glVertex3f(0,0,0);
    glVertex3f(0,0,0);
    glEnd();
}
void polygons()
{
    glBegin(GL_POLYGON);
    glVertex3f(  0.2, -0.1, -0.3 );
    glVertex3f(  0.2,  0.1, -0.3 );
    glVertex3f( -0.2,  0.1, -0.3 );
    glVertex3f( -0.2, -0.1, -0.3 );
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(  0.2, -0.1, 0.3 );
    glVertex3f(  0.2,  0.1, 0.3 );
    glVertex3f( -0.2,  0.1, 0.3 );
    glVertex3f( -0.2, -0.1, 0.3 );
    glEnd();


    glBegin(GL_POLYGON);
    glVertex3f( 0.2, -0.1, -0.3 );
    glVertex3f( 0.2,  0.1, -0.3 );
    glVertex3f( 0.2,  0.1,  0.3 );
    glVertex3f( 0.2, -0.1,  0.3);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f( -0.2, -0.1,  0.3 );
    glVertex3f( -0.2,  0.1,  0.3 );
    glVertex3f( -0.2,  0.1, -0.3 );
    glVertex3f( -0.2, -0.1, -0.3 );
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(  0.2,  0.1,  0.3 );
    glVertex3f(  0.2,  0.1, -0.3 );
    glVertex3f( -0.2,  0.1, -0.3 );
    glVertex3f( -0.2,  0.1,  0.3 );
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(  0.2, -0.1, -0.3 );
    glVertex3f(  0.2, -0.1,  0.3 );
    glVertex3f( -0.2, -0.1,  0.3 );
    glVertex3f( -0.2, -0.1, -0.3 );
    glEnd();
}

void midpolygons()
{
    glBegin(GL_POLYGON);
    glVertex3f(  0.05, -0.09, -0.2 );
    glVertex3f(  0.05,  0.09, -0.2 );
    glVertex3f( -0.05,  0.09, -0.2 );
    glVertex3f( -0.05, -0.09, -0.2 );
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(  0.05, -0.09, 0.2 );
    glVertex3f(  0.05,  0.09, 0.2 );
    glVertex3f( -0.05,  0.09, 0.2 );
    glVertex3f( -0.05, -0.09, 0.1 );
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f( 0.05, -0.09, -0.2 );
    glVertex3f( 0.05,  0.09, -0.2 );
    glVertex3f( 0.05,  0.09,  0.2 );
    glVertex3f( 0.05, -0.09,  0.2);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f( -0.05, -0.09,  0.2 );
    glVertex3f( -0.05,  0.09,  0.2 );
    glVertex3f( -0.05,  0.09, -0.2 );
    glVertex3f( -0.05, -0.09, -0.2 );
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(  0.05,  0.09,  0.2 );
    glVertex3f(  0.05,  0.09, -0.2 );
    glVertex3f( -0.05,  0.09, -0.2 );
    glVertex3f( -0.05,  0.09,  0.2 );
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(  0.05, -0.09, -0.2 );
    glVertex3f(  0.05, -0.09,  0.2 );
    glVertex3f( -0.05, -0.09,  0.2 );
    glVertex3f( -0.05, -0.09, -0.2 );
    glEnd();
}


void smallpolygons()
{
    glBegin(GL_POLYGON);
    glVertex3f(  0.02, -0.03, -0.10 );
    glVertex3f(  0.02,  0.03, -0.10 );
    glVertex3f( -0.02,  0.03, -0.10);
    glVertex3f( -0.02, -0.03, -0.10 );
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(  0.02, -0.03, 0.10 );
    glVertex3f(  0.02,  0.03, 0.10 );
    glVertex3f( -0.02,  0.03, 0.10 );
    glVertex3f( -0.02, -0.03, 0.10 );
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f( 0.02, -0.03, -0.10);
    glVertex3f( 0.02,  0.03, -0.10);
    glVertex3f( 0.02,  0.03,  0.10);
    glVertex3f( 0.02, -0.03,  0.10);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f( -0.02, -0.03,  0.1 );
    glVertex3f( -0.02,  0.03,  0.1 );
    glVertex3f( -0.02,  0.03, -0.1);
    glVertex3f( -0.02, -0.03, -0.1 );
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(  0.02,  0.03,  0.1);
    glVertex3f(  0.02,  0.03, -0.1);
    glVertex3f( -0.02,  0.03, -0.1);
    glVertex3f( -0.02,  0.03,  0.1);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(  0.02, -0.03, -0.1);
    glVertex3f(  0.02, -0.03,  0.1);
    glVertex3f( -0.02, -0.03,  0.1);
    glVertex3f( -0.02, -0.03, -0.1);
    glEnd();
}

void polygon1()
{
    glPushMatrix();
    glColor3f (0,0.5,0);
    glTranslatef(-0.4,-0.2,-0.4);
    polygons();
    glPopMatrix();
}

void polygon2()
{
    glPushMatrix();
    glColor3f (0,0,0.6);
    glTranslatef(0.0,-0.2,-0.4);
    polygons();
    glPopMatrix();
}
void polygon21()
{
    glPushMatrix();
    glColor3f (0,0,0.6);
    glTranslatef(0.2,-0.2,-0.4);
    polygons();
    glPopMatrix();
}

void polygon3()
{
    glPushMatrix();
    glColor3f (0,0.5,0);
    glTranslatef(0.6,-0.2,-0.4);
    polygons();
    glPopMatrix();
}

void turbine()
{
    glPushMatrix();
    glColor3f (0.752941,0.752941,0.752941);
    glTranslatef(0.5,0,0.40);
    glRotatef(90,0.1,0.0,0);
    glScalef(0.5,1,1);
    polygons();
    glPopMatrix();
}

void blue()
{
    glPushMatrix();
    glColor3f (0.0,0.0,0.6);
    glTranslatef(-0.4,0.1,0.4);
    glScaled(1,4,1);
    polygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f (0.0,0.0,0.6);
    glTranslatef(0.0,0.1,0.4);
    glScaled(1,4,1);
    polygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f (0.0,0.0,0.6);
    glTranslatef(0.2,0.1,0.4);
    glScaled(1,4,1);
    polygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f (0.0,0.0,0.6);
    glTranslatef(0.6,0.1,0.4);
    glScaled(1,4,1);
    polygons();
    glPopMatrix();
}

void middle()
{
    glColor3f(0.2,0.2,0.2);
    glRotatef(90,1.0,0.0,0.0);
    glTranslatef(-0.4,0.0,-0.0);
    polygons();
    glPopMatrix();

    glColor3f(0.0,0.0,0.5);
    glRotatef(180,0.0,0.0,0.0);
    glTranslatef(-0.4,0.0,0.0);
    polygons();
    glPopMatrix();

    glColor3f(0.0,0.0,0.5);
    glRotatef(-180,0.0,1.0,0.0);
    glTranslatef(0.2,0.0,0.0);
    polygons();
    glPopMatrix();

    glColor3f(0.2,0.2,0.2);
    glRotatef(-180,0.0,1.0,0.0);
    glTranslatef(-0.4,0.0,0.0);
    polygons();
    glPopMatrix();
}

void road()
{
    glColor3f (0,0,0);
    glTranslatef(0.8,0.0,0.4);
    glRotatef(90,0.0,1.0,0.0);
    midpolygons();
    glPopMatrix();

    glColor3f (0,0,0);
    glTranslatef(0.0,0.0,-0.4);
    glRotatef(180,0.0,1.0,0.0);
    midpolygons();
    glPopMatrix();

    glColor3f (0,0,0);
    glTranslatef(0.0,0.0,0.3);
    glRotatef(180,0.0,1.0,0.0);
    midpolygons();
    glPopMatrix();    //
}

void bridge()
{
    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.2,0.13,0.40);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.3,0.13,0.40);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.4,0.13,0.40);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.5,0.13,0.40);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.6,0.13,0.40);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.6,0.13,0.40);
    smallpolygons();
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.7,0.13,0.40);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.8,0.13,0.40);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.999,0.15,0.1);
    glRotatef(10,1,0,0);
    polygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.001,0.15,0.1);
    glRotatef(10,1,0,0);
    polygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.7,0.15,0.2);
    glRotatef(15,1,0,0);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.6,0.15,0.2);
    glRotatef(15,1,0,0);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.5,0.15,0.2);
    glRotatef(15,1,0,0);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.4,0.15,0.2);
    glRotatef(15,1,0,0);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.3,0.15,0.2);
    glRotatef(15,1,0,0);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0,0.0,0.6);
    glTranslatef(0.6,0.10,0.1);
    glRotatef(15,1,0,0);
    polygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0,0.0,0.6);
    glTranslatef(0.4,0.10,0.1);
    glRotatef(15,1,0,0);
    polygons();
    glPopMatrix();
}

void backbridge()
{
    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.9,-0.12,0.45);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.0,-0.12,0.45);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.1,-0.12,0.45);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.2,-0.12,0.45);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.3,-0.12,0.45);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.4,-0.12,0.45);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.5,-0.12,0.45);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.6,-0.12,0.45);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.7,-0.12,0.45);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.8,-0.12,0.45);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.9,-0.12,0.45);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.9,-0.12,0.60);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.0,-0.12,0.60);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.1,-0.12,0.60);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.2,-0.12,0.60);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.3,-0.12,0.60);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.4,-0.12,0.60);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.5,-0.12,0.60);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.6,-0.12,0.60);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.7,-0.12,0.60);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.8,-0.12,0.60);
    smallpolygons();
    glPopMatrix();
}

void bridgeside()
{
    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.1,0.0,1.10);
    glRotatef(90,0,1,0);
    polygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.1,0.0,-0.4);
    glRotatef(90,0,1,0);
    polygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.5,0.0,1.0);
    glRotatef(180,0,0,1);
    polygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.4,0.0,-0.4);
    glRotatef(90,0,1,0);
    polygons();
    glPopMatrix();
}

void tree()
{
    glColor3f(0.0,0.0,0.0);
    glPushMatrix();
    glTranslatef(0.4,0.6,-0.25);
    glRotatef(90,0,0,1);
    glScalef(0.25,2.0,0.25);
    glutSolidCube(0.15);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(0.3,0.6,-0.25);
    glScalef(0.1,0.1,0.1);
    glutSolidSphere(0.6,10,10);
    glPopMatrix();

    glColor3f(0.55,0.47,0.14);
    glPushMatrix();
    glTranslatef(0.4,0.4,-0.05);
    glRotatef(90,0,0,1);
    glScalef(1.20,2.0,1.20);
    glutSolidCube(0.15);
    glPopMatrix();
}
void Lefttree()
{
        glPushMatrix();
        glTranslatef(-0.01,0.0,1.0);
        tree();
        glPopMatrix();
}

void tree1()
{
     glPushMatrix();
    glColor3f(1,1,0);
    glTranslatef(0.3,0.6,-0.25);
    glScalef(0.1,0.1,0.1);
    glutSolidSphere(0.6,10,10);
    glPopMatrix();
}

void Lefttree1()
{
        glPushMatrix();
        glTranslatef(-0.01,0.0,1.0);
        tree1();
        glPopMatrix();
}

GLfloat ys=0.0,xs=0.0,zs=0.0;

void light()
{
    if(dash)
    {
        tree1();
        Lefttree1();
    }
}

void line()
{
if(dash)
  {
    glPushMatrix();
    glTranslatef(ys,0.0,0.0);
    glColor3f(0.9,0.9,0.9);
    glLineWidth(2);
    glRotatef(10,0,0,1);
    glBegin(GL_LINES);
    glVertex3f(0.00,0.25,0.35);
    glVertex3f(0.05,0.25,0.35);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0,xs,0.0);
    glColor3f(0.9,0.9,0.9);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex3f(0.49,0.2,0.35);
    glVertex3f(0.49,0.15,0.35);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(zs,0.0,0.0);
    glColor3f(0.9,0.9,0.9);
    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex3f(0.50,0.70,0.35);
    glVertex3f(0.45,0.70,0.35);
    glEnd();
    glPopMatrix();
  }
}

void flow()
{
    glPushMatrix();
    glTranslatef(0.00,0.0,0.30);
    line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.00,0.0,0.32);
    line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.00,0.0,0.335);
    line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.00,0.0,0.28);
    line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.00,0.0,0.22);
    line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.00,0.0,0.20);
    line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.00,0.0,0.18);
    line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.00,0.0,0.12);
    line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.00,0.0,0.10);
    line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.00,0.0,0.08);
    line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.00,0.0,0.02);
    line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.00,0.0,-0.02);
    line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.00,0.0,-0.08);
    line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.00,0.0,-0.1);
    line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.00,0.0,-0.12);
    line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.00,0.0,-0.18);
    line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.00,0.0,-0.20);
    line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.00,0.0,-0.22);
    line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.00,0.0,-0.24);
    line();
    glPopMatrix();
}

void idle()
{
    ys+=0.001;

    if(ys>0.5)
    {
        ys=0.2;
    }

    xs+=0.001;

    if(xs>0.5)
    {
        xs=-0.1;
    }

    zs+=0.001;

    if(zs>0.2)
    {
        zs=0.05;
    }

    glutPostRedisplay();
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glClearColor(1.0,1.0,1.0,1.0);

  glLoadIdentity();

  glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );

    polygon1();
    polygon2();
    polygon21();
    polygon3();

    blue();
    middle();
    bridge();

    road();
    bridgeside();
    light();
    line();
    flow();

    tree();
    Lefttree();
    turbine();

    glFlush();
    glutSwapBuffers();
}

void specialKeys( int key, int x, int y )
{
    if (key == GLUT_KEY_RIGHT)
    rotate_y += 5;

    else if (key == GLUT_KEY_LEFT)
    rotate_y -= 5;

    else if (key == GLUT_KEY_UP)
    rotate_x += 5;

    else if (key == GLUT_KEY_DOWN)
    rotate_x -= 5;

    glutPostRedisplay();
}
void mykey(unsigned char key,int x,int y)
{
    if(key=='o')
    {
        dash=true;
    }

    if(key=='c')
    {
        dash=false;
    }

    glutPostRedisplay();
    display();
}

int main(int argc, char* argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutCreateWindow("HYDRO ELECTRIC DAM");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(mykey);
    glutIdleFunc(idle);

    glutMainLoop();
    return 0;
}
