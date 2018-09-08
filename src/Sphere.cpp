#include "Sphere.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Sphere::Sphere(GLfloat radius, Vec3 pos, std::string texPath) : Object(texPath, pos), radius(radius) {
    // glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_CULL_FACE);

    obj = gluNewQuadric();
    make_tex(tex);
}

void Sphere::make_tex(GLuint &tex)
{
    int WIDTH = 2048;
    int HEIGHT = 1024;
    int channels = 0;
    unsigned char *data = stbi_load(texPath.c_str(), &WIDTH, &HEIGHT, &channels, 3);
    // unsigned char data[SIZE][SIZE][3];
    // for (int y = 0; y < SIZE; y++) {
    //     for (int x = 0; x < SIZE; x++) {
    //         unsigned char *p = data[y][x];
    //         p[1] = p[2] = (x ^ y) & 8 ? 255 : 0;
    //         p[0] = 0;
    //     }
    // }
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, WIDTH, HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, (const GLvoid *) data);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    
    // when texture area is small, bilinear filter the closest mipmap
    // glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
    //                 GL_LINEAR_MIPMAP_NEAREST );
    // // when texture area is large, bilinear filter the original
    // glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

    // the texture wraps over at the edges (repeat)
    // glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    // glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
}

void Sphere::Render() {
    glPushMatrix();
    
    // float x=0, y=2, z=0;
    glClearColor(0.0, 0.0, 0.0, 1);
    // glClear(GL_DEPTH_BUFFER_BIT);

    // glTranslatef(-x, -y, -z);
    glRotatef(angle, rot.X(), rot.Y(), rot.Z());
    // glTranslatef(x, y, z);
    glScalef(scale.X(), scale.Y(), scale.Z());
    glTranslatef(pos.X(), pos.Y(), pos.Z());
    // glutSolidSphere(radius, 50, 50);


    // glColor3f(1.0, 1.0, 1.0);
    gluQuadricDrawStyle(obj, GLU_FILL);
    glBindTexture(GL_TEXTURE_2D, tex);
    gluQuadricTexture(obj, GL_TRUE);
    gluQuadricNormals(obj, GLU_SMOOTH);
    gluSphere(obj, radius, 32, 16);

    // Unbind
    glBindTexture(GL_TEXTURE_2D, 0);

    glPopMatrix();

 
    // glMatrixMode(GL_MODELVIEW);
    // glLoadIdentity();
    // glTranslatef(0.0, 0.0,-2.0);
    // glRotatef(45, 0, 1, 0);
 
    // glColor3f(0.0,1.0,0.0);
    // gluQuadricDrawStyle(obj, GLU_FILL);
    // glBindTexture(GL_TEXTURE_2D, tex);
    // gluQuadricTexture(obj, GL_TRUE);
    // gluQuadricNormals(obj, GLU_SMOOTH);
    // gluSphere(obj, 1.0, 32, 16);
 
    // glutSwapBuffers();
}