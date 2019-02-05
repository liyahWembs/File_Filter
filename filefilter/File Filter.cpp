#include<iostream>
#include"File Filter.h"
using namespace std;


// the member function that calls the virtual function 
void Filter::doFilter(ifstream &in, ofstream &out)
{
	char ch;
	char transCh;
	
	in.get(ch);
	while (!in.fail())
	{
		// set transCh to the returned value of the virtual function 
		transCh = transform(ch);

		// writes the data to the created file as it is transformed 
		out.put(transCh);

		// gets the next character  
		in.get(ch);
	}
}
