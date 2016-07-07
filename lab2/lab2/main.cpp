/*
	CSci 191T - Information Security
 	Juan Pedraza - 7/5/16
 	Description:
		Write a program that takes a string input, converts to a set of integers with each integer
		being the index (1-26) of the corresponding character in the alphabetic letters. Then, 
 		use RSA with parameters: p=5, q=7, e=5, d=29. First, it performs encryption and prints 
 		the cipher integers. After that, it takes the same cipher integers and performs 
 		decryption and prints the original string.
 
	 Bonus: 20% bonus is given to implementation that determines p, q, e, and d by calling some functions.
 
 	Environment: MacBook OSX El Capitan , intel i7 2.2 GHz, 16GB RAM
 	IDE: Apple Xcode
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
//#include <stdlib.h>
#include <string>

using namespace std;

// global values
// initiallaly hard coded but will eventually generate these values
int P_val = 5;
int Q_val = 7;

int E_val = 5;
int D_val = 29;
int N_val = P_val * Q_val;

//declare
vector<string> RSAencryptString(string);
vector<string> RSAdecryptString(vector<string>);

string RSAencryptChar(char);
string RSAdecryptChar(string);

string vecToStr(vector<string>);

int main(int argc, const char * argv[]) {
	
	string inputFileName = "input.txt"; // input file name. will have the input string. 1 line
	string ecryptedFileName = "encrypted.txt"; // to store the output string
	string decryptedFileName = "decrypted.txt"; // to store the decrypted string. should be same as input.txt
	
	ifstream plainFile(inputFileName); // open the file with the plain text
	ofstream ecryptedFile(ecryptedFileName); // open file to write the encrypted text
	ofstream decryptedFile(decryptedFileName); // open file to write the decrypted text
	
	string plainText;
	getline(plainFile, plainText);
	
	cout << "Plain Text:\n\t" << plainText << endl;
	
	// call to encrypt the plain text using RSA
	vector<string> eVec = RSAencryptString(plainText);
	string eText = vecToStr(eVec);
	
	cout << "Encrypted Text:\n\t" << eText << endl;
	
	ecryptedFile << eText << endl; // save output to file
	
	// decrypte cipher text with the RSA
	vector<string> dVec = RSAdecryptString(eVec);
	string dText = vecToStr(dVec);
	
	cout << "Decrypted Text:\n\t" << dText << endl;
	
	decryptedFile << dText << endl; // save decrypted text to file.
	
	
	// clean up close all the files
	plainFile.close();
	ecryptedFile.close();
	decryptedFile.close();
	
    return 0;
}

// function definitions

/*
 Takes in a unecrypted string value and then encrypties the characters of that string using RSA and the globally set values.
 Input:
 	string plainText - unecrypted plain text to be encrypted
 Output:
 	vector<string> eString - RSA encrypted version of the string given string, each char is an element in the vector
*/
vector<string> RSAencryptString(string plainText)
{
	//string eString = ""; // to store generated ecrypted string
	vector<string> eString (0);
	
	for(int i=0; i < plainText.size(); i++)
	{
		//char eChar = plainText[i];
		if(isalpha(plainText[i]) == false) // non alpha char
		{
			//eString = eString + plainText[i] + " "; // add to eString and continue to next char
			string tStr = string(1,plainText[i]);
			eString.push_back(tStr);
		}else{ // is an alpha char
			//eString = eString + RSAencryptChar(plainText[i]) + " ";
			eString.push_back(RSAencryptChar(plainText[i]));
		}
	}
	
	return eString;
}

/*
 Takes a character and encrypts it using RSA and the current global values
 Input:
 	char pChar - plain text char to be encrypted
 Output:
 	char eChar - encrypted version of the given char
*/
string RSAencryptChar(char pChar)
{
	string eChar = ""; // to store the ecrypted char ... which will be a number
	if(isupper(pChar) == true) // if uppercase
	{
		pChar = tolower(pChar); // convert to lower case
		//eChar = RSAencryptChar(tolower(pChar)); // convert to lowercase and recusive call
		//return toupper(eChar);
	}
	//lower case
	
	//TODO: find more efficient way of doing calc
	unsigned long long int num = pChar - (int('a')-1); // 'a' -> 1, 'b'->2 ...
	
	num = pow(num, E_val) ;//% N_val;
	num = num % N_val;
	
	eChar = to_string(num); // convert int to string
	
	return eChar;
}

/*
 Input:
 	eVec - encrypted vector
*/
vector<string> RSAdecryptString(vector<string> eVec)
{
	vector<string> dVec (0); // vector with the decrypted characters
	
	for(int i=0; i < eVec.size(); i++)
	{
		string temp = RSAdecryptChar(eVec[i]);
		dVec.push_back(temp);
	}
	
	return dVec;
}


string RSAdecryptChar(string eStr)
{
	//int num = atoi(eStr);
	int num = stoi(eStr, nullptr, 10); // convert string to int
	if(num == 0) // was not a number
	{
		return eStr;
	}
	else
	{
		//TODO: find more efficient way of doing calculation
		unsigned long long int num2 = pow(num, D_val);
		num2 = num2 % N_val;
		
		char c = 'a' - 1 + num2;
		
		return string(1,c);
	}
}

/*
 Takes in a vector of strings and then iterates through the elemenents an add to a string to return. (space delimited)
*/
string vecToStr(vector<string> vec)
{
	string rString = "";
	
	for(int i=0; i < vec.size(); i++)
	{
		rString = rString + vec[i] + " ";
	}
	// now remove the last space at the end
	rString = rString.substr(0, rString.size()-1);
	
	return rString;
}
