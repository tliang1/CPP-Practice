#include "TLDate.h"
#include "TLFunctions.h"
#include <regex>
#include <vector>

using namespace std;

const string TLDate::getDayOfTheWeek(const string date)
{
	int numbers[3];
	int index = 0;
	for (const string n : TL::split(date, '/'))
	{
		numbers[index] = stoi(n);
		++index;
	}

	int day = numbers[1];
	int month = (numbers[0] < 3) ? (numbers[0] + 12) : numbers[0]; // 13 = January and 14 = February. Everything else stay the same.
	int year = (month > 12) ? (numbers[2] - 1) : numbers[2]; // Subtract year by 1 if month is January or February.
	int firstTwoDigitsOfYear = year / 100;
	int lastTwoDigitsOfYear = year % 100;

	// Zeller's algorithm or congruence
	const int dayOfTheWeek = (day + (((month + 1) * 13) / 5) + lastTwoDigitsOfYear + (lastTwoDigitsOfYear / 4) + (firstTwoDigitsOfYear / 4)
		+ (5 * firstTwoDigitsOfYear)) % 7;

	return days[dayOfTheWeek];
}

const int TLDate::getDayNumber(const string date)
{
	const int month = stoi(date.substr(0, 2));
	const int day = stoi(date.substr(3, 2));
	const int year = stoi(date.substr(6, 4));

	int dayNumber = 0;
	for (int i = 0; i < (month - 1); ++i)
	{
		dayNumber += daysForEachMonth[i];
	}
	dayNumber += ((year % 4 == 0) && (month > 2)) ? (day + 1) : day; // Add a day if the year is a leap year and the date is Feb 29 or above.

	return dayNumber;
}

bool TLDate::validDate(const string date)
{
	/*
	* Date format:
	* ##/##/####
	*
	* Regular Expression : ^\\d{2}/\\d{2}/\\d{4}$
	* ^ : Beginning of the line
	* \\d{2} : Must be two digits
	* / : Must have a forward slash
	* \\d{2} : Must be two digits
	* / : Must have a forward slash
	* \\d{4} : Must be four digits
	* $ : End of the line
	*/
	auto dateRegex = regex("^\\d{2}/\\d{2}/\\d{4}$");
	if (regex_match(date, dateRegex))
	{
		int numbers[3];
		int index = 0;
		for (string num : TL::split(date, '/'))
		{
			numbers[index] = stoi(num);
			++index;
		}

		for (const int month : months)
		{
			if (month == numbers[0])
			{
				// Leap year
				if ((month == 2) && (numbers[2] % 4 == 0))
				{
					if (numbers[1] <= (daysForEachMonth[month - 1] + 1))
					{
						return true;
					}
				}
				else
				{
					if (numbers[1] <= daysForEachMonth[month])
					{
						return true;
					}
				}
			}
		}
	}

	return false;
}