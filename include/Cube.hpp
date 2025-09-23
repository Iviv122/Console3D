#include <iostream>
#include <vector>

#include "Vector4.hpp"
#include "Vector2.hpp"
#include "Model.hpp"
#include "ScreenRender.hpp"

#pragma once

std::vector<std::vector<int>> CubeFaces = {
    {0, 1, 2, 3}, // front
    {1, 5, 6, 2}, // right
    {5, 4, 7, 6}, // back
    {4, 0, 3, 7}, // left
    {3, 2, 6, 7}, // top
    {4, 5, 1, 0}  // bottom
};

Model Cube()
{
    return Model(
        {
            Vector4(-0.5, -0.5, -0.5,1), // 0
            Vector4(0.5, -0.5, -0.5,1),  // 1
            Vector4(0.5, 0.5, -0.5,1),   // 2
            Vector4(-0.5, 0.5, -0.5,1),  // 3
            Vector4(-0.5, -0.5, 0.5,1),  // 4
            Vector4(0.5, -0.5, 0.5,1),   // 5
            Vector4(0.5, 0.5, 0.5,1),    // 6
            Vector4(-0.5, 0.5, 0.5,1)    // 7
        },
        Vector4(0, 0, 0));
}
void DrawCube(Shapes *r, Model cube, char c)
{
    for (int i = 0; i < CubeFaces.size(); i++)
    {
        r->DrawPlane(
            cube.pivot+cube.vertex[CubeFaces[i][0]],
            cube.pivot+cube.vertex[CubeFaces[i][1]],
            cube.pivot+cube.vertex[CubeFaces[i][2]],
            cube.pivot+cube.vertex[CubeFaces[i][3]],
            c+i);
    }
}