#include "array.h"

#include <iostream>
using namespace std;

static int *arr = nullptr;
static int arr_capacity = 0;
static int arr_size = 0;



void create(int capacity)
{
    if(arr == nullptr)
    {
        arr = new int[capacity];
        arr_capacity = capacity;
        arr_size = 0;
    }
    else
    {
        cout<<"array already created"<<endl;
    }
}


void resize(int capacity)
{
    if(arr != nullptr)
    {

        int *tmp = new int[capacity];
        for(int i = 0; i < capacity && i < arr_size; i++)
        {
            tmp[i] = arr[i];
        }

        delete [] arr;
        arr = tmp;
        arr_capacity = capacity;

        if(arr_size > capacity)
        {
            arr_size = capacity;
        }
    }
    else
    {
        cout<<"no array created"<<endl;
    }
}



void clear()
{
    delete [] arr;
    arr = nullptr;

    arr_capacity = 0;
    arr_size = 0;

}


void push_back(int num)
{

    if(arr == nullptr)
    {
        cout << "array not defined" << endl;
        return;
    }

    if(arr_size == arr_capacity)
    {
        resize(arr_capacity + 1);

    }

    arr[arr_size] = num;
    arr_size++;
}

void pop_back()
{
    if(arr_size > 1)
    {
        arr_size--;
        resize(arr_capacity - 1);
    }
}


void remove(int index)
{
    if(index >= 0 && index < arr_size)
    {
        for(int i = index; i < arr_size - 1; i++)
        {
            arr[i] = arr[i+1];
        }
        resize(arr_capacity - 1);
    }
}

int get_size()
{
    return arr_size;
}


int& get(int i)
{
    return arr[i];
}


int get_max(int index)
{
    int max = arr[i];
    for(int i = index; i < arr_size; i++)
    {
       if( arr[i] > max)
       {
            max = arr[i];
       }
    }

    return max;
}

