#include <iostream>
#include <vector>

#include "Vector4.hpp"
#include "Vector2.hpp"

#pragma once

struct Model
{
    std::vector<Vector4> vertex;
    Vector4 pivot;
    Model(std::vector<Vector4> v, Vector4 c) : vertex(v), pivot(c)
    {
    }

    void Move(Vector4 v)
    {
        Vector4 a = Vector4(v.x,v.y,v.z,1);
        pivot = pivot + a;
    }
    void Move(Vector3 v)
    {
        Vector4 a = Vector4(v.x,v.y,v.z,1);
        pivot = pivot + a;
    }
    void Scale(float a)
    {
        Vector4 v = Vector4(a, a, a, 1);
        for (int i = 0; i < vertex.size(); i++)
        {
            vertex[i] = vertex[i] * a;
        }
    }
    void Scale(Vector4 v)
    {
        Vector4 a = Vector4(v.x, v.y, v.z, 1);
        for (int i = 0; i < vertex.size(); i++)
        {
            vertex[i] = vertex[i] * a;
        }
    }
    void Scale(Vector3 v)
    {
        Vector4 a = Vector4(v.x, v.y, v.z, 1);
        for (int i = 0; i < vertex.size(); i++)
        {
            vertex[i] = vertex[i] * a;
        }
    }
};
