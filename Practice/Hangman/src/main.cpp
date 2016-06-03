// main.cpp : A hangman game.

#include "stdafx.h"
#include "Hangman.h"
#include "TLFunctions.h"

int main()
{
	using namespace std;

	cout << "Welcome to Hangman!\n";
	
	char input;

	do
	{
		Hangman hangman;
		hangman.drawHangman();

		do
		{
			char guess;
			cout << "Guess a letter(You have " << hangman.getTriesLeft() << " tries left): ";
			while (!(cin >> guess) || !isalpha(guess) || hangman.alreadyTried(guess))
			{
				if (hangman.alreadyTried(guess))
				{
					cout << "You already tried that letter." << endl;
				}
				cout << "Guess a letter(You have " << hangman.getTriesLeft() << " tries left): ";

				TL::clearInput();
			}

			hangman.updateHangman(guess);

			if (hangman.isCorrect())
			{
				cout << "Congratulations! You guess the word correctly." << endl;
			}

			TL::clearInput();

			if ((!hangman.isCorrect()) && (!hangman.isGameOver()))
			{
				cout << "Do you want to [G]uess again or you already know the [A]nswer?: ";
				while (!(cin >> guess) || ((tolower(guess) != 'g') && (tolower(guess) != 'a')))
				{
					cout << "Do you want to [G]uess again or you already know the [A]nswer?: ";
					TL::clearInput();
				}

				if (tolower(guess) == 'a')
				{
					string answer;
					cout << "Enter what word you think it is: ";
					cin >> answer;

					if (hangman.checkGuess(answer))
					{
						cout << "Congratulations! You guess the word correctly." << endl;
					}
					else
					{
						cout << "You did not guess the word correctly. You lose a try." << endl;
					}
				}
			}
		} while ((!hangman.isCorrect()) && (!hangman.isGameOver()));

		if (hangman.isGameOver())
		{
			cout << "You lose. You did not guess the word correctly within " << hangman.maxTries << " tries. The word is: " << hangman.getWord() << endl;
		}

		cout << "Do you want to [P]lay again or [Q]uit the program?: ";
		while (!(cin >> input) || ((tolower(input) != 'p') && (tolower(input) != 'q')))
		{
			cout << "Do you want to [P]lay again or [Q]uit the program?: ";
			TL::clearInput();
		}

	} while (tolower(input) != 'q');

	cout << endl;

	return 0;
}

