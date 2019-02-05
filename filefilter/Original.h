#ifndef ORIGINAL_H
#define ORIGINAL_H
#pragma once
#include"File Filter.h"

// sub class original that copies the original data  
class Original : public Filter
{
public:
	char transform(char ch);
};

#endif // !ORIGINAL_H