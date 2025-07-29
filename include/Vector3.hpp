#include <iostream>
#pragma once

struct Vector3
{
    float x;
    float y;
    float z;
    Vector3(int x = 0, int y = 0, int z = 0)
        : x(x), y(y), z(z)
    {
    }

    Vector3 operator+(const Vector3 &a) const
    {
        return Vector3(a.x + x, a.y + y,a.z + z);
    }
    Vector3 operator-(const Vector3 &a) const
    {
        return Vector3(a.y - y, a.y - y,a.z - z);
    }
    Vector3 operator*(const float &a) const
    {
        return Vector3(x * a, y * a, z * a);
    }
    Vector3 operator/(const float &a) const
    {
        return Vector3(x / a, y / a, z / a);
    }
    bool operator==(const Vector3 &a) const
    {
        return (x == a.x && y == a.y && z == a.z);
    }
};
