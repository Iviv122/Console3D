#include <iostream>
#pragma once

// vector4 is both arrow, point and matrix :D
/*
[1]*[x]
[1]*[y] => [x,y,z,w]
[1]*[z]
[1]*[w]
*/
struct Vector4
{
    float x;
    float y;
    float z;
    float w;
    Vector4(float x = 0, float y = 0, float z = 0,float w = 0)
        : x(x), y(y), z(z), w(w)
    {
    }
    Vector4 operator+(const Vector4 &a) const
    {
        return Vector4(a.x + x, a.y + y, a.z + z,a.w+w);
    }
    Vector4 operator-(const Vector4 &a) const
    {
        return Vector4(a.y - y, a.y - y, a.z - z,a.w-w);
    }
    Vector4 operator*(const float &a) const
    {
        return Vector4(x * a, y * a, z * a,w*a);
    }
    Vector4 operator*(const Vector4 &a) const
    {
        return Vector4(x * a.x, y * a.y, z * a.z,w*a.w);
    }
    Vector4 operator/(const float &a) const
    {
        return Vector4(x / a, y / a, z / a, w/a);
    }
    bool operator==(const Vector4 &a) const
    {
        return (x == a.x && y == a.y && z == a.z && w == a.w);
    }
};
Vector4 Add(Vector4 *a, Vector4 *b)
{
    return Vector4(a->x + b->x, a->y + b->y, a->z + b->z,a->w + b->w);
}
Vector4 Multiply(Vector4 *a, float b)
{
    return Vector4(a->x *b, a->y *b, a->z *b,a->w*b);
}
