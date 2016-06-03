// main.cpp : Encrypt and decrypt texts with an alphabetical caesar cipher. This cipher ignores numbers, symbols, and whitespace.

#include "stdafx.h"
#include "CaesarCipher.h"
#include <iostream>
#include <string>

void clearInput()
{
	using namespace std;
	// Clean up the input stream
	cin.clear(); // Clear the error state of the stream
	// Empty the keyboard buffer
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main()
{
	Caesar_Cipher cc;
	char input;

	std::cout << "Welcome to the Caesar Cipher program!\n";

	do
	{
		std::string text;
		std::cout << "Enter text: ";
		std::getline(std::cin, text);

		int shift = 0;

		std::cout << "Enter the number of shifts(-25 to 25): ";
		while (!(std::cin >> shift) || shift < -25 || shift > 25)
		{
			std::cout << "Enter the number of shifts(-25 to 25): ";
			clearInput();
		}

		std::cout << "Do you want to [E]ncrypt or [D]ecrypt this text?: ";
		while (!(std::cin >> input) || (tolower(input) != 'e' && tolower(input) != 'd'))
		{
			std::cout << "Do you want to [E]ncrypt or [D]ecrypt this text?: ";
			clearInput();
		}

		if (tolower(input) == 'e')
		{
			text = cc.encrypt(text, shift);
			std::cout << "The encrypted text is: ";
		}
		else
		{
			text = cc.decrypt(text, shift);
			std::cout << "The decrypted text is: ";
		}

		std::cout << text << std::endl;

		std::cout << "Do you want to [S]tart over or [Q]uit the program?: ";
		while (!(std::cin >> input) || (tolower(input) != 's' && tolower(input) != 'q'))
		{
			std::cout << "Do you want to [S]tart over or [Q]uit the program?: ";
			clearInput();
		}

		clearInput();

	} while (tolower(input) != 'q');
	
	std::cout << std::endl;

    return 0;
}
