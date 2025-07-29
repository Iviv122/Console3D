#include "Screen.hpp"

#pragma once

class ScreenRender
{
private:
    Screen *s;

public:
    ScreenRender(Screen *s)
    {
        this->s = s;
    }
    void DrawLine(const Vector2 *pos,const Vector2 *pos1,const char &c)
    {
        float dx = pos1->x - pos->x;
        float dy = pos1->y - pos->y;
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
            s->PlaceChar(pos->x + x, pos->y + y, c);
            x = x + dx;
            y = y + dy;
            i = i + 1;
        }
    }
    void DrawTriangle(Vector2 *pos, Vector2 *pos1, Vector2 *pos2,const char c)
    {
        DrawLine(pos, pos1, c);
        DrawLine(pos1, pos2, c);
        DrawLine(pos2, pos, c);
    }
    ~ScreenRender()
    {
    }
};
