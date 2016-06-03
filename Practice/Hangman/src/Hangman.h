#ifndef HANGMAN_H
#define HANGMAN_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/// <summary>
/// Hangman game class.
/// </summary>
class Hangman 
{
private:
	bool correct = false;
	int tries = 0;
	vector<string> words;
	string word;
	const vector<string> background{ "_____", "|   |", "|", "|", "|", "|", "|", "|", "|", "|", "|_____" };
	const vector<string> hangman{ "[   ]", "[x  ]", "[x x]", "[ ^ ]", "  |", "/", "/ |", "/ | \\", " /", " / \\", "/", "/   \\" };
	vector<string> correctLetters; // vector of every character concatenated with the position of the characters that the user guess correctly
	vector<char> alreadyGuess; // vector of every character that the user already tried
	
	const string toLowerCase(const string &text);
public:
	Hangman();

	static const int maxTries = 13;
	
	const string getWord();
	const int getTriesLeft();
	
	bool alreadyTried(const char l);

	bool checkGuess(const char c);
	bool checkGuess(const string &userWord);

	void drawHangman(const int tries = 0);
	void displayCorrectLetters();
	void printGuessLetters();

	void updateHangman(const char c);

	const bool isCorrect();
	const bool isGameOver();
};

#endif