#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

struct Ucenik{
	string ime;
	string prezime;
	int razred;
	int ocjene[5];
};

vector < Ucenik > ucenici;

void Unesi_ucenika(){
	Ucenik trenutni;
	
	ofstream filein;
	filein.open("ucenici.txt",ios::app);
	
	cout<<"Unesi ime: "<<endl;
	cin>>trenutni.ime;
	cout<<"Unesi prezime: "<<endl;
	cin>>trenutni.prezime;
	cout<<"Unesi razred: "<<endl;
	cin>>trenutni.razred;
	
	filein<<trenutni.ime<<endl<<trenutni.prezime<<endl<<trenutni.razred<<endl<<"?"<<endl;
	
	for(int i=0;i<5;i++){
		cout<<"Unesi #"<<i+1<<" ocjenu: "<<endl;
		cin>>trenutni.ocjene[i];
		filein<<trenutni.ocjene[i]<<endl;
	}

	filein<<"$"<<endl;
}

void Ispis_ocjena(){
	cout<<"Unesi ime ucenika: "<<endl;
	string a;
	cin>>a;
	cout<<"Unesi prezime ucenika: "<<endl;
	string b;
	cin>>b;
	
	ifstream fileout;
	string linija;
	vector<string> linije;
	fileout.open("ucenici.txt", ios :: out);
	
	while(getline(fileout,linija)){
		linije.push_back(linija);
	}
	fileout.close();
	for(int i=0;i<linije.size();i++){
		
		if(linije[i]==a && linije[i+1]==b){
			cout<<"Ocjene ucenika "<<a<<" "<<b<<" :"<<endl;
			cout<<linije[i+4]<<endl<<linije[i+5]<<endl<<linije[i+6]<<endl<<linije[i+7]<<endl<<linije[i+8]<<endl;
		}
	}
}

void Ispis_prosjeka(){
	
	cout<<"Unesi ime ucenika: "<<endl;
	string a;
	cin>>a;
	cout<<"Unesi prezime ucenika: "<<endl;
	string b;
	cin>>b;
	
	//odavdje
	ifstream fileout;
	string linija;
	vector<string> linije;
	fileout.open("ucenici.txt", ios :: out);
	
	while(getline(fileout,linija)){
		linije.push_back(linija);
	}
	fileout.close();
	
	//ovo sve iznad je template puca u vektor stringova
	
	float ocjena;
	 vector <float> ocjene;
	 
	
	for(int i=0;i<linije.size();i++){
		
		if(linije[i]==a && linije[i+1]==b){
			
		ocjena=stof(linije[i+4]);
		ocjene.push_back(ocjena);
		ocjena=stof(linije[i+5]);
		ocjene.push_back(ocjena);
		ocjena=stof(linije[i+6]);
		ocjene.push_back(ocjena);
		ocjena=stof(linije[i+7]);
		ocjene.push_back(ocjena);
		ocjena=stof(linije[i+8]);
		ocjene.push_back(ocjena);
	
		break;
		} 
	}
	
	for(int i=0;i<ocjene.size();i++){
		ocjena+=ocjene[i];	
	}
	
	ocjena/=5;
	
	
	cout<<"Prosjecna ocjena ucenika "<<a<<" "<<b<<" je "<<ocjena<<endl;	
	
}

void Ispis_najboljeg_ucenika(){
	
	//odavdje
	ifstream fileout;
	string linija;
	vector<string> linije;
	fileout.open("ucenici.txt", ios :: out);
	
	while(getline(fileout,linija)){
		linije.push_back(linija);
	}
	fileout.close();
	
	//ovo sve iznad je template puca u vektor stringova
	
	float ocjena, tren_ocjena;
	 vector <float> ocjene;
	 vector <float> prosjeci;
	 
	
	for(int i=0;i<linije.size();i++){
		
		if(linije[i]=="?"){
			ocjene.push_back(stof(linije[i+1]));
			ocjene.push_back(stof(linije[i+2]));
			ocjene.push_back(stof(linije[i+3]));
			ocjene.push_back(stof(linije[i+4]));
			ocjene.push_back(stof(linije[i+5]));		
			}	
	}
for(int i=0;i<ocjene.size();i+=5){
	
	tren_ocjena+=ocjene[i]+=ocjene[i+1]+=ocjene[i+2]+=ocjene[i+3]+=ocjene[i+4];
	tren_ocjena/=5;
	prosjeci.push_back(tren_ocjena);
	}


float najveci_prosjek=0;


for(int i=0;i<prosjeci.size();i++){
if(prosjeci[i]>najveci_prosjek){
	najveci_prosjek=prosjeci[i];
}	
}

cout<<"Najveci prosjek je: "<<najveci_prosjek-1<<endl<<endl<<endl;
}
int main(){
	
	
	
	int korisnicki_input;
	
	
	
	
	do{
		cout<<"Unesi opciju koju zelis: "<<endl;
		
		cout << "1. Unesi ucenika: \n2. Ispis ocjena: \n3. Ispis prosjeka: \n4. Ispis najboljeg ucenika: \n5. Kraj programa."<<endl<<endl;
	
		cin >> korisnicki_input;
		switch(korisnicki_input)
		{
			case 1:{
				Unesi_ucenika();
				break;
			}
			case 2:{
				Ispis_ocjena();
				break;
			}
			case 3:{
				Ispis_prosjeka();
				break;
			}
			case 4:{
				Ispis_najboljeg_ucenika();
				break;
			}
			case 5:{
				exit(0);
				break;
			}
			default:{
				cout<<"ti si supak"<<endl;
				break;
			}	
		}
	} while(1);
	
	return 0;
}
