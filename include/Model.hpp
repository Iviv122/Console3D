#include <iostream>
#include <vector>

#include "Vector3.hpp"
#include "Vector2.hpp"

#pragma once

struct Model
{
    std::vector<Vector3> vertex;
    Vector3 pivot;
    Model(std::vector<Vector3> v, Vector3 c): vertex(v), pivot(c)
    {}
};
