#include <fstream>
#include <iostream>
using namespace std;




struct Entry {
	int number;
	char code[3];
};

int main()
{

	fstream file("ourFirstFile.txt", ios::out| ios::in);

	//file.write("hello world\n", 12);

	
	char buff[200];

	file.seekg(0);


	int i = 0;
	while (file.getline(buff + i,200 - i))
	{

		//cout << buff << endl;
		i += 13;
		buff[i - 2] = '1';
		buff[i - 1] = '\n';
	}

	file.seekp(0);
	file.write(buff, 3 * 13);

	
	cout << buff << endl;
	

	file.close();

	file.open("file.bin", ios::out| ios::binary | ios::trunc);
	Entry arr[] = { {2,{'a','c','d'}}, {5,{'5','c','0'}},{222,{'3','c','j'}} };


	cout << sizeof(Entry) << endl;
	file.write((char*)arr, sizeof(Entry)*3);
	file.close();

	file.open("file.bin", ios::in | ios::binary );
	Entry entry;

	while (file.read((char*)&entry, sizeof(Entry)))
	{
		cout << entry.number << " ";
		for (size_t i = 0; i < 3; i++)
		{
			cout << entry.code[i];
		}
		cout << endl;
	}



	return 0;

}