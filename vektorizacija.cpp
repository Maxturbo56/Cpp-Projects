#include<iostream>
#include<vector>
using namespace std;

struct Broj{
	int broj;
};

void func(vector <Broj> x)
{
	vector <Broj> brojevi;
	Broj broj;
	
	brojevi = x;
	
	for(int i = 0; i < brojevi.size(); i++)
	{
		broj = brojevi[i];
		cout<<broj.broj;
	}	
}

int main()
{
	Broj broj;
	broj.broj = 18236;
	vector <Broj> a;
	a.push_back(broj);
	func(a);
	return 0;
}
