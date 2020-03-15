#include <string>
#include "CipherInterface.h"
#include "Playfair.h"
#include <iostream>
#include <fstream>
#include "RowTransposition.h"
#include "Caesar.h"
#include "Railfence.h"
//add .h file for the other programs

using namespace std;

int main(int argc, char** argv)
{

	string cipherName = argv[1];
	string key_ = argv[2];
	string encdec = argv[3];
	string input = argv[4];
	string output = argv[5];
	ofstream outfile;
	string plaintext, ciphertext;
	fstream infile(argv[4], fstream::in);

	cout << "cipher: " << argv[1] << endl;
	cout << "key: " << argv[2] << endl;
	cout << "ENC/DEC: " << argv[3] << endl;
	cout << "input file: " << argv[4] << endl;
	cout << "output file: " << argv[5] << endl;

	getline(infile, plaintext, '\0');

	cout << "plaintext: " << plaintext << endl;

	infile.close();

	outfile.open(output);

	/* Create an instance of the Playfair cipher */
	CipherInterface* cipher = NULL;

	if (cipherName == "PLF")
		cipher = new Playfair();
	else if (cipherName == "RTS")
		cipher = new RowTransposition();
	else if (cipherName == "RFC")
		cipher = new Railfence();
	else if (cipherName == "VIG")
		cipher = new Vigenere();
	else if (cipherName == "CES")
		cipher = new Caesar();
	else
	{
		cout << "ERROR";
	}

	/* Error checks */
	if(!cipher)
	{
		fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",
		__FILE__, __FUNCTION__, __LINE__);
		exit(-1);
	}
	else {
		cipher->setKey(key_);

		if (encdec == "ENC") {
			ciphertext = cipher->encrypt(plaintext);
			cout << "ENCRYPT: " << endl << ciphertext << endl;
			outfile << ciphertext;
			outfile.close();
		}
		else if (encdec == "DEC") {
			string OGtext = cipher->decrypt(plaintext);
			cout << "DECRYPT: " << endl << OGtext << endl;
			outfile << OGtext;
			outfile.close();
		}
		else {
			cout << "ERROR" << endl;
		}
	}
	return 0;
}
