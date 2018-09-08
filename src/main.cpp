#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include "Sphere.h"
#include<vector>
enum class Projection {
    ORTHO = 1,
    PERSPECTIVE
};

Projection PROJ;

float theta = 0.1;
double vel = 1;
int win_id = 0;
std::vector<Object*> objArray;

GLfloat px = 300, py = 0, pz = 740;

void ortoProjection() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    double w = glutGet(GLUT_WINDOW_WIDTH);
    double h = glutGet(GLUT_WINDOW_HEIGHT);
    double ar = w / h;
    double left = -40;
    double bottom = -40;
    double size = 100;
    glOrtho(left, size, bottom, size * ar, -400.0f, 400.0f);
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
        double w = glutGet(GLUT_WINDOW_WIDTH);
        double h = glutGet(GLUT_WINDOW_HEIGHT);
        double ar = w / h;
        gluPerspective(10, ar, 0.1, 1000);
    glPopMatrix();

    // glMatrixMode(GL_MODELVIEW);
    // glPopMatrix();
}

void createScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // glClearColor(1, 1, 1, 1);

    glMatrixMode(GL_MODELVIEW);
    if (PROJ == Projection::ORTHO) {
        ortoProjection();
    } else {
        perspectProjection();
    }
    // glColor3f(1, 0, 0);

    // glPushMatrix();
    // glRotatef(theta, 0, 0, 1);
    // glScalef(1, 1, 1);
    // glTranslatef(0, 0, 0);
    // glutWireSphere(1, 50, 50);
    // glPopMatrix();

    // glLoadIdentity();
    for (Object *obj: objArray) {
        // obj->Rotate(0.01, {0.001, 0.001, 0});
        Vec3 pos = obj->pos;
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
}

void keyboard_special(int  key, int x, int y) {
    switch (key) {
        case GLUT_KEY_RIGHT:
            std::cout<<"Para direita:" << py <<"\n";
            py += vel;
            break;
        case GLUT_KEY_LEFT:
            std::cout<<"Para esquerda:" << py <<"\n";
            py -= vel;
            break;
        case GLUT_KEY_UP:
            std::cout<<"Para cima:" << pz <<"\n";
            pz += vel;
            break;
        case GLUT_KEY_DOWN:
            std::cout<<"Para baixo:" << pz <<"\n";
            pz -= vel;
            break;
    }
}

void keyboard_keys(unsigned char key, int x, int y ) {
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
            px += vel;
            break;
        case 'd':
            std::cout<<"Apertou D:" << px << "\n";
            px -= vel;
            break;
    }
    glutPostRedisplay();
}

void update() {
    // glMatrixMode(GL_PROJECTION);
    glRotatef(0.1, 1, 0, 0);
    glFlush();
    glutPostRedisplay();
}

void resize(int w, int h)
{
    if (!h) {
	    h = 1;
    }
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0, 1.0 * w / h, 0.1, 100.0);
}

void init(void)
{
    float d = 0;
    Sphere *sun = new Sphere(20, {0, 0, 0}, "../img/sun.jpg"); // 131
    d += 20;
    Sphere *kb = new Sphere(1.31, {d + 5.8, 0, 0}, "../img/jupiter.jpg");
    d += 1.51;
    Sphere *kc = new Sphere(1.18, {d + 1.8, 0, 0}, "../img/jupiter.jpg");
    d += 1.58;
    Sphere *ki = new Sphere(1.32, {d + 1.8, 0, 0}, "../img/jupiter.jpg");
    d += 3;
    Sphere *kd = new Sphere(2.88, {d + 1.8, 0, 0}, "../img/jupiter.jpg");
    d += 6;
    Sphere *ke = new Sphere(2.67, {d + 1.8, 0, 0}, "../img/jupiter.jpg");
    d += 6;
    Sphere *kf = new Sphere(2.89, {d + 1.8, 0, 0}, "../img/jupiter.jpg");
    d += 12;
    Sphere *kg = new Sphere(8.13, {d + 1.8, 0, 0}, "../img/jupiter.jpg");
    d += 20;
    Sphere *kh = new Sphere(11.32, {d + 1.8, 0, 0}, "../img/jupiter.jpg");
    // sp->Scale({5, 5, 5});
    // k1->Rotate(1, {0, 0, -3});
    // static_cast<Object>(sp);
    objArray.push_back(sun);
    objArray.push_back(kb);
    objArray.push_back(kb);
    objArray.push_back(kc);
    objArray.push_back(ki);
    objArray.push_back(kd);
    objArray.push_back(ke);
    objArray.push_back(kf);
    objArray.push_back(kg);
    objArray.push_back(kh);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_DEPTH);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 800);
    win_id = glutCreateWindow("Janelinha");

    glutDisplayFunc(createScene);

    glutSpecialFunc(&keyboard_special);
    glutKeyboardFunc(&keyboard_keys);
    glutIdleFunc(&update);
    // glutReshapeFunc(resize);

    init();

    glutMainLoop();
}