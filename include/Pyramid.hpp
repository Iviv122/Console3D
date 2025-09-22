#include <iostream>
#include <vector>

#include "Vector4.hpp"
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
        {Vector4(-0.5, -0.5, -.5, 1),
         Vector4(0.5, -0.5, -.5, 1),
         Vector4(0, 0.366, -.5, 1),
         Vector4(0, -0.211, .5, 1)},
        Vector4(0, 0, 0, 1));
}
void DrawPyramid(Shapes *r, Model pyramid, char c)
{
    for (int i = 0; i < PiramidFaces.size(); i++)
    {
        r->DrawPolygon(
            pyramid.pivot + pyramid.vertex[PiramidFaces[i][0]],
            pyramid.pivot + pyramid.vertex[PiramidFaces[i][1]],
            pyramid.pivot + pyramid.vertex[PiramidFaces[i][2]],
            c);
    }
}