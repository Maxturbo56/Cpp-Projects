#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

struct Klub{
	string naziv;
	int godina_Osnivanja;
};

//univerzalna naslov
univerzalna u
string naziv;
int broj; 
struct Igrac{
	Klub klub;
	string ime;
	string prezime;
	string spol;
	string kategorija;
};

void NapraviIgraca()
{
	Igrac igrac;
	ofstream /* ovo definise fajl, u koji se moze upisivati */ fileIN;
	fileIN.open("igraci.txt", ios::app);
	cout<<"Unesi ime igraca : "<<endl;
	cin>>igrac.ime;
	cout<<"Unesi prezime igraca : "<<endl;
	cin>>igrac.prezime;
	cout<<"Unesi spol igraca : "<<endl;
	cin>>igrac.spol;
	cout<<"Unesi kategoriju igraca "<<endl;
	cin>>igrac.kategorija;
	cout<<"Unesi naziv kluba igraca "<<endl;
	cin>>igrac.klub.naziv;
	cout<<"Unesi godinu osnivanja kluba igraca "<<endl;
	cin>>igrac.klub.godina_Osnivanja;
	
	fileIN<<igrac.ime<<" "<<igrac.prezime<<endl<<igrac.spol<<endl<<igrac.kategorija<<endl<<igrac.klub.naziv<<endl<<igrac.klub.godina_Osnivanja<<"\n&"<<endl;
	fileIN.close();
}

void IspisiIgrace()
{
	ifstream fileOut;
	string linija;
	fileOut.open("igraci.txt", ios::out);
	while(getline(fileOut, linija))
	{	
		if(linija == "&")
		{
			cout<<endl<<endl;
		}
		else
		{
			cout<<linija<<" - ";
		}
	}
	fileOut.close();
	cout<<endl<<endl; 
}

void ProvjeriPrijavljene()
{
	string kategorija;
	string spol;
	cout<<"Unesite koji spol zelite : "<<endl;
	cin>>spol;
	cout<<"Unesite koju kategoriju zelite : "<<endl;
	cin>>kategorija;
	
	ifstream fileOut;
	string linija;
	
	vector <string> linije;
	
	fileOut.open("igraci.txt", ios::out);
	while(getline(fileOut, linija))
	{	
		linije.push_back(linija);
	}
	
	fileOut.close();
	
	for(int i = 0; i < linije.size(); i++)
	{
		if(linije[i] == spol && linije[i + 1] == kategorija)
		{
			cout<<linije[i - 1]<<" - "<<linije[i]<<" - "<<linije[i + 1]<<" - "<<linije[i + 2]<<" - "<<linije[i + 3];		
			cout<<endl<<endl;
		}
	}
	
	cout<<endl<<endl;
}
	
void KreirajZdrijeb()
{
	
	string kategorija;
	string spol;
	cout<<"Unesite koji spol zelite : "<<endl;
	cin>>spol;
	cout<<"Unesite koju kategoriju zelite : "<<endl;
	cin>>kategorija;
	
	ifstream fileOut;
	fileOut.open("igraci.txt", ios::in);
	
	string linija;
	vector <string> linije;
	
	while(getline(fileOut, linija))
	{	
		linije.push_back(linija);
	}
		
	fileOut.close();
	
	vector <string> prolazi;
	
	for(int i = 0; i < linije.size(); i++)
	{
		if(linije[i] == spol && linije[i + 1] == kategorija)
		{
			prolazi.push_back(linije[i - 1]);
		}
	}
		
	ofstream fileIn;
	
	fileIn.open(kategorija+spol+".txt", ios::app);
	
	fileIn<<endl<<endl<<" ---- Pocetak Zdrijeba ---- "<<endl;
	
	for(int i = 0; i < prolazi.size(); i+=2)
	{	
		fileIn<<prolazi[i]<<" - "<<prolazi[i + 1]<<endl;
	}
	
	
	fileIn.close();
	cout<<endl<<endl;
}

int main()
{
	vector <Igrac> igraci;
	int a;
	int* UserInput = &a;
	
	do{
		cout<<"Unesi opciju koji zelite : "<<endl<<endl;
		cout<<"1. Unesi Igraca\n2. Citaj Igraca\n3. Provjeri Prijavljene\n4. Kreiraj Zrijeb\n5. Kraj"<<endl;
		cin>>*UserInput;
		switch(*UserInput)
		{
			case 1:
			{
				NapraviIgraca();
				break;	
			}
			
			case 2:
			{
				IspisiIgrace();
				break;	
			}
			case 3:
			{
				ProvjeriPrijavljene();
				break;	
			}
			case 4:
			{
				KreirajZdrijeb();
				break;
			}
			case 5: 
			{
				exit(0);
				break;
			}
		}
	}while(1);
	
	
	return 0;
}
