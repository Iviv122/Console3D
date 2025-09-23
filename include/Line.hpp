#include <iostream>
#include <vector>

#include "Vector4.hpp"
#include "Vector2.hpp"
#include "Model.hpp"
#include "ScreenRender.hpp"

#pragma once

Model Line(std::vector<Vector4> points)
{
    return Model(
        points,
        Vector4(0, 0, 0, 1));
}
void DrawLine(Shapes *r, Model face, char c)
{
    for (size_t i = 1; i < face.vertex.size(); i++)
    {
        r->DrawLineWorld(face.vertex[i - 1], face.vertex[i], c);
    }
    r->DrawLineWorld(face.vertex[0], face.vertex[face.vertex.size() - 1], c);
}