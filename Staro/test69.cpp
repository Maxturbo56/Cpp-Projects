#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	fstream file;
	
	file.open("test1.txt", ios::app);
	file<<"ovo je test 1";
	file.close();
	
	string linija;
	
	file.open("test1.txt");
	while(getline(file, linija))
	{
		cout<<linija;
	}
	file.close();
	
	return 0;
}
