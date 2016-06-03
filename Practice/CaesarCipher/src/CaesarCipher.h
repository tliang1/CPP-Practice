#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

#include <string>

/// <summary>
/// Caesar cipher class for encryption and decryption of alphabetic text.
/// </summary>
class Caesar_Cipher {
public:
	Caesar_Cipher() {}
	
	std::string encrypt(const std::string text, const int shift);
	std::string decrypt(const std::string text, const int shift);
};

#endif
