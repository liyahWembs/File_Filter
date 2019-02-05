#pragma once
#ifndef ENCRYPTED_H
#define ENCRYPTED_H
#include"File Filter.h"

// sub class to encrypt the data
class Encryption : public Filter
{
public:
	char transform(char ch);
};
#endif // !ENCRYPTED_H