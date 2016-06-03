/* main.cpp : Create a program that will print the pascal triangle up to the row that the user enters or take coordinates and prints the corresponding 
number in pascals triangle.
*/

#include "stdafx.h"
#include "TLFunctions.h"
#include <iostream>

/// <summary>
/// Print a complete pascal triangle up to the specified row or print the value at a specified position(row, column).
/// </summary>
/// <param name="row">
/// The row of the pascal triangle.
/// </param>
/// <param name="column">
/// The column of the pascal triangle. If left empty, entire pascal triangle is printed up to the specified row.
/// </param>
/// <returns>
/// Returns the complete pascal triangle up to the specified row or the value at the specified position(row, column).
/// </returns>
void printNumberInPascalTriangle(const unsigned int row, const unsigned int column = 0)
{
	using namespace std;

	if (column > row)
		cout << "Column is greater than row. Invalid." << endl;

	vector< vector<unsigned int> > pascal(row, vector<unsigned int>(row));
	for (unsigned int i = 0; i < row; ++i)
	{
		for (unsigned int j = 0; j <= i; ++j)
		{
			if ((j == 0) || (j == i))
			{
				pascal[i][j] = 1;
			}
			else
			{
				pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
			}

			if ((i == (row - 1)) && (j == (column - 1)))
			{
				cout << pascal[i][j] << endl;
				return;
			}

			if (column == 0)
			{
				cout << pascal[i][j] << " ";
			}
		}
		if (column == 0)
		{
			cout << endl;
		}
	}
}

void printPascalTriangle(const int lines = 15)
{
	printNumberInPascalTriangle(lines);
}

int main()
{
	using namespace std;

	cout << "Welcome to Pascal Triangle!\n";
	
	char input;
	
	do
	{
		cout << "Do you want to print a specific value in a pascal triangle based on a [C]oordinate or print an [E]ntire pascal triangle?: ";
		while (!(cin >> input) || ((tolower(input) != 'c') && (tolower(input) != 'e')))
		{
			cout << "Do you want to print a specific value in a pascal triangle based on a [C]oordinate or print an [E]ntire pascal triangle?: ";
			TL::clearInput();
		}

		if (tolower(input) == 'c')
		{
			cout << "Enter the coordinates(Format: row column): ";
			unsigned int row = 0, column = 0;
			while (!(cin >> row >> column))
			{
				cout << "Enter the coordinates(Format: row column): ";
				TL::clearInput();
			}
			printNumberInPascalTriangle(row, column);
		}
		else
		{
			cout << "Enter the number of lines for the pascal triangle: ";
			unsigned int lines = 0;
			while (!(cin >> lines) || (lines < 1))
			{
				cout << "Enter the number of lines for the pascal triangle: ";
				TL::clearInput();
			}
			printPascalTriangle(lines);
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