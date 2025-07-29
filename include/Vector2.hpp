#include <iostream>
#pragma once

struct Vector2
{
    float x;
    float y;
    Vector2(int x = 0, int y = 0)
        : x(x), y(y)
    {
    }

    Vector2 operator+(const Vector2 &a) const
    {
        return Vector2(a.x + x, a.y + y);
    }
    Vector2 operator-(const Vector2 &a) const
    {
        return Vector2(a.y - y, a.y - y);
    }
    Vector2 operator*(const float &a) const
    {
        return Vector2(x * a, y * a);
    }
    Vector2 operator/(const float &a) const
    {
        return Vector2(x / a, y / y);
    }
    bool operator==(const Vector2 &a) const
    {
        return (x == a.x && y == a.y);
    }
};
