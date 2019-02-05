#ifndef FILE_FILTER_H
#define FILE_FILTER_H
#pragma once
#include<fstream>
#include<iostream>
using namespace std;


// main class 
class Filter
{
public:
	//virtual function
	virtual char transform(char ch) = 0;
	void doFilter(ifstream &in, ofstream &out);
};

#endif // !FILE_FILTER_H







