#include <iostream>
#include <cmath>
#include "Vector2.hpp"

#pragma once

class Screen
{
private:
public:
    size_t width;
    size_t height;
    size_t *matrix;
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
        for (size_t y = 0; y < height; y++)
        {
            for (size_t x = 0; x < width; x++)
            {
                printf("%c", matrix[y * width + x]);
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
        // adjust to place in center :p
        y += height / 2;
        x += width / 2;
        int sum = y * width + x;
        if (sum < 0 || sum > width * height)
        {
            return;
        }
        matrix[sum] = c;
    }
    void PlaceChar(float x, float y, const char &c)
    {
        // adjust to place in center :p
        int sum = (round(y + (float)height / 2)) * width + (round(x + (float)width / 2));
        if (sum < 0 || sum > width * height)
        {
            return;
        }
        matrix[sum] = c;
    }
    void PlaceChar(const Vector2 pos, const char &c)
    {
        // adjust to place in center :p
        int sum = (round(pos.y) + height / 2) * width + (round(pos.x) + width / 2);
        if (sum < 0 || sum > width * height)
        {
            return;
        }
        matrix[sum] = c;
    }
    ~Screen()
    {
        delete this->matrix;
    }
};
