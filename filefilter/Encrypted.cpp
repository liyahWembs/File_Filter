#include"Encrypted.h"
#include <iostream>
using namespace std;

// sub class encrytpion virtual function transform definition 


char Encryption::transform(char ch)
{
	char key[3] = { 'K', 'Q','C' };
	char output = ch;
	return output = ch ^ key[1 % (sizeof(key) / sizeof (char))];
}