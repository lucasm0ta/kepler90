#include "Vec3.h"

#include <cmath>
Vec3::Vec3() : x(0), y(0), z(0){
}

Vec3::Vec3(std::initializer_list<GLdouble> initList) {
    if (initList.size() == 3) {
        x = initList.begin()[0];
        y = initList.begin()[1];
        z = initList.begin()[2];
    }
}

Vec3::Vec3 (GLdouble _x, GLdouble _y, GLdouble _z) : x(_x), y(_y), z(_z){
}

GLdouble Vec3::X() const {
    return x;
}

GLdouble Vec3::Y() const {
    return y;
}

GLdouble Vec3::Z() const {
    return z;
}

void Vec3::Set(GLdouble _x, GLdouble _y, GLdouble _z) {
    x = _x;
    y = _y;
    z = _z;
}

void Vec3::Rotated(Vec3 v, GLdouble rad) {
    float _x = std::cos(rad) * x - std::sin(rad) * y;
    float _y = std::sin(rad) * x + std::cos(rad) * y;
    x = _x;
    y = _y;
}

Vec3 Vec3::operator+(const Vec3 &a) const {
    return Vec3(a.x + x, a.y + y, a.z + z);
}

Vec3 Vec3::operator+(const Vec3 &&a) const {
    return Vec3(a.x + x, a.y + y, a.z + z);
}

Vec3 Vec3::operator-(const Vec3 &a) const {
    return Vec3(x - a.x, y - a.y, z - a.z);
}

Vec3 Vec3::operator-(const Vec3 &&a) const {
    return Vec3(x - a.x, y - a. y, z - a.z);
}

Vec3 Vec3::operator-() const {
    return Vec3(-x, -y, -z);
}

Vec3& Vec3::operator+=(const Vec3 &a) {
    x += a.x;
    y += a.y;
    z += a.z;
    return *this;
}

Vec3& Vec3::operator+=(const Vec3 &&a) {
    x += a.x;
    y += a.y;
    z += a.z;
    return *this;
}

Vec3& Vec3::operator-=(const Vec3 &a) {
    x -= a.x;
    y -= a.y;
    z -= a.z;
    return *this;
}

Vec3& Vec3::operator-=(const Vec3 &&a) {
    x -= a.x;
    y -= a.y;
    z -= a.z;
    return *this;
}

Vec3& Vec3::operator*=(const Vec3 &a) {
    x *= a.x;
    y *= a.y;
    z *= a.z;
    return *this;
}

Vec3& Vec3::operator*=(const Vec3 &&a) {
    x *= a.x;
    y *= a.y;
    z *= a.z;
    return *this;
}

Vec3& Vec3::operator*=(GLdouble f) {
    x *= f;
    y *= f;
    z *= f;
    return *this;
}

bool Vec3::operator==(const Vec3 &a) {
    return (x == a.x && y == a.y && z == a.z);
}

Vec3  Vec3::operator*(GLdouble f) const {
    return Vec3(x * f, y * f, z * f);
}

Vec3  Vec3::operator/(GLdouble f) const {
    if (f != 0) {
        return Vec3(x / f, y / f, z / f);
    } else {
        return Vec3(x, y, z);
    }
}

std::ostream& operator<<(std::ostream& os, const Vec3& a) {
    os << '(' << a.x << ',' << a.y << ',' << a.z << ')';
    return os;
}
