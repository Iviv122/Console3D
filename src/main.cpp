#include <iostream>
#include <cmath>
#include <vector>
#include <thread>
#include <chrono>


#include "Screen.hpp"
#include "ScreenRender.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Cube.hpp"
#include "Pyramid.hpp" 
#include "Face.hpp" 
#include "Line.hpp" 

int main(int argc, char const *argv[])
{
    Screen *s = new Screen(50, 50);
    Shapes *r = new Shapes(s);
    
    Model m = Cube();

    Vector3 offset = Vector3(0, 0, 11);
    m.Move(offset);
    m.Scale(10);
    
    float a = 3;
   
    while (true)
    {
        s->Fill(' ');

        DrawCube(r,m,'x');
        m.RotateX(0.1); 
        m.RotateY(0.15); 
        //m.RotateZ(0.15+sin(a)*0.1);

        s->Print();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        a += 0.5;
    }

    return 0;
}
