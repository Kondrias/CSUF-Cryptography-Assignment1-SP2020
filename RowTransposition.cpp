#include "RowTransposition.h"

#include <string>
#include <iostream>
#include <vector>

bool RowTransposition::setKey(const string& key) {
	_key = key;
	return false;
}

string RowTransposition::encrypt(const string& plaintext) {
	string encryptText = "";
	string ptext = plaintext;
	int ptextLength = plaintext.length();
	int keyLength = _key.length();
	int numOfRows = ptextLength / keyLength;
	int position = 0;
	int Mod = ptextLength % keyLength;

	if (Mod != 0) {
		int extra = keyLength - Mod;
		for (int i = 0; i < extra; i++) {
			ptext += int(i) + 'a';
		}
		ptextLength = ptext.length();
		numOfRows = ptextLength / keyLength;
	}

	vector<string> ptextMatrix(numOfRows);
	for (int i = 0; i < numOfRows; i++) {
		for (int j = 0; j < keyLength; j++) {
			ptextMatrix[i].push_back(ptext[position + j]);
		}
		position += keyLength;
	}

	int column;
	for (int i = 0; i < keyLength; i++) {
		column = int(_key[i]) - '0';
		for (int j = 0; j < numOfRows; j++) {
			encryptText += ptextMatrix[j][column - 1];
		}
	}

	return encryptText;

}

string RowTransposition::decrypt(const string& ciphertext) {
	string decryptText = "";
	int ctextLength = ciphertext.length();
	int keyLength = _key.length();
	int numOfRows = ctextLength / keyLength;
	int currentColumn = (int(_key[0]) - '0') - 1;
	int columnIndex = 0;
	int column = 0;
	int count = 0;
	int y = 0;
	int x = 0;

	while (x < numOfRows) {
		while (y < keyLength) {
			columnIndex = 0;
			while (currentColumn != column) {
				columnIndex++;
				currentColumn = (int(_key[columnIndex]) - '0') - 1;
			}

			count = columnIndex * numOfRows;
			decryptText += ciphertext[count + x];
			column++;
			currentColumn = (int(_key[0]) - '0') - 1;
			if (column == keyLength) {
				y++;
				column = 0;
				break;
			}
		}
		x++;
	}

	return decryptText;

}