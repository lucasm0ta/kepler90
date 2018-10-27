#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include "Sphere.h"
#include<vector>

float theta = 0.1;
int win_id = 0;
std::vector<Object*> objArray;

GLfloat px = 0, py = 0, pz = 2;

void ortoProjection() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4.0f, 4.0f, -4.0f, 4.0f, -4.0f, 4.0f);
}

void perspectProjection() {
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glLoadIdentity();
    gluLookAt(px, py, pz, 0, 0, 0, 0, 1, 0);

    glMatrixMode(GL_PROJECTION);
    // glPushMatrix();
    glLoadIdentity();
    gluPerspective(100, 1, 0.1, 1000);
    glPopMatrix();

    // glMatrixMode(GL_MODELVIEW);
    // glPopMatrix();
}

void createScene(void) {

    perspectProjection();
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1, 1, 1, 1);
    // ortoProjection();
    // glColor3f(1, 0, 0);

    // glPushMatrix();
    // glRotatef(theta, 0, 0, 1);
    // glScalef(1, 1, 1);
    // glTranslatef(0, 0, 0);
    // glutWireSphere(1, 50, 50);
    // glPopMatrix();

    // glLoadIdentity();
    for (Object *obj: objArray) {
        obj->Rotate(0.01, {0, 1, 0});
        obj->Render();
    }

    
    // glPushMatrix();
    // // clear matrix
    // glLoadIdentity();
    // // apply rotations
    // glRotate3f(rotX, 1.0, 0.0, 0.0);
    // glRotate3f(rotY, 0.0, 1.0, 0.0);
    // glRotate3f(rotZ, 0.0, 0.0, 1.0);
    // // move the axes to the screen corner
    // glTranslatef(-3.0, -2.0, 0.0);
    // // draw our axes
    // glBegin(GL_LINES);
    // // draw line for x axis
    // glColor3f(1.0, 0.0, 0.0);
    // glVertex3f(0.0, 0.0, 0.0);
    // glVertex3f(1.0, 0.0, 0.0);
    // // draw line for y axis
    // glColor3f(0.0, 1.0, 0.0);
    // glVertex3f(0.0, 0.0, 0.0);
    // glVertex3f(0.0, 1.0, 0.0);
    // // draw line for Z axis
    // glColor3f(0.0, 0.0, 1.0);
    // glVertex3f(0.0, 0.0, 0.0);
    // glVertex3f(0.0, 0.0, 1.0);
    // glEnd();
    // // load the previous
    
    // glFlush();
    // glutPostRedisplay();

    theta += 0.01;
}
void keyboard_special(int  key, int x, int y) {
    switch (key) {
        case GLUT_KEY_RIGHT:
            std::cout<<"Para direita:" << py <<"\n";
            py += 0.05;
            break;
        case GLUT_KEY_LEFT:
            std::cout<<"Para esquerda:" << py <<"\n";
            py -= 0.05;
            break;
        case GLUT_KEY_UP:
            std::cout<<"Para cima:" << pz <<"\n";
            pz += 0.05;
            break;
        case GLUT_KEY_DOWN:
            std::cout<<"Para baixo:" << pz <<"\n";
            pz -= 0.05;
            break;
    }
}
void keyboard_keys(unsigned char key, int x, int y )
{
    switch (key) {
        case 27: // Escape key
            glutDestroyWindow (win_id);
            exit (0);
            break;
        case 'r':
            std::cout<<"Apertou R\n";
            break;
        case 'a':
            std::cout<<"Apertou A:" << px << "\n";
            px += 0.05;
            break;
        case 'd':
            std::cout<<"Apertou D:" << px << "\n";
            px -= 0.05;
            break;
    }
    glutPostRedisplay();
}
void update() {
    // glRotatef(0.1, 1, 0, 0);
    glFlush();
    glutPostRedisplay();
}

void resize(int w, int h)
{
    // if (!h)
	//     h = 1;
    // glViewport(0, 0, w, h);
    // glMatrixMode(GL_PROJECTION);
    // glLoadIdentity();
    // gluPerspective(90.0, 1.0 * w / h, 0.1, 100.0);
}

void init(void)
{
    Sphere *sp = new Sphere(1, {0, 0, 0});
    // sp->Scale({5, 5, 5});
    // sp->Translate({0, 0, -3});
    // static_cast<Object>(sp);
    objArray.push_back(sp);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    win_id = glutCreateWindow("Janelinha");

    glutDisplayFunc(createScene);

    glutSpecialFunc(&keyboard_special);
    glutKeyboardFunc(&keyboard_keys);
    glutIdleFunc(&update);
    // glutReshapeFunc(resize);

    init();

    glutMainLoop();
}