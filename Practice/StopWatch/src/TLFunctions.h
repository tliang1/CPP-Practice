#ifndef TLFUNCTIONS_H
#define TLFUNCTIONS_H

#include <ctime>
#include <iostream>
#include <random>
#include <sstream>
#include <stdlib.h>
#include <vector>

namespace TL
{
	static void clearInput()
	{
		// Clean up the input stream
		std::cin.clear(); // Clear the error state of the stream
		// Empty the keyboard buffer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	/// <summary>
	/// Randomly generate an integer between a specified range using the Mersenne Twister generator.
	/// </summary>
	/// <returns>
	/// Returns a randomly generated integer.
	/// </returns>
	static int getRandomNumber(int min, int max)
	{
		std::random_device seed;
		std::mt19937 randomNumberGenerator(seed()); // mersenne_twister
		std::uniform_int_distribution<int> idist(min, max);
		return idist(randomNumberGenerator);
	}

	/// <summary>
	/// Split a string by a delimiter.
	/// </summary>
	/// <param name="s">
	/// The string to split.
	/// </param>
	/// <param name="delim">
	/// The character used to delimit the string.
	/// </param>
	/// <param name="elems">
	/// The vector for storing the substrings of the string.
	/// </param>
	/// <returns>
	/// Returns vector of strings that were delimited by the delimiter.
	/// </returns>
	static std::vector<std::string> &split(const std::string &s, const char delim, std::vector<std::string> &elems) 
	{
		std::stringstream ss(s);
		std::string item;
		while (getline(ss, item, delim)) 
		{
			if (!item.empty())
			{
				elems.push_back(item);
			}
		}
		return elems;
	}

	/// <summary>
	/// Split a string by a delimiter.
	/// </summary>
	/// <param name="s">
	/// The string to split.
	/// </param>
	/// <param name="delim">
	/// The character used to delimit the string.
	/// </param>
	/// <returns>
	/// Returns vector of strings that were delimited by the delimiter.
	/// </returns>
	static std::vector<std::string> split(const std::string &s, const char delim) 
	{
		std::vector<std::string> elems;
		split(s, delim, elems);
		return elems;
	}
}

#endif