// main.cpp : A word unscrambler that reads scramble words from a txt file and unscramble them from reading and using a word list txt file.

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

// Overload () operator to compare the two strings' sizes
struct Compare 
{
	bool operator()(const string& firstWord, const string& secondWord) 
	{
		return firstWord.size() < secondWord.size();
	}
};

// Sort a string to be in ascending order
void sortstring(string &s) 
{
	sort(s.begin(), s.end());
}

void main() {

	vector<string> scrambleWords, wordList, wordListBackup;

	// Read and store each word into the scrambleWords vector of strings
	ifstream scrambleWordsFile("scrambled.txt");
	for (string line; scrambleWordsFile.good() && getline(scrambleWordsFile, line); scrambleWords.push_back(line));
	scrambleWordsFile.close();

	// Read and store each word into the wordList vector of strings
	ifstream wordsListFile("wordlist.txt");
	for (string line; wordsListFile.good() && getline(wordsListFile, line); wordList.push_back(line))
	{
		wordListBackup.push_back(line);
	}
	wordsListFile.close();

	// Change each word to have its letters be sorted in ascending order
	for (string &word : scrambleWords)
	{
		sortstring(word);
	}

	// Change each word to have its letters be sorted in ascending order
	for (string &word : wordList)
	{
		sortstring(word);
	}

	// Find where each scrambled word is located in the word list
	for (string &word : scrambleWords)
	{
		word = wordListBackup.at(find(wordList.begin(), wordList.end(), word) - wordList.begin());
	}
	
	// Sort words by length
	Compare c;
	sort(scrambleWords.begin(), scrambleWords.end(), c);

	for (const string word : scrambleWords)
	{
		cout << word << endl;
	}
}