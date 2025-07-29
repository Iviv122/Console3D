#include <iostream>
#include "Vector2.hpp"

#pragma once

class Screen
{
private:
    size_t width;
    size_t height;
    size_t *matrix;

public:
    Screen(size_t width, int height)
    {

        printf("Screen Created\n");

        this->width = width;
        this->height = height;
        this->matrix = new size_t[width * height];
    }
    Screen(size_t width, int height, char c)
    {

        printf("Screen Created\n");

        this->width = width;
        this->height = height;
        this->matrix = new size_t[width * height];
        this->Fill(c);
    }
    void Print()
    {
        for (size_t i = 0; i < height; i++)
        {
            for (size_t j = 0; j < width; j++)
            {
                printf("%c", matrix[i * width + j]);
            }
            printf("\n");
        }
    }
    void Fill(const char &c)
    {
        for (size_t i = 0; i < height; i++)
        {
            for (size_t j = 0; j < width; j++)
            {
                matrix[i * width + j] = c;
            }
        }
    }
    void PlaceChar(int x, int y, char c)
    {
        matrix[y * width + x] = c;
    }
    void PlaceChar(const Vector2 *pos,const char &c)
    {
        matrix[(int)pos->y * width + (int)pos->x] = c;
    }
    ~Screen()
    {
        delete this->matrix;
    }
};
