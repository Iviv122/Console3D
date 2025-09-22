#include <iostream>
#include <vector>

#include "Vector4.hpp"
#include "Vector2.hpp"
#include "Model.hpp"
#include "ScreenRender.hpp"

#pragma once

Model Face()
{
    return Model(
        {
        Vector4(-0.5, -0.5, 0, 1),
        Vector4(0.5, -0.5, 0, 1),
        Vector4(0.5, 0.5, 0, 1),
        Vector4(-0.5, 0.5, 0, 1)
    },
        Vector4(0, 0, 0, 1));
}
void DrawFace(Shapes *r, Model face, char c)
{
        r->DrawPlane(
            face.pivot + face.vertex[0],
            face.pivot + face.vertex[1],
            face.pivot + face.vertex[2],
            face.pivot + face.vertex[3],
            c);
}