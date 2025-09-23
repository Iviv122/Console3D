#include <iostream>
#pragma once

// vector3 is both arrow, point and matrix :D
/*
[1]*[x]
[1]*[y] => [x,y,z]
[1]*[z]
*/
struct Vector3
{
    float x;
    float y;
    float z;
    Vector3(float x = 0, float y = 0, float z = 0)
        : x(x), y(y), z(z)
    {
    }
    Vector3 operator+(const Vector3 &a) const
    {
        return Vector3(a.x + x, a.y + y, a.z + z);
    }
    Vector3 operator-(const Vector3 &a) const
    {
        return Vector3(a.x - x, a.y - y, a.z - z);
    }
    Vector3 operator*(const float &a) const
    {
        return Vector3(x * a, y * a, z * a);
    }
    Vector3 operator*(const Vector3 &a) const
    {
        return Vector3(x * a.x, y * a.y, z * a.z);
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
Vector3 add(Vector3 *a, Vector3 *b)
{
    return Vector3(a->x + b->x, a->y + b->y, a->z + b->z);
}
Vector3 Multiply(Vector3 *a, float b)
{
    return Vector3(a->x * b, a->y * b, a->z * b);
}
float Dot(Vector3 a, Vector3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
Vector3 Cross(Vector3 a, Vector3 b)
{
    return Vector3(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x);
}