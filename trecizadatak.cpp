#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

/* Potrebno je napraviti aplikaciju za voðenje turnira u tenisu.
Aplikacija treba da sadrži sljedeæe elemente:

1. Enumeraciju Kategorija {U9, U10, U11, U12, U13} 1 bod
Enumeraciju Spol {muski, zenski} 1 bod

2. Strukture: 4 boda
a) Klub – naziv - string,
godina osnivanja – int,
b) Igrac – klub – Klub,
imePrezime - string,
spol - Spol,
kategorija - Kategorija

Potrebno je definisati vektor igraci u koji æe se smještati uneseni igraci.
Takoðer potrebno je sve igrace snimati u datoteku igraci.txt/igraci.csv BITNO

6 bodova upis i 8 bodova èitanje

U glavnom programu kreirati meni:

1. Unesi igraca (funkcija strukture Igrac koja u objekat koji je pozvan unosi odgovarajuæe podatke
a zatim u glavnom programu se smjesta u niz/vektor/file) 5 boda
2. Ispis igraca - funkcija glavnog programa koja ispisuje sve igraæe u obliku npr:
Hamo Hamic - U11 muski
Nika Nikic - U9 zenski 5 boda
3. Provjeri prijavljene (pitati korisnika za koju kategoriju i koji spol i nakon toga izlistati sve igrace
sa tim uslovima. 5 boda


4. Kreiraj zrijeb (pitati korisnika za koju kategoriju i koji spol i nakon toga kreirati zrijeb za te uslove
snimajuci zrijeb u datoteku.) npr. korisnik odabere U9 i zenski
Datoteka: U9zenski.txt
Sadrzaj datoteke:
Nika Nikic - Elma Terzic
Helena Tikvic - Maja Dodik
Esma Catic - slobodna




5 bodova

5. Kraj
Igraèe je potrebno prilikom pokretanja programa snimiti u vektor, i prilikom zatvaranja programa
ponovo snimiti u datoteku.*/

struct Klub{
	string naziv;
	int godina_Osnivanja;
};

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
	cout<<"Unesi ime i prezime igraca : "<<endl;
	cin>>igrac.ime;
	cin>>igrac.prezime;
	cout<<"Unesi spol igraca : "<<endl;
	cin>>igrac.spol;
	cout<<"Unesi kategoriju igraca "<<endl;
	cin>>igrac.kategorija;
	cout<<"Unesi klub igraca "<<endl;
	cin>>igrac.klub.naziv>>igrac.klub.godina_Osnivanja;
	
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
			cout<<" - "<<linija<<" - ";
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
	
	void KreirajZdrijeb(){
	
	string kategorija;
	string spol;
	cout<<"Unesite koji spol zelite : "<<endl;
	cin>>spol;
	cout<<"Unesite koju kategoriju zelite : "<<endl;
	cin>>kategorija;
	
	ifstream fileOut;
	fileOut.open("igraci.txt", ios::out);
	
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
	
		
	/*ofstream fileIn;
	fileIn.open(kategorija+spol+".txt");*/
	
	for(int i = 0; i < prolazi.size(); i++)
	{
		cout<<prolazi[i]<<" - "<<prolazi[i + 1]<<endl;
	}
	
	cout<<endl<<endl;
	}
/*Kreiraj zrijeb (pitati korisnika za koju kategoriju i koji spol i nakon toga kreirati zrijeb za te uslove
snimajuci zrijeb u datoteku.) npr. korisnik odabere U9 i zenski
Datoteka: U9zenski.txt
Sadrzaj datoteke:
Nika Nikic - Elma Terzic
Helena Tikvic - Maja Dodik
Esma Catic - slobodna*/	
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
