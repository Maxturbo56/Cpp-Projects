#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
using namespace std;

/*
uneses rijec koja transponuje abecedu
uneses poruku koju hoces enkriptovati
uneses keyword koji SAMO ti znas i vrati ti enkriptovanu tvoju poruku
*/

int main()
{
    vector <char> abeceda = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    //key matrix
    char matrix[26][26];
    string key;
    cout<<"Enter transpose key for alphabet : "<<endl;
    cin>>key;
    /* za svako slovo u key, treba :
    1. nac isto to slovo u vektoru
    2. obrisat ga, onda ga dodat na pocetak
    3. formirat prvi red matrice
    4. formirat matrix
    DONE!
    */
    char stored_char; // USE THIS!!!
    for(int i = key.size(); i >= 0; i--)
    {
        for(int j = 0; j < abeceda.size(); j++)
        {
            if(key[i] == abeceda[j])
            {
                stored_char = abeceda[j];
                abeceda.erase(abeceda.begin() + j);
                abeceda.insert(abeceda.begin(), stored_char);
            }
        }
    }
    // FORM MATRIX FUNCTION
    int current_row = 0;
    for(int j = 0; j < 26; j++)
    {
        //this fills the row with the current alphabet
        for(int i = 0; i < abeceda.size(); i++)
        {
            matrix[i][j] = abeceda[i];
        }
        stored_char = abeceda[0];
        cout<<"Stored character as : "<<stored_char<<endl;
        abeceda.erase(abeceda.begin());
        cout<<"Current starting point in alphabet : "<<abeceda[0]<<endl;
        abeceda.push_back(stored_char);
        cout<<"Last element in alphabet is : "<<abeceda[abeceda.size() - 1]<<endl;
    }

    // PRINT FUNCTIONS
    cout<<"MATRIX : "<<endl;
    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl<<"ABECEDA : "<<endl;
    for(int i = 0; i < abeceda.size(); i++)
    {
        cout<<abeceda[i]<<" ";
    }

    cout<<endl<<endl<<endl<<endl;

    // MAKE THE SECRET KEYWORD
    int message_pointer = 0; 
    int keyword_pointer = 0;
    string keyword;
    string secret_message;
    string secret_keyword = "";
    cout<<"Please enter your secret message : "<<endl;
    cin.ignore();
    getline(cin, secret_message);
    cout<<"Please enter keyword : "<<endl;
    cin>>keyword;
    while(message_pointer < secret_message.size())
    {
        cout<<keyword[keyword_pointer]<<" & "<<secret_message[message_pointer]<<endl;
        secret_keyword += keyword[keyword_pointer];
        if(keyword_pointer == keyword.size() - 1)
        {
            keyword_pointer = 0;
        }
        else
        {
            keyword_pointer++;
        }
        message_pointer++;
    }
    cout<<"SECRET KEYWORD COMPILED : "<<secret_keyword<<endl;
    /* U ovom momentu se
    secret keyword i secret 
    message poklapaju po duzini savresno.
    EH SAD, sad treba napraviti da imas 'k'
    u obe i da se 'j' i 'i'
    poklapaju.
    */
    // MAKE THE CYPER TEXT
    string cypher_text = ""; 
    int cypher_row = 0;
    int cypher_collumn = 0;
    for(int k = 0; k < secret_keyword.size(); k++)
    {
        // ovaj salta redove za index trenutnog slova secret messagea
        for(int i = 0; i < 26; i++)
        {
            if(matrix[i][0] == secret_message[k])
            {
                cout<<"FOUND IN ROW : "<<i<<endl;
                cypher_row = i;
            }
        }

        // ovaj salta kolone za index trenutnog slova keyworda
        for(int j = 0; j < 26; j++)
        {
            if(matrix[0][j] == secret_keyword[k])
            {
                cout<<"FOUND IN COLLUMN : "<<j<<endl;
                cypher_collumn = j;
            }
        }

        cypher_text += matrix[cypher_row][cypher_collumn]; 
    }
    cout<<"CYPHER TEXT RESULT : "<<cypher_text<<endl;

    // Write to file for sending...
    ofstream fajl_cypher;
    ofstream fajl_alphabet;
    // ---------------------------------------------
    fajl_cypher.open("poruka.txt", ios::out);
    fajl_cypher<<cypher_text;
    fajl_cypher.close();
    // -----------------------------------------
    fajl_alphabet.open("abc.txt", ios::out);
    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            fajl_alphabet<<matrix[i][j];
        }
    }
    fajl_alphabet.close();
    cout<<"Terminating cypher excecution..."<<endl;
    Sleep(2000);
    int f;
    cin>>f;
    return 0;
}
