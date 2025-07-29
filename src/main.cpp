#include <iostream>
#include <cmath>
#include <vector>

#include <unistd.h>

#include "Screen.hpp"
#include "ScreenRender.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Model.hpp"


std::vector<Vector3> cube = {
    // front
    Vector3(-1, 0, 0),
    Vector3(1, 0, 0),
    Vector3(1, 1, 0),
    Vector3(-1, 1, 0),

    // left
    Vector3(-1, 0, 0),
    Vector3(-1, 0, 1),
    Vector3(-1, 1, 1),
    Vector3(-1, 1, 0),

    // right
    Vector3(1, 0, 0),
    Vector3(1, 0, 1),
    Vector3(1, 1, 1),
    Vector3(1, 1, 0),

    // back
    Vector3(-1, 0, 1),
    Vector3(1, 0, 1),
    Vector3(1, 1, 1),
    Vector3(-1, 1, 1)
};


Model m = Model(cube,Vector3(1,1,1));

int main(int argc, char const *argv[])
{
    Screen *s = new Screen(81, 31);
    Shapes *r = new Shapes(s);


    Vector3 offset = Vector3(0, 0, 3);
    for (size_t i = 0; i < 13; i++)
    {
        cube[i] = cube[i] + offset;
    }
    float scale = 15;
    for (size_t i = 0; i < 13; i++)
    {
        cube[i].x *= scale;
        cube[i].y *= scale;
    }
    float a = 1;
    while (true)
    {

        s->Fill('.');

        for (size_t i = 0; i < 12; i += 4)
        {
            r->DrawPlane(cube[i]+sin(a)*5, cube[i + 1]+sin(a)*5, cube[i + 2]+sin(a)*5, cube[i + 3]+sin(a)*5, 'X');
        }

        s->Print();
        usleep(1000*100);
        a+=0.5;
    }

    return 0;
}
