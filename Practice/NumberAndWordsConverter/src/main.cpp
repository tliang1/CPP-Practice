/* main.cpp : Create a program that will print the english name of an integer or the integer of the english name. For example, "1211" would become "one 
thousand , two hundred , eleven" and "one hundred , four" would become 104.
*/

#include "stdafx.h"
#include "NumWordsConverter.h"
#include "TLFunctions.h"
#include <iostream>
#include <string>

int main()
{
	using namespace std;

	NumWordsConverter nWC;

	cout << "Welcome to the Number Words Converter!" << endl;

	char input;
	
	do
	{
		cout << "Do you want to convert a [N]umber to words or [W]ords to number?: ";
		while (!(cin >> input) || ((tolower(input) != 'n') && (tolower(input) != 'w')))
		{
			cout << "Do you want to convert a [N]umber to words or [W]ords to number?: ";
			TL::clearInput();
		}

		if (tolower(input) == 'n')
		{
			unsigned long long number = 0;
			cout << "Enter a positive integer (max: " << numeric_limits<unsigned long long>::max() << "): ";
			while (!(cin >> number) || number < 0 || number > numeric_limits<unsigned long long>::max())
			{
				cout << "Invalid input. Only a positive integer is allowed.\n";
				cout << "Enter a positive integer (max: " << numeric_limits<unsigned long long>::max() << "): ";
				TL::clearInput();
			}

			string text = nWC.numberToWords(number);

			cout << "Your number is: " << text << endl;
		}
		else
		{
			TL::clearInput();
			string text;
			cout << "Enter a positive integer (max: " << numeric_limits<unsigned long long>::max() << ") in words (Format: \"nine hundred ninety nine "
				<< "thousand , nine hundred ninety nine\" Space between each word and add commas for every three digit): ";
			getline(cin, text);

			cout << "Your number is: " << nWC.wordsToNum(text) << endl;
		}

		cout << "Do you want to [C]ontinue or [Q]uit the program?: ";
		while (!(cin >> input) || ((tolower(input) != 'c') && (tolower(input) != 'q')))
		{
			cout << "Do you want to [C]ontinue or [Q]uit the program?: ";
			TL::clearInput();
		}

	} while (tolower(input) != 'q');

	cout << endl;

	return 0;
}