#include<iostream>
#include<vector>
using namespace std;
struct Knjiga{
	char naslov[50];
	char autor[30];
	int godinaIzdavanja;
};

struct Univerzalna{
	string naslov;
	string autor;
	int godinaIzdavanja;
};

void Pretraga(vector <Univerzalna> x, string a)
{
	cout<<" Sve knjige ciji je autor jednak proslijedjenom parametru su: "<<endl;
	string b;
	b = a;
	
	Univerzalna u;
	vector <Univerzalna> s;
	s = x;

	
	for(int i = 0; i < s.size(); i++)
	{
		u = s[i];
		
		if(u.autor == b)
		{
			cout<<u.naslov<<endl;
		}
	}	
}

int main(){

Univerzalna k;
vector <Univerzalna> v;
cout<<"Unesi broj elemenata: "<<endl;
int n;
cin>>n;
string uslov;
cout<<"Unesi uslov tj. ime autora"<<endl;
cin>>uslov;

//sad pravimo bazu
for(int i=0;i<n;i++){
	cout<<"Unesi naslov: "<<endl;
	cin>>k.naslov;
	cout<<"Unesi ime autora: "<<endl;
	cin>>k.autor;
	cout<<"Unesi godinu izdavanja: "<<endl;
	cin>>k.godinaIzdavanja;
	
	v.push_back(k);
}
Pretraga (v, uslov);

return 0;
}
