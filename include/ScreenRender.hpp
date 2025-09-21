#include "Screen.hpp"

#include "Vector3.hpp"
#include "Vector4.hpp"
#include <cmath>

#pragma once

class Shapes
{
private:
    Screen *s;

public:
    Shapes(Screen *s)
    {
        this->s = s;
    }
    void DrawLine(const Vector3 pos, const Vector3 pos1, const char &c)
    {
        float dx = pos1.x - pos.x;
        float dy = pos1.y - pos.y;
        float a = dy / dx;
        float y = 0;
        float x = 0;
        float step;

        if (abs(dx) >= abs(dy))
            step = abs(dx);
        else
            step = abs(dy);

        dx = dx / step;
        dy = dy / step;

        int i = 0;

        while (i <= step)
        {
            s->PlaceChar(pos.x + x, pos.y + y, c);
            x = x + dx;
            y = y + dy;
            i = i + 1;
        }
    }
    void DrawTriangle(const Vector3 pos, const Vector3 pos1, const Vector3 pos2, const char c)
    {
        DrawLine(pos, pos1, c);
        DrawLine(pos1, pos2, c);
        DrawLine(pos2, pos, c);
    }
    void DrawSquare(Vector3 pos, Vector3 pos1, Vector3 pos2, Vector3 pos3, const char c)
    {
        DrawLine(pos, pos1, c);
        DrawLine(pos1, pos2, c);
        DrawLine(pos2, pos3, c);
        DrawLine(pos3, pos, c);
    }
    // Isometric if you need it...
    Vector3 Translate(Vector4 point)
    {
        return Vector3((point.x - point.z) / sqrt(2), (point.x + point.y * 2 + point.z) / sqrt(6), point.w);
    }

    void DrawPlane(Vector4 pos, Vector4 pos1, Vector4 pos2, Vector4 pos3, const char c)
    {
        DrawLine(Translate(pos), Translate(pos1), c);
        DrawLine(Translate(pos1), Translate(pos2), c);
        DrawLine(Translate(pos2), Translate(pos3), c);
        DrawLine(Translate(pos3), Translate(pos), c);
    }
    ~Shapes()
    {
    }
};
