#include "Encrypted.h"; 
#include "Original.h";
#include "Uppercase.h"; 
#include "Group Header.h"
//#include <iostream> 
//#include <string> 
using namespace std;

//function prototypes
double getDouble();
double getNumber();
double getWholeNumber();
double getRangeNumber(int, int);

// function to get number in range
double getRangeNumber(int MIN, int MAX) {
	double num = getWholeNumber();
	while (num < MIN || num > MAX) {
		cout << "\tPlease enter a number from " << MIN << " to " << MAX << " : ";
		cin >> num;
	}
	return num;
}

// function to get whole number and check them
double getWholeNumber() {
	double num;
	num = getDouble();
	while (num != (int)num) {
		cout << "\tWhole number only. Try again: ";
		cin >> num;
	}
	return num;
}

// function to get number 
double getNumber() {
	double number;
	while (!(cin >> number)) {
		cin.clear(); cin.ignore(10000, '\n');
		cout << "\tNo letter please. Try again: ";
	}
	cin.ignore(80, '\n');
	return number;
}
double getDouble() {
	double number;
	number = getNumber();
	return number;
}

// main function
int main()
{
	// variables declarations
	ifstream input;
	ofstream output;
	string fileName, transformFileName, line;
	Original copyFile;
	Encryption encryptFile;
	Upper uppercaseFile;
	int choice;
	const int MIN = 1, MAX = 3;
	char answer = 'y';

	// print header function
	printHeader();

	// loop to ask the user if the want to reply 
	while (true) {
		
		// ask for file name 
		cout << "Please enter the name of the file, remember to include .txt at the end: ";
		cin >> fileName; // input filename

		//open inout file 
		input.open(fileName);
		while (!input)
		{
			// Display an error message. 
			cout << "Error opening the input file.\n";
			cout << "Please enter the name of the file, remember to include .txt at the end: ";
			cin >> fileName;
			input.open(fileName);
		}

		cout
			// allow the user to choose what operation to perform

			<< "\nPlease choose the option that you want to peform on the file: \n"
			<< "\t 1. Encrypt\n"
			<< "\t 2. Capitalize\n"
			<< "\t 3. Copy\n"
			<< "Choice: ";
		choice = getRangeNumber(MIN, MAX);
		// assume that has input validation that from 1~3 and no letter allow 

		// switch for the user choice 
		switch (choice)
		{
			do {
				// first case to encrypt the file
		case 1:
			cout << "Enter the output file name, remember .txt at the end: ";
			cin >> transformFileName;
			output.open(transformFileName);
			encryptFile.doFilter(input, output);
			input.close();
			output.close();
			break;
			// second case to upper the file
		case 2:
			cout << "Enter the output file name, remember .txt at the end: ";
			cin >> transformFileName;
			output.open(transformFileName);
			uppercaseFile.doFilter(input, output);
			input.close();
			output.close();
			break;
			// third case to copy the file
		case 3:
			cout << "Enter the output file name, remember .txt at the end: ";
			cin >> transformFileName;
			output.open(transformFileName);
			copyFile.doFilter(input, output);
			input.close();
			output.close();
			break;



			// display the name of the file created 

			cout << "\n\n\tA file named " << transformFileName << " has been created in your folder.....\n";

			cout << "\tHere is how the file look like: \n\n";
			input.open(transformFileName);
			if (input.is_open())
			{
				while (getline(input, line))
				{
					cout << line << '\n';
				}
				input.close();
			}
			else
				cout << "Open Error. Did you add the .txt?\n";

			cout << "Do you want to try again?(Y/N) ";
			cin >> answer;

			if (toupper(answer) == 'N') {
				cout << "Thank you for trying. \n"
					<< "Terminating the program.....\n";
				system("pause");
				break;
			}
			} while (answer != 'n' || answer != 'N');



		}
		system("pause");
	return 0;
  }
}
