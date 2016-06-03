#ifndef NUMWORDSCONVERTER_H
#define NUMWORDSCONVERTER_H

#include "TLFunctions.h"
#include <map>
#include <string>

/// <summary>
/// NumWordsConverter class for the number to words and words to number converter.
/// </summary>
class NumWordsConverter
{
private:
	const std::string ones[20]{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "eleven", "twelve", "thirteen", "fourteen",
		"fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	const std::string tens[9]{ "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
	const std::string rest[7]{ "hundred", "thousand", "million", "billion", "trillion", "quadrillion", "quintillion" };

	const std::map<std::string, unsigned long long> wordAndNumberMap{ { "zero", 0 }, { "one", 1 }, { "two", 2 }, { "three", 3 }, { "four", 4 }, 
	{ "five", 5 }, { "six", 6 }, { "seven", 7 }, { "eight", 8 }, { "nine", 9 }, { "ten", 10 }, { "eleven", 11 }, { "twelve", 12 }, { "thirteen", 13 }, 
	{ "fourteen", 14 }, { "fifteen", 15 }, { "sixteen", 16 }, { "seventeen", 17 }, { "eighteen", 18 }, { "nineteen", 19 }, { "twenty", 20 }, 
	{ "thirty", 30 }, { "forty", 40 }, { "fifty", 50 }, { "sixty", 60 }, { "seventy", 70 }, { "eighty", 80 }, { "ninety", 90 }, { "hundred", 100 }, 
	{ "thousand", 1000 }, { "million", 1000000 }, { "billion", 1000000000 }, { "trillion", 1000000000000 }, { "quadrillion", 1000000000000000 }, 
	{ "quintillion", 1000000000000000000 } };

public:
	NumWordsConverter() {}

	/// <summary>
	/// The number is converted to words three digits at a time from right to left because it is easier to track. Every three digits are converted
	/// separatedly to words.
	/// </summary>
	/// <param name="number">
	/// The number used for conversion.
	/// </param>
	/// <returns>
	/// Returns the number in word representation.
	/// </returns>
	std::string numberToWords(const unsigned long long number);

	/// <summary>
	/// The text is converted to the number three digits at a time from left to right because it is easier to track.
	/// </summary>
	/// <param name="text">
	/// The number in words representation used for conversion.
	/// </param>
	/// <returns>
	/// Returns the number.
	/// </returns>
	unsigned long long wordsToNum(const std::string &text);
};

#endif