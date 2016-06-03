// main.cpp : Create a stopwatch application.

#include "stdafx.h"
#include "Stopwatch.h"
#include "TLFunctions.h"
#include <iostream>
#include <fstream>

int main()
{
	using namespace std;
	
	Stopwatch timer;

	cout << "Stop Watch" << endl;
	
	char input;
	
	ofstream output_file("time.txt");
	
	if (output_file.is_open())
	{
		do
		{
			cout << "[S]tart timer or [Q]uit program: ";
			while (!(cin >> input) || ((tolower(input) != 's') && (tolower(input) != 'q')))
			{
				cout << "[S]tart timer or [Q]uit program: ";
				TL::clearInput();
			}

			if (tolower(input) == 's')
			{
				timer.start();
				int lap = 1;
				do
				{

					cout << "[P]ause timer, [R]eset timer, or [L]ap timer: ";
					while (!(cin >> input) || ((tolower(input) != 'p') && (tolower(input) != 'r') && (tolower(input) != 'l')))
					{
						cout << "[P]ause timer, [R]eset timer, or [L]ap timer: ";
						TL::clearInput();
					}

					switch (tolower(input))
					{
					case 'p':
						timer.stop();
						cout << "Paused at " << timer.elapsed() << " seconds." << endl;
						break;
					case 'r':
						timer.stop();
						cout << "Total time: " << timer.elapsed() << " seconds." << endl;
						output_file << "Total time: " << timer.elapsed() << " seconds.\n";
						timer.reset();
						break;
					case 'l':
						double currentLapTime = timer.lap();
						cout << "Lap " << lap << ": " << currentLapTime << " seconds." << endl;
						output_file << "Lap " << lap << ": " << currentLapTime << " seconds.\n";
						++lap;
						break;
					}

					if (tolower(input) == 'p')
					{
						cout << "[U]npause timer or [R]eset timer: ";
						while (!(cin >> input) || ((tolower(input) != 'u') && (tolower(input) != 'r')))
						{
							cout << "[U]npause timer or [R]eset timer: ";
							TL::clearInput();
						}

						switch (tolower(input))
						{
						case 'u':
							timer.start();
							break;
						case 'r':
							timer.stop();
							cout << "Total time: " << timer.elapsed() << " seconds." << endl;
							output_file << "Total time: " << timer.elapsed() << " seconds.\n";
							timer.reset();
							break;
						}
					}
				} while (tolower(input) != 'r');
			}
		} while (tolower(input) != 'q');
	}

	cout << endl;

	output_file.close();

    return 0;
}