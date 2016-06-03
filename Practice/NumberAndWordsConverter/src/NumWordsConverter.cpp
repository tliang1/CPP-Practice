#include "NumWordsConverter.h"
#include <vector>

std::string NumWordsConverter::numberToWords(const unsigned long long number)
{
	std::string text;

	if (number == 0)
	{
		return ones[number];
	}
	else
	{
		unsigned long long tempNum = number;

		// Example: 123456789
		// digitPosition starts at 0 which is at digit 9 and increases everytime digit(s) is/are shifted left.
		int digitPosition = 0;

		while (tempNum != 0)
		{
			int threeDigitNum = static_cast<int>(tempNum % 1000); // Use to get every last three digits of tempNum.
			tempNum /= 1000; // Keep every digit except the last three digits at each loop around
			int hundredNum = threeDigitNum / 100; // The hundred digit
			int tenNum = (threeDigitNum - (hundredNum * 100)) / 10; // The ten digit
			int remain = (threeDigitNum - (hundredNum * 100)) % 10; // The third digit

			// Skip and loop again if threeDigitNum is 000. Example: 123000123 and threeDigitNum is currently 000
			if (((hundredNum == 0) && (tenNum == 0) && (remain == 0)) == false)
			{
				// Add "hundred", "thousand", "million", etc. word first if the threeDigitNum is not the last three digits of the number variable
				if ((number >= 1000) && (digitPosition > 2))
				{
					if (text == "")
					{
						text = rest[static_cast<int>(ceil((digitPosition + 1) / 3.0) - 1)] + text;
					}
					else
					{
						text = rest[static_cast<int>(ceil((digitPosition + 1) / 3.0) - 1)] + " , " + text;
					}
				}

				// If the second and third digit does not make the number 0 or 10 - 19, add the word of remain
				if ((tenNum == 0 || tenNum > 1) && (remain > 0))
				{
					text = ones[remain] + " " + text;
				}

				// If the second and third digit does make a number between 10 and 99
				if (tenNum > 0)
				{

					// If the second and third digit does make a number between 20 and 99, add the word of tenNum (Example: 55 -> fifty)
					if (tenNum > 1)
					{
						text = tens[tenNum - 1] + " " + text;
					}
					// If the second and third digit does make a number between 10 and 19, add the word of that number
					else
					{
						// If the number is 10
						if (remain == 0)
						{
							text = tens[remain] + " " + text;
						}
						else
						{
							text = ones[remain + 9] + " " + text;
						}
					}
				}

				/* If the hundredNum is greater than zero which means the threeDigitNum is between 100 to 999, add the word of the hundredNum and the word
				"hundred" after it*/
				if (hundredNum > 0)
				{
					text = ones[hundredNum] + " " + rest[0] + " " + text;
				}
			}

			// Shift left to the next digit correctly
			if ((threeDigitNum > 99) || (threeDigitNum == 0) || tempNum > 0)
			{
				digitPosition += 3;
			}
			else if (threeDigitNum > 9)
			{
				digitPosition += 2;
			}
			else
			{
				++digitPosition;
			}
		}

		// Remove extra space at the end of the text
		if (text[text.length() - 1] == ' ')
		{
			text.pop_back();
		}

		return text;
	}
}

unsigned long long NumWordsConverter::wordsToNum(const std::string &text)
{
	using namespace std;

	unsigned long long number = 0;
	vector<string> commaWords = TL::split(text, ',');
	for (const string &commaWord : commaWords)
	{
		vector<string> &words = TL::split(commaWord, ' ');

		/* Last element must be one for this formula to get the right number: ([#] = value in element #) ((([0] * [1]) + [2] + [3]) * [4])
		[0] is between 0 - 9, [1] is either 0 or 100, [2] is a multiple of 10 between 0 and 90, [3] is between 0 - 9, and [4] is 1000^x where x is positive.
		*/
		unsigned long long numbers[5]{ 0, 0, 0, 0, 1 };

		int index = 0; // Keep track of where to put the number value in numbers array

		for (int i = words.size() - 1; i >= 0; --i)
		{
			for (const auto &wordAndNumPair : wordAndNumberMap)
			{
				// For each word, find the corresponding value
				if (words[i] == wordAndNumPair.first)
				{
					// If value is 1000^x where x is greater than 0
					if (wordAndNumPair.second > 100)
					{
						index = 4;
					}
					else if (wordAndNumPair.second == 100)
					{
						index = 1;
					}

					// If value is a multiple of 10 and not zero
					else if (wordAndNumPair.second >= 10)
					{
						index = 2;
					}
					else
					{
						// Only if value is to be multiplied by 1000^x where x is positive
						if (index != 1)
						{
							index = 3;
						}

						// Only if value is to be multiplied by 100
						else
						{
							index = 0;
						}

					}

					numbers[index] = wordAndNumPair.second;
					break;
				}
			}
		}

		// Example: [123],456 -> When calculating for [123], ((1 * 100) + 20 + 3) * 1000 = 123000. Doing the same for [456] and adding it to 123000 = 123456.
		number += (((numbers[0] * numbers[1]) + numbers[2] + numbers[3]) * numbers[4]);
	}

	return number;
}