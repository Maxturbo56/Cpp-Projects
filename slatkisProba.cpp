#include<iostream>
#include<vector>
using namespace std;

//pravi struct slatkis 
struct Slatkis{
	char naziv[20];
	float cijena;
	int brKalorija;
};


void PretragaSlatkisi(vector <Slatkis> x /* vektor slatkisa */, int& a /* Proslijedjeni parametar n */ )
{
	cout<<"Svi slatkisi kod kojih cijena po kaloriji je manja od n su : "<<endl;
	Slatkis q /* Ovo je neki ZAMISLJENI SLATKIS koji se izjednacava sa elementom vektora */ ;
	vector <Slatkis> u; /* Ovo je zapravo vektor nad kojim mi mozemo da radimo  */
	u = x; /* x je PASSED IN as func argument   */
	for(int i = 0; i < u.size(); i++)
	{
		q = u[i];
		if((q.cijena / q.brKalorija) < a)
		{
			cout<<q.naziv<<endl;
		}
	}
	
}


int main()
{
	Slatkis slatkis;
	
	vector <Slatkis> slatkisi;
	
	cout<<"Unesi broj slatkisa : "<<endl;
	
	int n;
	cin>>n;
	
	//pravi bazu
	
	for(int i = 0; i < n; i++)
	{
		cout<<"Unesi naziv : "<<endl;
		cin>>slatkis.naziv;
		
		cout<<"Unesi cijena : "<<endl;
		
		do{
			cin>>slatkis.cijena;
			if(slatkis.cijena < 0 || slatkis.cijena > 100)
			{
				cout<<"Unesi cijenu izmedju 0 i 100"<<endl;
			}
		}while(slatkis.cijena < 0 || slatkis.cijena > 100);
		
		cout<<"Unesi broj kalorija : "<<endl;
		
		do{			
			cin>>slatkis.brKalorija;
			if(slatkis.brKalorija < 0 || slatkis.brKalorija > 1000)
			{
				cout<<"Unesi broj kalorija izmedju 0 i 1000"<<endl;
			}
		}while(slatkis.brKalorija < 0 || slatkis.brKalorija > 1000);
		
		slatkisi.push_back(slatkis);
	}
	
	//printa bazu
	
	for(int i = 0; i < slatkisi.size(); i++)
	{
		slatkis = slatkisi[i];
		cout<<slatkis.naziv<<"\n"<<slatkis.cijena<<"\n"<<slatkis.brKalorija;
		cout<<endl<<endl;
	}
	
	cout<<endl<<endl;
	
	//zi function
	PretragaSlatkisi(slatkisi, n);
	
}


