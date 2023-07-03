#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<Windows.h>
using namespace std;

//user mode

vector <int> Integers;
vector <string> Strings; 

int main()
{
	ofstream fajl;
	ifstream file;
	string a, c, d;
	int b, p, q;
	string what, what_Two;
	int whatInt, whatInt_Two;
	string* user_Input = &a;
	int* value_AddressInt = &b;
	int* value_Of_Line = &p;
	string* value_AddressString = &c;
	
	cout<<"Command line Terminal"<<endl<<endl<<endl<<"Input commands are : "<<endl<<endl<<"- Make (arguments it takes : Int :: value, String :: value)"
	<<endl<<"- Show (arguments it takes : Integers, Strings)"
	<<endl<<"- Add (arguments it takes : Integers.stream, Int position 1 & Int position 2)"
	<<endl<<"- Combine (arguments it takes : Strings.stream, String position 1 & String position 2)"
	<<endl<<"- CLM (arguments it takes : Full :: Integers, Strings || Last :: Integers, Strings)"
	<<endl<<"- Literal (arguments it takes : Add :: Strings.stream, String position 1 & String position 2 || Save :: Integers, Strings || Load :: Integers, Strings)"
	<<endl<<"- Console (arguments it takes : NULL)"
	<<endl<<"- Exit"
	<<endl<<endl;
	
	do{
		cin>>*user_Input;
		
		if(*user_Input == "Exit")
		{
			exit(0);
		}
		
		if(*user_Input == "Make")
		{
			cin>>what;
			
			if(what == "Int")
			{
				cin>>*value_AddressInt;
				Integers.push_back(*value_AddressInt);
			}
			
			if(what == "String")
			{
				cin>>*value_AddressString;
				Strings.push_back(*value_AddressString);
			}
		}
		
		if(*user_Input == "Show")
		{
			cin>>what;
			if(what == "Integers")
			{
				for(int i = 0; i < Integers.size(); i++)
				{
					cout<<Integers[i]<<"\t";
				}
				
				cout<<endl<<endl;
			}
			
			if(what == "Strings")
			{
				for(int i = 0; i < Strings.size(); i++)
				{
					cout<<Strings[i]<<"\t";
				}
				
				cout<<endl<<endl;
			}
		}		
		
		if(*user_Input == "Add")
		{	
			if(Integers.empty())
			{
				cout<<"Empty Integer Stream. Please add more integers by literal Make ; Int ; Value of your integer to be able to use this command."<<endl<<endl;
			}
			else
			{
				cout<<"Recommended to show Integer stream before adding them. Literal of Integer type Show ; Integers ;"<<endl<<endl;
				cout<<"Value of Integers shown as value pairs of location and Integers inert value"<<endl<<endl;
				cin>>whatInt;
				cin>>whatInt_Two;
				
				Integers.push_back(Integers[whatInt] + Integers[whatInt_Two]);
				cout<<"Added Integers.stream positions at "<<whatInt<<" & "<<whatInt_Two<<endl<<endl;
			}
		}	
		
		if(*user_Input == "Combine")
		{	
			if(Strings.empty())
			{
				cout<<"Empty String Stream. Please add more strings by literal Make ; String ; Value of your string to be able to use this command."<<endl<<endl;
			}
			else
			{
				cout<<"Recommended to show String stream before combining them. Literal of String type Show ; Strings ;"<<endl<<endl;
				cout<<"Value of Strings shown as value pairs of location and Strings inert value"<<endl<<endl;
				cin>>whatInt;
				cin>>whatInt_Two;
				
				Strings.push_back(Strings[whatInt] + " " + Strings[whatInt_Two]);
				cout<<"Combined Strings.stream positions at "<<whatInt<<" & "<<whatInt_Two<<endl<<endl;
			}
		}		
		
		if(*user_Input == "CLM")
		{	
			cin>>what;
			
			if(what == "Full")
			{
				cin>>what;
				
				if(what == "Integers")
				{
					Integers.clear();
				}
			
				if(what == "Strings")
				{
					Strings.clear();
				}
			}
			
			if(what == "Last")
			{
				cin>>what;
				
				if(what == "Integers")
				{
					Integers.pop_back();
				}
			
				if(what == "Strings")
				{
					Strings.pop_back();
				}
			}
			
			if(what == "ToLast")
			{
				cin>>what;
				
				if(what == "Integers")
				{
					Integers.erase(Integers.begin(), Integers.end() - 1);
				}
			
				if(what == "Strings")
				{
					Strings.erase(Strings.begin(), Strings.end() - 1);
				}
			}
		}	
		
		if(*user_Input == "Literal")
		{	
			cin>>what;
			
			if(what == "Add")
			{
				cout<<"Recommended to show String stream before Literal Adding them. Literal of String type Show ; Strings ;"<<endl<<endl;
				cout<<"Value of Strings shown as value pairs of location and Strings inert value"<<endl<<endl;
				cin>>whatInt;
				cin>>whatInt_Two;
				
				Strings.push_back(Strings[whatInt] +  Strings[whatInt_Two]);
				cout<<"Combined Strings.stream positions at "<<whatInt<<" & "<<whatInt_Two<<endl<<endl;
			}
			
			if(what == "Save")
			{
				cin>>what;
				if(what == "Integers")
				{
					cout<<"Recommended to show Integer stream before saving. Literal of Integer type Show ; Integers ;"<<endl<<endl;
					fajl.open("saveInts.txt", ios::app);
					cin>>whatInt;
					fajl<<Integers[whatInt]<<endl;
					fajl.close();
				}
				
				if(what == "Strings")
				{
					cout<<"Recommended to show String stream before saving. Literal of String type Show ; Strings ;"<<endl<<endl;
					fajl.open("saveStrings.txt", ios::app);
					cin>>whatInt;
					fajl<<Strings[whatInt]<<endl;
					fajl.close();
				}
			}
			
			if(what == "Load")
			{
				cin>>what;
				if(what == "Integers")
				{
					file.open("saveInts.txt", ios::out);
					while(getline(file, d))
					{
						*value_Of_Line = stoi(d);
						Integers.push_back(*value_Of_Line);
					}
					file.close();
				}

				if(what == "Strings")
				{
					file.open("saveStrings.txt", ios::out);
					while(getline(file, d))
					{
						Strings.push_back(d);
					}
					file.close();
				}
			}
		}	
		
		if(*user_Input == "Console")
		{	
			cin>>what;
			
			if(what == "NULL")
			{
				system("CLS");
			}
		}	
		
		if(*user_Input == "Loop")
		{	
			cout<<"How many times to loop : "<<endl;
			cin>>whatInt;
			
			cout<<"What to loop : "<<endl;
			cin>>what;
			
			if(what == "Integers")
			{
				for(int i = 0; i < whatInt; i++)
				{
					
				}
			}
		}
	}while(1);
}
