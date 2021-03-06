#ifndef OBJECT_H
#define OBJECT_H

#include "Vec3.h"
class Object {
public:
    Object(std::string texPath, Vec3 pos = {0, 0, 0}, Vec3 scale = {1, 1, 1}, Vec3 rot = {0, 0, 0});

    void Translate(Vec3 tr);
    void Scale(Vec3 sc);
    void Rotate(GLdouble ang, Vec3 r);

    virtual void Render() = 0;

    Vec3 pos;
    Vec3 scale;
    Vec3 rot;

    GLdouble angle;

    GLuint tex;
    GLUquadric* obj;
    std::string texPath;
    // unsigned char *data;
};

#endif /* OBJECT_H */