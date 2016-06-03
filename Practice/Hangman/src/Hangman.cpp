#include "Hangman.h"
#include "TLFunctions.h"

const string Hangman::toLowerCase(const string &text)
{
	string lowerCaseText;
	for (const char c : text)
	{
		lowerCaseText += tolower(c);
	}
	return lowerCaseText;
}

Hangman::Hangman()
{
	// Read and store each word into the words vector of strings
	ifstream wordsFile("words.txt");
	for (string line; wordsFile.good() && getline(wordsFile, line); words.push_back(line));
	wordsFile.close();

	// Randomly pick a word for the user to guess
	word = words[TL::getRandomNumber(0, static_cast<int>(words.size()))]; // Get a random word
}

const string Hangman::getWord()
{
	return word;
}

const int Hangman::getTriesLeft()
{
	return maxTries - tries;
}

bool Hangman::alreadyTried(const char l)
{
	for (const char c : alreadyGuess)
	{
		if (c == tolower(l))
		{
			return true;
		}
	}
	return false;
}

void Hangman::updateHangman(const char c)
{
	alreadyGuess.push_back(tolower(c));

	if (!checkGuess(tolower(c)))
	{
		++tries;
	}

	drawHangman(tries);

	displayCorrectLetters();

	for (int i = 0; i < static_cast<int>(word.length()); ++i)
	{
		cout << "-";
	}
	cout << endl;

	printGuessLetters();
}

bool Hangman::checkGuess(const char c)
{
	bool found = false;
	for (int i = 0; i < static_cast<int>(word.length()); ++i)
	{
		if (word[i] == c)
		{
			correctLetters.push_back(c + to_string(i)); // If c = 'p' and i = 5, then c + to_string(i) = "p5"
			if (!found)
			{
				found = true;
			}
		}
	}

	return found;
}

bool Hangman::checkGuess(const string &userWord)
{
	if (toLowerCase(userWord) == word)
	{
		correct = true;
	}
	else
	{
		++tries;
	}
	return isCorrect();
}

void Hangman::drawHangman(const int tries)
{
	cout << background[0] << endl;
	cout << background[1] << endl;

	for (int i = 2; i < static_cast<int>(background.size()) - 2; ++i)
	{
		cout << background[i] << " ";

		// Draw hangman
		if (tries > 0)
		{
			// Draw top head
			if (i == 2)
			{
				if (tries < 3)
				{
					cout << hangman[tries - 1];
				}
				else
				{
					cout << hangman[i];
				}
			}

			// Draw bottom head
			if (i == 3)
			{
				if (tries < 4)
				{
					cout << hangman[i - 3];
				}
				else
				{
					cout << hangman[i];
				}
			}

			// Draw neck
			if ((tries > 4) && (i == 4))
			{
				cout << hangman[i];
			}

			// Draw body
			if ((tries > 5) && (i == 5))
			{
				// Right hand
				if (tries == 6)
				{
					cout << hangman[i];
				}

				// Right hand and torso
				else if (tries == 7)
				{
					cout << hangman[i + 1];
				}

				// Torso and both hands
				else
				{
					cout << hangman[i + 2];
				}
			}

			// Draw stomach
			if ((tries > 8) && (i == 6))
			{
				cout << hangman[i - 2];
			}

			// Draw thighs
			if ((tries > 9) && (i == 7))
			{
				// Left thigh
				if (tries == 10)
				{
					cout << hangman[i + 1];
				}

				// Both thighs
				else
				{
					cout << hangman[i + 2];
				}
			}

			// Draw legs
			if ((tries > 11) && (i == 8))
			{
				// Left leg
				if (tries == 12)
				{
					cout << hangman[i + 2];
				}

				// Both legs
				else
				{
					cout << hangman[i + 3];
				}
			}
		}
		cout << endl;
	}

	cout << background[static_cast<int>(background.size()) - 2] << endl;
	cout << background[static_cast<int>(background.size()) - 1] << "\n" << endl;
}

void Hangman::displayCorrectLetters()
{
	for (int i = 0; i < static_cast<int>(word.length()); ++i)
	{
		bool found = false;
		for (int j = 0; j < static_cast<int>(correctLetters.size()); ++j)
		{
			if (correctLetters[j].find(word[i]) < correctLetters[j].length())
			{
				int index = 0;
				// Get the index of the current character
				stringstream ss(correctLetters[j].substr(1));
				ss >> index;

				// Must be in the correct position
				if (index == i)
				{
					cout << word[i];
					found = true;
				}
			}
		}

		if (!found)
		{
			cout << " ";
		}
	}
	cout << endl;
}

void Hangman::printGuessLetters()
{
	cout << "Letters tried: ";
	for (const char l : alreadyGuess)
	{
		cout << l << " ";
	}
	cout << "\n" << endl;
}

const bool Hangman::isCorrect()
{
	if (correctLetters.size() == word.length())
	{
		correct = true;
	}
	return correct;
}

const bool Hangman::isGameOver()
{
	return (tries == maxTries);
}