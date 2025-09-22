#include <iostream>
#include <cmath>
#include <vector>

#include <unistd.h>

#include "Screen.hpp"
#include "ScreenRender.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Cube.hpp"
#include "Pyramid.hpp" 


int main(int argc, char const *argv[])
{
    Screen *s = new Screen(50, 30);
    Shapes *r = new Shapes(s);
    
    //Model m = Cube();
    Model m = Piramid();


    Vector3 offset = Vector3(0, 0, 1);
    m.Move(offset);
    m.Scale(10);
   
    float a = 3;

    while (true)
    {

        s->Fill(' ');

        DrawPyramid(r,m,'x');
        //DrawCube(r,m,'x');
        m.RotateX(0.1); 
        m.RotateY(0.2); 
        
        s->Print();
        usleep(1000 * 100);
        a += 0.5;
    }

    return 0;
}
