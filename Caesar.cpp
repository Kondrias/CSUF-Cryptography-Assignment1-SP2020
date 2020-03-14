#include "Caesar.h"
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

bool Caesar::setKey(const string& key)
{
  //stringstream val(key);     would convert the string to an
  //int x = 0;                 int value for the encryption
  //val >> x;
	_key = key;
	return false;
}

/**
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted ciphertext string
 */
string Caesar::encrypt(const string& plaintext)
{
	string encryptText = "";
  string ptext=plaintext;
  int ptextLength = plaintext.length();
  stringstream val(_key); //converts the key into an
  int keyint = 0;         //int to make encryption
	val >> keyint;          //easier

  for (int i = 0; i<ptextLength; i++)
  {
    if(isupper(ptext[i])){
      encryptText += char(int(ptext[i]+keyint-65)%26+65);
    }
    else{
      encryptText += char(int(ptext[i]+keyint-97)%26+97);
    }
  }
	return encryptText;
}

/**
 * This function is almost identical to the encryption
 * algorithm because of the cyclic nature of caesar ciphers
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string Caesar::decrypt(const string& cipherText)
{
  string decryptText = "";
  string ctext=cipherText;
  int ctextLength = cipherText.length();
  stringstream val(_key); //converts the key into an
  int keyint = 0;         //int to make decryption
	val >> keyint;          //easier

  for (int i = 0; i<ctextLength; i++)
  {
    if(isupper(ctext[i])){
      decryptText += char(int(ctext[i]+keyint-65)%26+65);
    }
    else{
      decryptText += char(int(ctext[i]+keyint-97)%26+97);
    }
  }
	return decryptText;
}
