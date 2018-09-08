#ifndef VEC3_H
#define VEC3_H

#include <GL/glut.h>
#include <iostream>
#include <initializer_list>

class Vec3 {
public:
    Vec3();
    Vec3(std::initializer_list<GLdouble> list);
    Vec3(GLdouble x, GLdouble y, GLdouble z);

    // void Rotate(GLdouble rad);
    // Vec3 GetRotated(GLdouble rad) const;
    // GLdouble Mag() const;
    // GLdouble L0Mag() const;
    // void SetMag(GLdouble mag);
    // static GLdouble EuclidianDist(const Vec3 &a, const Vec3 &b);
    // static GLdouble ManhattamDist(const Vec3 &a, const Vec3 &b);
    // static GLdouble Angle(const Vec3 &a, const Vec3 &b);

    GLdouble X() const;
    GLdouble Y() const;
    GLdouble Z() const;
    void Set(GLdouble x, GLdouble y, GLdouble z);
    void Rotated(Vec3 v, GLdouble rad);

    Vec3 operator+(const Vec3 &a) const;
    Vec3 operator+(const Vec3 &&a) const;
    Vec3 operator-(const Vec3 &a) const;
    Vec3 operator-(const Vec3 &&a) const;
    Vec3 operator-() const;
    Vec3 operator*(GLdouble f) const;
    Vec3 operator/(GLdouble f) const;

    Vec3& operator=(const Vec3 &a) = default;
    Vec3& operator+=(const Vec3 &a);
    Vec3& operator+=(const Vec3 &&a);
    Vec3& operator-=(const Vec3 &a);
    Vec3& operator-=(const Vec3 &&a);
    Vec3& operator*=(const Vec3 &a);
    Vec3& operator*=(const Vec3 &&a);
    Vec3& operator*=(GLdouble f);
    bool operator==(const Vec3 &a);
    friend std::ostream& operator<<(std::ostream& os, const Vec3& a);

private:
    GLdouble x;
    GLdouble y;
    GLdouble z;
};

#endif /* VEC3_H */
