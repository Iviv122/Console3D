#include <iostream>
#include <vector>

#include "Vector4.hpp"
#include "Vector2.hpp"
#include "Model.hpp"
#include "ScreenRender.hpp"

#pragma once

std::vector<std::vector<int>> PiramidFaces = {
    {0, 1, 2},
    {0, 3, 2},
    {0, 1, 3},
    {3, 2, 1}};

Model Piramid()
{
    return Model(
        {Vector4(-0.5, -0.5, -.5,1),
         Vector4(0.5, -0.5, -.5,1),
         Vector4(0, 0.366, -.5,1),
         Vector4(0, -0.211, .5,1)},
        Vector4(0, 0, 0, 1));
}
void DrawPiramid(Shapes *r, Model cube, char c)
{
    for (int i = 0; i < PiramidFaces.size(); i++)
    {
        r->DrawPolygon(
            cube.pivot + cube.vertex[PiramidFaces[i][0]],
            cube.pivot + cube.vertex[PiramidFaces[i][1]],
            cube.pivot + cube.vertex[PiramidFaces[i][2]],
            c);
    }
}