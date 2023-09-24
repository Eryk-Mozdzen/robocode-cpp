#pragma once

namespace robocode {

struct Vector {
    float x;
    float y;

    static const Vector X;
    static const Vector Y;

    Vector();
    Vector(const float x, const float y);

    Vector operator+(const Vector &other) const;
    Vector operator-(const Vector &other) const;
    float operator*(const Vector &other) const;
    Vector operator*(const float num) const;
    Vector operator/(const float num) const;

    void operator+=(const Vector &other);
    void operator-=(const Vector &other);
    void operator*=(const float num);
    void operator/=(const float num);

    float len() const;
};

Vector operator*(const float num, const Vector &vec);
Vector operator/(const float num, const Vector &vec);

}
