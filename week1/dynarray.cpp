#include "dynarray.h"
#include <iostream>
using namespace std;

void dynarray::create(int capacity_)
{
    if (arr == nullptr)
    {
        capacity = capacity_;
        arr = new int[capacity];
    }
}



void dynarray::free()
{
    if(arr != nullptr)
    {
        delete [] arr;
        arr = nullptr;
        capacity = 0;
    }
}


/*void dynarray::free()
{
    if(arr != nullptr)
    {
        delete [] arr;
        arr = nullptr;
        capacity = 0;
    }
}*/

int& dynarray::get(int i)
{
    return arr[i];
}


void dynarray::print()
{

    for(int i = 0; i < capacity; i++)
    {
        cout << arr[i] <<", ";

    }
}


void dynarray2D::create(int capacityX_, int capacityY_)
{
    if(arr == nullptr)
    {
        capacityY = capacityY_;
        capacityX = capacityX_;
        arr = new dynarray[capacityY];

        for(int i = 0; i < capacityY; i++)
        {
            arr[i].create(capacityX);
        }

    }
}

void dynarray2D::free()
{

    if(arr != nullptr)
    {
        for(int i = 0; i < capacityY; i++)
        {
            arr[i].free();
        }
        delete [] arr;
        capacityY = capacityX = 0;
    }
}


 void dynarray2D::print()
 {
    for(int i = 0; i < capacityY; i++)
    {
        arr[i].print();
        cout<<endl;
    }


 }


 int& dynarray2D::get(int X, int Y)
 {

     return arr[Y].get(X);
 }


 dynarray* dynarray2D::get(int Y)
 {

     return &arr[Y];
 }


 dynarray* get_best_sum_row(Y)
 {

     return nullptr;
 }
