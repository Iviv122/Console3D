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
    uint width = 0;    
    uint height = 0;

    std::cout <<"enter preferable screen width: ";
    std::cin >> width;

    if(width <= 0){
        std::cout << "incorect width \n";
        return 1;
    }

    std::cout <<"enter preferable screen height: ";
    std::cin >> height;

    if(width <= 0){
        std::cout << "incorect height \n";
        return 1;
    }

    bool isometric = false;

    std::cout << "enter 0 if you want isometric look. else perspective: ";
    std::cin >> isometric; 

    Screen *s = new Screen(width, height);
    
    Shapes *r = new Shapes(s,isometric);
    Model m = Cube(); 

    Vector3 offset = Vector3(0, 0, 11);
    m.Move(offset);
    m.Scale(8);
    
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
        std::cout << isometric << "\n";
    }

    return 0;
}
