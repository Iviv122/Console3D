#include "Vector3.hpp"
#include "Vector2.hpp"

#pragma once

class Model
{
private:
    Vector3 origin;
    Vector3 model[]; 
public:
    Model();
    ~Model();
};

Model::Model()
{
}

Model::~Model()
{
}
