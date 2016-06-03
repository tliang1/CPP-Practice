// main.cpp : Create a program that will find the smallest factors of a number.

#include "stdafx.h"
#include "TLFunctions.h"

const int smallestFactor(const int number)
{
	if (number < 0) return 0;

	for (int i = 2; i < number; ++i)
		if (number % i == 0)
			return i;
	return number;
}

void printFactors(int number)
{
	int factor = smallestFactor(number);

	while (factor != number) 
	{
		std::cout << factor << " * ";
		number /= factor;
		factor = smallestFactor(number);
	}

	std::cout << factor << std::endl;
}

int main()
{
	std::cout << "Welcome to the factors of a number program!\n";

	char input;
	
	do
	{
		int number;
		std::cout << "Enter a integer: ";
		while (!(std::cin >> number) || (number < 0))
		{
			std::cout << "Enter a integer: ";
			TL::clearInput();
		}

		std::cout << "Factors for " << number << " are ";

		printFactors(number);

		std::cout << "Do you want to [C]ontinue or [Q]uit the program?: ";
		while (!(std::cin >> input) || ((tolower(input) != 'c') && (tolower(input) != 'q')))
		{
			std::cout << "Do you want to [C]ontinue or [Q]uit the program?: ";
			TL::clearInput();
		}
	} while (tolower(input) != 'q');

	std::cout << std::endl;

	return 0;
}