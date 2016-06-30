/*
 CSci 191T - Information Security 
 Juan Pedraza - 6/29/16
 Purpose:
 	1. Read line in from file and encrypt that line
		1a. encrypt using pattern: c1, c2, c1, c2 ... where c1 uses key 5 and c2 uses key 19
 	2. Decrypt the encrypted line and get back the original plain text
 		2a. write the encrypted line to an output file
 		2b. write the decrypted line to an output file ... should match the original text.
 Notes:
 	* only encryptes alpha chars. if the char is capital then i convert it to lowercase, encrypt it and then capitalize the encrypted char.
	
 Environment: Macbook OSX El Capitan, intel i7 2.2 GHz, 16GB RAM. 
 IDE: Apple Xcode
 
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

//global patter - which order to use the keys in
vector<int> pattern;

//global keys
//int k1 = 5;
//int k2 = 19;
int keys [2] = {5,19};

//declarations
char getPlainChar(char, int); // decrypt char to get plain char
char getCipherChar(char, int); // encrypt char to get encrypted char
string encryptString(string); // encrypt string
string decryptString(string); // decrypt string


int main()
{
	//set the pattern as c1, c2, c1, c2 ...
	pattern.push_back(1);
	pattern.push_back(2);
	
    string plainFileName = "plainText.txt";
	string encryptedFileName = "encryptedText.txt";
	string decryptedFileName = "decryptedText.txt";
	
	ifstream plainFile (plainFileName); // open plain file text
	
    string plainText = "";
	getline(plainFile, plainText); // get plain text
	
	cout << "Plain Text:\n\t" << plainText << endl;
	
	string encryptedString = encryptString(plainText); // encrypt string
	
	ofstream encryptedFile (encryptedFileName); // to store the encrypted string
	encryptedFile << encryptedString; // save encrypted string to file
	
	cout << "Encrypt Text:\n\t " << encryptedString << endl;
	
	//decrypt encrypted string
	string decryptedStr = decryptString(encryptedString);
	
	ofstream decryptedFile (decryptedFileName); // file to store the decrypted text
	decryptedFile << decryptedStr;
	
	cout << "Decrypted Text:\n\t" << decryptedStr << endl;
	
    
    
    
    plainFile.close();
	encryptedFile.close();
	decryptedFile.close();
	
    //epiloge
	cout << endl << "** Exit ** " << endl;
    
    return 0;
}


/* encryptString
 	Input: string plainText
 	Output: string encrypted version of the plain text
 */
string encryptString(string plainText)
{
    string eString = ""; // encrypted string final output
	
	// loop through the string and get encrypted version of the string
	// non alpha characters are left the same
    for(int i=0; i < plainText.length(); i++)
    {
		if( isalpha(plainText[i]) == 0 ) // not alpha
			eString += plainText[i];
		else // is alpha
		{
			int patternIndex = i % pattern.size(); // determin which key to use to encrypt this char
			int stepSize = keys[patternIndex]; // get the key (stepSize)
			
			eString += getCipherChar(plainText[i], stepSize);
		}
			
    }
    
    return eString;
}

/* getCipherChar
	Input: 
 		char c - to be "encrypted"
		int step - number of steps to move c forward to get the encrypted version of c
 	Output: char e - "encrypted" version of the given char
 */
char getCipherChar(char c, int step)
{
	// if the char is upper then convert it to lower and call this function with that lower value and capitalize after return
	if(isupper(c))
	{
		char encryptChar = getCipherChar(tolower(c), step); // conver to lower case and then call function
		return toupper(encryptChar);
	}
	
	// only lower case at this point
	char encryptChar = c + step;
	int encryptInt = int(c) + step;
	
	if(encryptInt > int('z')) // have to circle around and start at 'a'
		encryptChar = encryptInt - int('z') - 1 + 'a'; // 122 = 'z' ... so 123 should get you 'a'
	
	return encryptChar;
}

/* decryptString
Input: 
 	string eString - encrypted string
 Output:
 	string pString - decrypted string
*/
string decryptString(string eString)
{
	string pString = ""; // to store the generated plain string
	
	// loop through each char and decrypt each one and add to the plain string
	for(int i=0; i < eString.length(); i++)
	{
		if(isalpha(eString[i]) == 0) // not alpha so ignore and just add to the plain string
		{
			pString += eString[i];
		}else // was alpha so have to decrypt it
		{
			int patternIndex = i % pattern.size(); // determine which key was used to encrypt this char
			int stepSize = keys[patternIndex]; // get the key needed to decrypt
			pString += getPlainChar(eString[i], stepSize);
		}
	}
	return pString;
}

/* getPlainChar
 Input:
 	char c - encrypted char
 	int step - step size
 Output: 
 	char plainChar - decrypted char
 Use the step to convert c to its unencrypted (plain) state
*/
char getPlainChar(char c, int step)
{
	//if upper case then conver to lower case and recursively call this function with the lower case version.
	// then capitalize the result from that and return char
	if(isupper(c))
	{
		char plainChar = getPlainChar(tolower(c), step);
		return toupper(plainChar);
	}
	
	// only lower case at this point
	char plainChar = c - step;
	int decryptInt = int(c) - step;
	if(decryptInt < int('a')) // have to circle around and go back from 'z'
		plainChar = 'z' + (decryptInt - int('a') + 1); // if you go below 'a' you should circle back and cont back from 'z'
	
	return plainChar;
	
}

