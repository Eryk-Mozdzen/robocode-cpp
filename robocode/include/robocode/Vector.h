#pragma once

#include <ostream>

namespace robocode {

struct Vector {
    double x;
    double y;

    static const Vector X;
    static const Vector Y;

    Vector();
    Vector(const double x, const double y);

    Vector operator+(const Vector &other) const;
    Vector operator-(const Vector &other) const;
    double operator*(const Vector &other) const;
    Vector operator*(const double num) const;
    Vector operator/(const double num) const;

    void operator+=(const Vector &other);
    void operator-=(const Vector &other);
    void operator*=(const double num);
    void operator/=(const double num);

    float len() const;
};

Vector operator*(const double num, const Vector &vec);
Vector operator/(const double num, const Vector &vec);

std::ostream & operator<<(std::ostream &stream, const Vector &vec);

}
