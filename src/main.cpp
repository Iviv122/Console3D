#include <iostream>
#include <cmath>
#include <vector>

#include <unistd.h>

#include "Screen.hpp"
#include "ScreenRender.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Cube.hpp"


int main(int argc, char const *argv[])
{
    Screen *s = new Screen(81, 31);
    Shapes *r = new Shapes(s);
    
    Model m = Cube();
    Vector3 offset = Vector3(0, 0, 10);
    m.Move(offset);
    m.Scale(20);
    m.Scale(Vector3(2,0.5,1));
   
    float a = 3;

    while (true)
    {

        s->Fill(' ');

        DrawCube(r,m,'x');


        s->Print();
        usleep(1000 * 100);
        a += 0.5;
    }

    return 0;
}
