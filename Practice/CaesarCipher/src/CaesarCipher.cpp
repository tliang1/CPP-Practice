#include "CaesarCipher.h"

std::string Caesar_Cipher::encrypt(const std::string text, const int shift)
{
	std::string encryptText = text;
	for (char &c : encryptText)
	{
		if (isalpha(c))
		{
			char newChar;
			if (isupper(c))
			{
				newChar = ((c - 'A' + shift) % 26);
				c = (newChar < 0 ? (newChar + 26) : newChar) + 'A';
			}
			else
			{
				newChar = ((c - 'a' + shift) % 26);
				c = (newChar < 0 ? (newChar + 26) : newChar) + 'a';
			}
		}
	}
	return encryptText;
}

std::string Caesar_Cipher::decrypt(std::string text, const int shift)
{
	return encrypt(text, -shift);
}