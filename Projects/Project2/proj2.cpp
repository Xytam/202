/*****************************************
 ** File:    proj2.cpp
 ** Project: CMSC 202 Project 2, "Spring" 2015
 ** Author:  John Horvers
 ** Date:    023/30/2015
 ** Section: 11 19
 ** E-mail:  horvers1@umbc.edu
 **
 ** This is the main driver program for project 2
 ** prompting the user with and easy to use menu
 ** and allowing acces to methods and files.
 **
 ***********************************************/

#include <iostream>
#include <string>
#include "CipherMessage.h"
#include "Date.h"
using namespace std;
int main()
{
	CipherMessage newCipher;
	char selection = 'a';
	string loadedFile = "";
	do
	{	
		if(loadedFile=="")
			cout << "No file loaded\n";
		else
			cout << "\n--------------------------------------\n" <<loadedFile << " loaded.\n--------------------------------------";
		cout << "\nChoose and action from the following menu: \n \n";
		cout << "l - load a cipher file\n";
		cout << "h - display cipher file header\n";
		cout << "t - display cipher file text\n";
		cout << "d - decipher file with known key\n";
		cout << "u - decipher file with unknown key\n";
		cout << "q - quit\n\n";
		cout << "Selection: ";
		cin >> selection;
		switch(selection)
		{
			case 'l':
			{
				//
				string loadFileName;
				cout <<"Cipher file name: ";
				cin >> loadFileName;
				if(newCipher.LoadFromFile(loadFileName))
				{
					cout << "The cipher file "<< loadFileName << " loaded successfully!\n\n";
					loadedFile=loadFileName;
				}
				else
					cout << "Invalid file name!\n";
				break;
			}
			case 'h':
			{
				Date usefulDate = newCipher.GetSentDate();
				//
				cout << newCipher.GetFrom() << "\n" << newCipher.GetTo() << "\n";
				usefulDate.PrintDate();
				break;
			}
			case 't':
			{
				//
				cout << "Ciphertext: " << newCipher.GetText() << "\n";
				break;
			}
			case 'd':
			{
				//
				string key;
				cout << "Please input the key: ";
				cin >> key;
				string plainText=newCipher.Decipher(key);
				cout << "Plain: " << plainText << "\n";
				break;
			}
			case 'u':
			{
				//
				cout << "Plain: " << newCipher.Decipher() << "\n";
				break;
			}
			case 'q':
			{
				cout << "Quitting...\n";
				break;
			}
			default:
			{
				cout << "Your selection was invalid. Please try again.\n";
			}
		}
	}while(selection != 'q');
	return 0;
}	
