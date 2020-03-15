#include "Playfair.h"

#include <string>
#include <iostream>
#include <vector>

/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */
bool Playfair::setKey(const string& key) // also creates the matrix used
{
	_key = key;
	string Keymatrix[5][5];
	string alphabet = "abcdefghiklmnopqrstuvwxyz";
	for (int i=0; i< _key.length(); i++){
		for(int j=0; i< alphabet.length(); j++){
			if(_key[i] == "j"){
				_key[i] == "i";
			}
			if(_key[i] == alphabet[j]){
				alphabet.erase(j,1);
			}
		}
	}
	_key.append(alphabet)
	return true;
}




/**
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted ciphertext string
 */
string Playfair::encrypt(const string& plaintext)
{
	string encryptText = "";


	return encryptText;
}

/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string Playfair::decrypt(const string& cipherText)
{
	return "";

}
