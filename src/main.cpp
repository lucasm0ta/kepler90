#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include "Sphere.h"
#include<vector>

float theta = 0.1;
int win_id = 0;
std::vector<Object*> objArray;


void translate2d(GLfloat dx, GLfloat dy) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(dx, dy, 0.0f);
    glPopMatrix();
}

void rotate2d(GLfloat rad) {
    // cx, cy;
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // glTranslatef(dx, dy, 0.0f);
}

void drawRect() {
    glColor3f(.5, .6, .1);
    glBegin(GL_QUADS);
        glVertex2f(0.6, 0.6);
        glVertex2f(0.6, 0.8);
        glVertex2f(0.8, 0.8);
        glVertex2f(0.8, 0.6);
    glEnd();
}

void drawTrangle() {
    glColor3f(.7, .6, .3);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.3, 0.4);
        glVertex2f(0.2, 0.2);
        glVertex2f(0.4, 0.4);
    glEnd();
}

void createScene(void) {

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    for (Object *obj: objArray) {
        obj->Render();
    }
    
    glFlush();
    glutPostRedisplay();

    theta += 0.1;
}
void keyboard_special(int  key, int x, int y) {
    switch (key) {
        case GLUT_KEY_RIGHT:
            std::cout<<"Para direita\n";
            break;
        case GLUT_KEY_LEFT:
            std::cout<<"Para esquerda\n";
            break;
        case GLUT_KEY_UP:
            std::cout<<"Para cima\n";
            break;
        case GLUT_KEY_DOWN:
            std::cout<<"Para baixo\n";
            break;
    }
}
void keyboardCB(unsigned char key, int x, int y )
{
    switch (key) {
        case 27: // Escape key
            glutDestroyWindow (win_id);
            exit (0);
            break;
    }
    glutPostRedisplay();
}
void rotating() {
    glRotatef(0.1, 1, 0, 0);
    glutPostRedisplay();
}

void resize(int w, int h)
{
    // if (!h)
	//     h = 1;
    // glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    // glLoadIdentity();
    gluPerspective(90.0, 1.0 * w / h, 0.1, 100.0);
}

void init(void)
{
    Sphere *sp = new Sphere(1, {0, 0, 0});
    sp->Scale({5, 5, 5});
    sp->Translate({0, 0, -3});
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
    glutKeyboardFunc(&keyboardCB);
    glutIdleFunc(&rotating);
    glutReshapeFunc(resize);

    init();

    glutMainLoop();
}