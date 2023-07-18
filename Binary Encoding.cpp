#include<iostream>
using namespace std;

struct Binarni{
	int vrijednost[4];
};

Binarni Pretvori(int a)
{
	Binarni binary;
	int temp;
	
	for(int i = 0; i < 4; i++)
	{
		binary.vrijednost[i] = a % 2;
		a /= 2;
	}
	
	return binary;
}

void Ispisi(Binarni a)
{		
	

	for(int i = 3; i > -1; i--)
	{	
		cout<<a.vrijednost[i];
	}
	
	cout<<endl;
}

Binarni Saberi_Binarno(Binarni a, Binarni b)
{
	Binarni c;
	bool pamti = false;
	
	for(int i = 0; i < 4; i++)
	{
		c.vrijednost[i] = a.vrijednost[i] + b.vrijednost[i];
		
		if(c.vrijednost[i] == 2)
		{
			c.vrijednost[i] = 0;
			pamti = true;
		}
	}
	
	return c;
}


int main()
{
	Binarni binarni, binarni_dva, rezultat;
	
	int a, b;
	cout<<"--------------------------------\nUnesite prvi broj koji zelite konvertovati u binarni : "<<endl;
	cin>>a;
	
	cout<<"Unesite drugi broj koji zelite konvertovati u binarni : "<<endl;
	cin>>b;
	
	binarni = Pretvori(a);
	binarni_dva = Pretvori(b);
	
	cout<<endl<<endl<<"--------------------------------\nVasi cijeli brojevi pretvoreni u binarni kod su : \n\n "<<a<<" = ";
	
	Ispisi(binarni);
	
	cout<<" \n "<<b<<" = ";
	
	Ispisi(binarni_dva);
	
	cout<<endl<<endl;
	
	cout<<"--------------------------------\nNakon sabiranja vasi brojevi izgledaju ovako : \n\n "<<a + b<<" == ";
	
	rezultat = Saberi_Binarno(binarni, binarni_dva);

	Ispisi(rezultat);
	
	return 0;
}
