#include <iostream>
#include <vector>

#include "Vector4.hpp"

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
        Vector4 a = Vector4(v.x, v.y, v.z, 1);
        pivot = pivot + a;
    }
    void Move(Vector3 v)
    {
        Vector4 a = Vector4(v.x, v.y, v.z, 1);
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

    void RotateZ(float a)
    {
        for (int i = 0; i < vertex.size(); i++)
        {
            float x = vertex[i].x;
            float y = vertex[i].y;

            vertex[i].x = x * cos(a) -(y * sin(a));
            vertex[i].y = (x * sin(a)) + (y * cos(a));
        }
    }

    void RotateY(float a)
    {
        for (int i = 0; i < vertex.size(); i++)
        {
            float x = vertex[i].x;
            float z = vertex[i].z;

            vertex[i].x = x * cos(a) + z * sin(a);
            vertex[i].z = -(x * sin(a)) + z * cos(a);
        }
    }

    void RotateX(float a)
    {
        for (int i = 0; i < vertex.size(); i++)
        {
            float y = vertex[i].y;
            float z = vertex[i].z;

            vertex[i].y = y * cos(a) - z * sin(a);
            vertex[i].z = y * sin(a) + z * cos(a);
        }
    }
};
