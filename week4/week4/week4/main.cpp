#include "Class.h"
int main()
{

	Class UP;

	for(int i = 0; i<20; i++)
		UP.addStudent("pesho", i*100 + i);

	UP.removeStudentByPos(4);
	UP.print();

	UP[5].get_name();
	UP[5].get_FN();

	

	return 0;
}