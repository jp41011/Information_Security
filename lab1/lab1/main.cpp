// lab1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

//global keys
int k1 = 5;
int k2 = 19;

//int pattern [] = {1,2,1,2};

/*vector<int> pattern (0);
 pattern.push_back(1);
 pattern.push_back(2);
 */

char getPlainChar(char, int);
char getCipherChar(char, int);
string encryptString(string);
string decryptString(string);


int main()
{
    string plainFileName = "plainText.txt";
    ifstream plainFile (plainFileName);
    
    string plainText = "";
    getline(plainFile, plainText);
    
    cout << "Plain Text: " << plainText << endl;
    
    
    
    plainFile.close();
    //epiloge
    cout << "Hello World" << endl;
    char x;
    cin >> x;
    
    return 0;
}

string encryptString(string plainText)
{
    string eString = ""; // encrypted string final output
    //int patternLen = pattern.length();
    
    for(int i=0; i < plainText.length(); i++)
    {
        //eString += getCipherChar(plainText[i], );
    }
    
    return eString;
}

