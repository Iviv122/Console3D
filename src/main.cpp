#include <iostream>
#include <cmath>

#include <unistd.h>

#include "Screen.hpp"
#include "ScreenRender.hpp"
#include "Vector2.hpp"

int main(int argc, char const *argv[])
{
    Screen *s = new Screen(80, 20,' ,');
    ScreenRender *r = new ScreenRender(s);

    Vector2 *pos = new Vector2(0, 0);
    Vector2 *pos1 = new Vector2(19, 7);

    Vector2 *pos2 = new Vector2(9, 9);

    s->Fill(' ');
    r->DrawTriangle(pos, pos1, pos2, 'x');
    s->Print();

    return 0;
}
