#pragma once
#ifndef UPPERCASE_H
#define UPPERCASE_H
#include "File Filter.h"

// sub class upper that transforms all data to uppercase 
class Upper : public Filter
{
public:
	char transform(char ch);
};

#endif // !UPPERCASE_H

