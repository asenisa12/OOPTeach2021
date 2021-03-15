
#include "Point.h"
#include <iostream>
#include <cmath>
using namespace std;

Point::~Point()
{
    cout<<getX()<<":"<<getY()<<" bye bye cruel life"<<endl;
    delete [] values;
}
Point::Point(int X, int Y)
{
    values = new int[2];
    values[0] = X;
    values[1] = Y;
}

int Point::getX()  const
{
    return values[0];
}

int Point::getY() const
{
    return values[1];
}

void Point::setX(int x)
{
    values[0] = x;
}

void Point::setY(int y)
{
    values[1] = y;
}


double Point::distance(const Point &other)
{

    int other_x =  other.getX();
    int other_y = other.getY();

    return sqrt(pow(other_x - getX(), 2) +pow( other_y- getY(), 2));
}
