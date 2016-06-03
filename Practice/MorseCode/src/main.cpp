// main.cpp : Create a program that can translate Morse code to text and vice versa.

#include "stdafx.h"
#include <iostream>
#include <string>

std::string morseToText(const std::string &morse, const char *t, const std::string *m, const int length)
{
	std::string temp = "";
	std::string text = "";

	for (unsigned int i = 0; i < morse.length(); ++i)
	{
		// Form each morse code.
		if ((morse[i] != ' ') && (morse[i] != '/') && (i != morse.length() - 1))
		{
			temp += morse[i];
		}
		else
		{
			// Must form the last morse code.
			if (i == morse.length() - 1)
			{
				temp += morse[i];
			}

			// For each morse code, decode it.
			for (int j = 0; j < length; ++j)
			{
				if (temp == m[j])
				{
					text += t[j];
				}
			}

			temp = "";
		}

		if (morse[i] == '/')
		{
			text += " ";
		}
	}

	return text;
}

std::string textToMorse(const std::string &text, const char *t, const std::string *m, const int length)
{
	std::string morse = "";

	for (const char c : text)
	{
		if (c == ' ')
		{
			morse += "/ ";
		}

		// For each letter, change it to morse code.
		for (int i = 0; i < length; ++i)
		{
			if (toupper(c) == t[i])
			{
				morse += m[i] + " ";
			}
		}
	}

	morse.pop_back(); // Remove the extra space after the last morse code
	return morse;
}

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
	using namespace std;

	char t[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	string m[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".-- -", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
		"...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };

	cout << "Welcome to Morse Code/Text Converter!\n";

	char input;
	
	do
	{
		cout << "Do you want to convert text to [M]orse code or morse code to [T]ext?: ";
		while (!(cin >> input) || ((tolower(input) != 'm')) && (tolower(input) != 't'))
		{
			cout << "Do you want to convert text to [M]orse code or morse code to [T]ext?: ";
			clearInput();
		}

		cout << "Enter the";
		string txt;
		if (tolower(input) == 'm')
		{
			cout << " text you want to convert to morse code: ";
			clearInput();
			getline(cin, txt);
			cout << "Morse code: " << textToMorse(txt, t, m, 26) << endl;
		}
		else
		{
			cout << " morse code you want to convert to text: ";
			clearInput();
			getline(cin, txt);
			cout << "Text: " << morseToText(txt, t, m, 26) << endl;
		}

		cout << "Do you want to [C]ontinue or [Q]uit the program?: ";
		while (!(cin >> input) || ((tolower(input) != 'c')) && (tolower(input) != 'q'))
		{
			cout << "Do you want to [C]ontinue or [Q]uit the program?: ";
			clearInput();
		}

	} while (tolower(input) != 'q');

	cout << endl;

	return 0;
}

