#include <cstring>
#include <iostream>
#include "dynarray.h"
using namespace std;
/*
int global;
struct Example
{
        int example_int = 'a';
        char example_char = 3;
        char example_str[8] = "wow";

        void print_example()
        {
            global;

            cout <<"int: "<<example_int<<" char: "<<example_char <<" str: "<<example_str<<endl;
        }

};



int main()
{

    Example ex;

    ex.example_char = 'c';

    ex.example_int = 2;

    strncpy(ex.example_str, "example", 9);

    cout<< ex.example_str <<endl;

    Example *ex_ptr = &ex;

    cout << ex_ptr->example_char<<endl;//==
    cout << (*ex_ptr).example_char<<endl;


    ex.print_example();
*/

int main(){

    dynarray darr;
    dynarray darr2;

    darr.create(10);
    darr2.create(6);

    for(int i = 0; i < darr.capacity; i++)
    {

        darr.get(i) = i+1;
    }


    darr.print();

    darr2.free();
    darr.free();


    dynarray2D arr2d;
    arr2d.create(10, 10);
    for(int i = 0; i<arr2d.capacityY; i++)
    {
        for(int j = 0; j<arr2d.capacityX; j++)
        {
            arr2d.get(j,i) = i*100+j;
        }
    }

    arr2d.print();
    arr2d.get(2)->print();
    return 0;
}
