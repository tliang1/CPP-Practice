#ifndef TLDATE_H
#define TLDATE_H

#include <string>

class TLDate
{
private:
	const int months[12] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	const int daysForEachMonth[12]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	const std::string days[7]{ "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
public:
	TLDate() {};

	/// <summary>
	/// Use Zeller's algorithm to get the day of the week of the date.
	/// </summary>
	/// <param name="date">
	/// The date in string format. Format: ##/##/####
	/// </param>
	/// <returns>
	/// Returns the day of the week.
	/// </returns>
	const std::string getDayOfTheWeek(const std::string date);

	/// <summary>
	/// Get total days since January 1st of the year.
	/// </summary>
	/// <param name="date">
	/// The date in string format. Format: ##/##/####
	/// </param>
	/// <returns>
	/// Returns the total days.
	/// </returns>
	const int getDayNumber(const std::string date);

	/// <summary>
	/// Make sure the date is in correct format before using the other functions.
	/// </summary>
	/// <param name="date">
	/// The date in string format. Format: ##/##/####
	/// </param>
	/// <returns>
	/// Returns true if the date is in the correct format.
	/// </returns>
	bool validDate(const std::string date);
};

#endif