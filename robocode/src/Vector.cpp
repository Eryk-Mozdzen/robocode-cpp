#include <cmath>

#include <robocode/Vector.h>

namespace robocode {
    const Vector Vector::X(1, 0);
    const Vector Vector::Y(0, 1);

    Vector::Vector() : x{0}, y{0} {

    }

    Vector::Vector(const double x, const double y) : x{x}, y{y} {

    }

    Vector Vector::operator+(const Vector &other) const {
        return Vector(x+other.x, y+other.y);
    }

    Vector Vector::operator-(const Vector &other) const {
        return Vector(x-other.x, y-other.y);
    }

    double Vector::operator*(const Vector &other) const {
        return x*other.x + y*other.y;
    }

    Vector Vector::operator*(const double num) const {
        return Vector(x*num, y*num);
    }

    Vector Vector::operator/(const double num) const {
        return Vector(x/num, y/num);
    }

    void Vector::operator+=(const Vector &other) {
        x +=other.x;
        y +=other.y;
    }

    void Vector::operator-=(const Vector &other) {
        x -=other.x;
        y -=other.y;
    }

    void Vector::operator*=(const double num) {
        x *=num;
        y *=num;
    }

    void Vector::operator/=(const double num) {
        x /=num;
        y /=num;
    }

    float Vector::len() const {
        return std::sqrt(x*x + y*y);
    }

    Vector operator*(const double num, const Vector &vec) {
        return Vector(num*vec.x, num*vec.y);
    }

    Vector operator/(const double num, const Vector &vec) {
        return Vector(vec.x/num, vec.y/num);
    }

    std::ostream & operator<<(std::ostream &stream, const Vector &vec) {
        stream << vec.x << " " << vec.y;
        return stream;
    }
}
