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


using namespace std;

// global values
// initiallaly hard coded but will eventually generate these values
int P_val = 5;
int Q_val = 7;
int E_val = 5;
int D_val = 29;

//declare
string RSAencryptString(string);
string RSAdecryptString(string);

char RSAencryptChar(char);
char RSAdecryptChar(char);

int main(int argc, const char * argv[]) {
	
	string inputFileName = "input.txt"; // input file name. will have the input string. 1 line
	string ecryptedFileName = "encrypted.txt"; // to store the output string
	string decryptedFileName = "decrypted.txt"; // to store the decrypted string. should be same as input.txt
	
	ifstream plainFile(inputFileName); // open the file with the plain text
	ofstream ecryptedFile(ecryptedFileName); // open file to write the encrypted text
	ofstream decryptedFile(decryptedFileName); // open file to write the decrypted text
	
	string plainText;
	getline(plainFile, plainText);
	
	cout << plainText << endl;
	
	// call to encrypt the plain text using RSA
	
	// save output to file
	
	// decrypte cipher text with the RSA
	
	// save decrypted text to file.
	
	
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
 	string eString - RSA encrypted version of the string given string
*/
string RSAencryptString(string plainText)
{
	string eString = ""; // to store generated ecrypted string

	return eString;
}

/*
 Takes a character and encrypts it using RSA and the current global values
 Input:
 	char pChar - plain text char to be encrypted
 Output:
 	char eChar - encrypted version of the given char
*/
char RSAencryptChar(char pChar)
{
	char eChar = ' '; // to store the ecrypted char
	
	return eChar;
}

//string RSAdecryptString(string);
//char RSAdecryptChar(char);
