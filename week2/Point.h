#pragma once



struct Point
{
    int *values;
    /*Point()
    {
        values = new int[2];
        values[0] = 0;
        values[1] = 0;
    }*/

    Point(int X = 0, int Y = 0);
    ~Point();

    int getX() const;

    int getY() const;

    void setX(int x);
    void setY(int y);
    double distance(const Point &other);
};


