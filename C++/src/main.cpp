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
#include "Face.hpp" 
#include "Line.hpp" 

int main(int argc, char const *argv[])
{
    Screen *s = new Screen(50, 30);
    Shapes *r = new Shapes(s);
    
    //Model m = Cube();
    Model m = Piramid();
    //Model m = Face();
    //std::vector<Vector4> ver;
    //for (float i = -1; i < 1; i+=0.1)
    //{
    //    ver.push_back(Vector4(i,0,0,1));
    //}
    
    //Model m = Line(ver);

    Vector3 offset = Vector3(0, 0, 1);
    m.Move(offset);
    m.Scale(10);
   
    float a = 3;

    while (true)
    {
        s->Fill(' ');

        //DrawLine(r,m,'x');
        //DrawFace(r,m,'x');
        DrawPyramid(r,m,'x');
        //DrawCube(r,m,'x');
        m.RotateX(0.1); 
        m.RotateY(0.2); 
        //m.RotateZ(0.2);

        s->Print();
        usleep(1000 * 100);
        a += 0.5;
    }

    return 0;
}
