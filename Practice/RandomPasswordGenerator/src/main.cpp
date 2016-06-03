// main.cpp : Random password generator with default and custom settings.

#include "stdafx.h"
#include "TLFunctions.h"
#include <iostream>
#include <string>

std::string generatePassword(const int length)
{
	std::string password;
	for (int j = 0; j < length; ++j)
	{
		password.push_back(static_cast<char>(TL::getRandomNumber(33, 126)));
	}

	return password;
}

int main()
{
	using namespace std;

	char input;
	
	cout << "Password Generator\n";
	
	do
	{
		cout << "Generate password using [D]efault settings or [C]ustom settings? [Q]uit program: ";
		while (!(cin >> input) || ((tolower(input) != 'd') && (tolower(input) != 'c') && (tolower(input) != 'q')))
		{
			cout << "Generate password using [D]efault settings or [C]ustom settings? [Q]uit program: ";
			TL::clearInput();
		}

		if (tolower(input) == 'd')
		{
			cout << "Your generated password is: " << generatePassword(TL::getRandomNumber(12, 16)) << endl;
		}
		else if (tolower(input) == 'c')
		{
			cout << "How long do you want your password to be?(Minimum:4): ";
			int length = 4;
			while (!(cin >> length) || length < 4)
			{
				cout << "How long do you want your password to be?(Minimum:4): ";
				TL::clearInput();
			}

			cout << "How many passwords do you want to generate?(Minimum:1): ";
			int numOfPass = 1;
			while (!(cin >> numOfPass) || numOfPass < 1)
			{
				cout << "How many passwords do you want to generate?(Minimum:1): ";
				TL::clearInput();
			}

			if (numOfPass > 1)
			{
				cout << "Your generated passwords: \n";
				for (int i = 1; i < numOfPass; ++i)
				{
					cout << "Password # " << i << ": " << generatePassword(length) << "\n";
				}
				cout << "Password # " << numOfPass << ": " << generatePassword(length) << endl;
			}
			else
			{
				cout << "Your generated password is: " << generatePassword(length) << endl;
			}
		}
		
	} while (tolower(input) != 'q');

	cout << endl;

    return 0;
}