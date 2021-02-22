#include "array.h"
#include <iostream>


using namespace std;
int main()
{

    create(10);

    for(int i = 0; i<121; i++)
    {
        push_back(i*10);
    }

    for(int i = 0; i<get_size(); i++)
    {
        get(i) = get(i) + 2;
        cout << get(i) <<endl;
    }

    clear();
    return 0;
}
