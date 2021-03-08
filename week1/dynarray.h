#pragma once

struct dynarray
{

    int *arr = nullptr;
    int capacity = 0;

    void create(int capacity_);
    void free();
    int& get(int i);
    void print();

};


struct dynarray2D
{
    dynarray *arr = nullptr;

    int capacityX = 0;
    int capacityY = 0;

    void create(int capacityX, int capacityY);
    void free();

    void print();
    int& get(int X, int Y);
    dynarray* get(int Y);
    dynarray* get_best_sum_row(Y);// HW
};


