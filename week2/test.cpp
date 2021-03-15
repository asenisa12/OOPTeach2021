
//#define CATCH_CONFIG_MAIN
//#include "catch2.h"


/*
TEST_CASE("dummy")
{

    dyn_arr.set_size(5);
    REQUIRE(dyn_arr.size == 5);
}*/



#include <iostream>
using namespace std;
#include "Point.h"


int main()
{


    Point p0; //Point()
    Point p(2,3); // == Point p
    Point *p_ptr = new Point[10];

    p.setX(12);
    p.getX();
    for(int i = 0; i < 10; i++)
    {
        p_ptr[i].setX(i+1);
        p_ptr[i].setY(i-1);
        if(i>0)
        {
            cout<<"distance: "<< p_ptr[i].distance(p_ptr[i-1]) <<endl;
        }
        cout<< p_ptr[i].getX() <<" " << p_ptr[i].getY() <<endl;
    }

    delete [] p_ptr;
    Point *p_ptr2 = new Point(5,6);
    delete p_ptr2;


    Point **p_arr = new Point*[10];
    for(int i = 0; i < 10; i++)
    {
        p_arr[i] = new Point(i*10, (i+1)*10);
        if(i>0)
        {
            cout<<"distance: "<< p_arr[i]->distance(*p_arr[i-1]) <<endl;
        }
        cout<< p_arr[i]->getX() <<" " << p_arr[i]->getY() <<endl;
    }

    for(int i = 0; i < 10; i++)
    {
        delete p_arr[i];
    }
    delete [] p_arr;

    return 0;
}


