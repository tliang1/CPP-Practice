// main.cpp : Testing custom Date class.

#include "stdafx.h"
#include "TLDate.h"
#include "TLFunctions.h"

int main()
{
	using namespace std;

	cout << "Welcome to the TLDate Class Program!\n";
	TLDate tlDate;
	char input;

	do
	{
		string date;
		while (!tlDate.validDate(date))
		{
			cout << "Enter the date(Format: ##/##/####): ";
			cin >> date;
			TL::clearInput();
		}

		cout << "Do you want to know the day of the [W]eek of the date or the [N]umber of days up to the date?: ";
		while (!(cin >> input) || ((tolower(input) != 'w') && (tolower(input) != 'n')))
		{
			cout << "Do you want to know the day of the [W]eek of the date or the [N]umber of days up to the date?: ";
			TL::clearInput();
		}

		if (tolower(input) == 'w')
		{
			cout << "The day of the week for " << date << " is " << tlDate.getDayOfTheWeek(date) << endl;
		}
		else
		{
			cout << "The day number for " << date << " is " << tlDate.getDayNumber(date) << endl;
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