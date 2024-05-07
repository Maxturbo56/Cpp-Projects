#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    string chars;
    vector<char> matrix_ready;
    char matrix_table[26][26];
    string cypher;
    ifstream fajl_cypher;
    ifstream fajl_abc;
    // -----------------------------------
    fajl_cypher.open("poruka.txt", ios::in);
    fajl_cypher >> cypher;
    fajl_cypher.close();
    cout << "Gained access to cypher!\nCypher text : " << cypher << endl;
    // ---------------------------------
    fajl_abc.open("abc.txt", ios::in);
    fajl_abc >> chars;
    fajl_abc.close();
    int k = 0;
    int row = 0;      // i
    int collumn = -1; // j
    while (k < chars.size())
    {
        if (k % 26 == 0)
        {
            row = 0;
            collumn++;
            cout << endl;
        }
        matrix_table[row][collumn] = chars[k];
        cout << "Entered " << chars[k] << " to position : " << row << " " << collumn << endl;
        k++;
        row++;
    }

    cout << endl
         << endl;

    // PRINTING MATRIX DECYPHER
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            cout << matrix_table[i][j] << " ";
        }
        cout << endl;
    }

    // RESOLUTION
    string keyword;
    cout << "Please enter the given keyword for this cypher matrix : " << endl;
    cin >> keyword;
    int keyword_pointer = 0;
    int cypher_pointer = 0;
    string secret_keyword = "";
    cout << "Cypher is : " << cypher << endl
         << endl;
    while (cypher_pointer < cypher.size())
    {
        secret_keyword += keyword[keyword_pointer];
        if (keyword_pointer == keyword.size() - 1)
        {
            keyword_pointer = -1;
        }
        keyword_pointer++;
        cypher_pointer++;
    }
    cout << "Recompiled secret keyword lenght in keyword status is : " << secret_keyword << endl
         << endl;

    // ------------------------------------------------------- //
    // sad imas secret keyword i cypher i sad pravis message!! //
    // ------------------------------------------------------- //

    // secret keyword je nedimned
    // cypher je nqvcmgwo

    string original_message = "";
    
    int cypher_row = 0;
    int cypher_collumn = 0;
    for (int k = 0; k < secret_keyword.size(); k++)
    {

        for (int i = 0; i < 26; i++)
        {
            if (matrix_table[0][i] == secret_keyword[k])
            {
                cypher_collumn = i;
                break;
            }
        }
        for (size_t i = 0; i < 26; i++)
        {
            if (matrix_table[i][cypher_collumn] == cypher[k])
            {
                cypher_row = i;
                break;
            }
            
        }
    
        original_message += matrix_table[cypher_row][0];
    }
    cout << "ORIGINAL MESSAGE TEXT RESULT : " << original_message << endl;

    int f;
    cin >> f;
    return 0;
}