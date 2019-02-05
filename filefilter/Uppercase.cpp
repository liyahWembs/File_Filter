#include<iostream>
#include"Uppercase.h"

// sub class uppers virtual functions transform definition 

char Upper::transform(char ch)
{
	return toupper(ch);
}