#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <io.h>
#include <stdlib.h>

using namespace std;

void WritePrime();
bool _exit;
ofstream myfile;
int printedNumbers;

void main()
{
	int i;
	i = 2;
	_exit = true;
	printedNumbers = 1;
	remove("PrimeNumbers.txt");
	myfile.open("PrimeNumbers.txt");
	while (true) {
		if (_exit) { while (_exit) WritePrime(); }
	
		printf("Writing prime numbers...\n");
	
		cout << "Stopped script because the S key was pressed." << endl;
		cout << "Printed ~" << (printedNumbers - 4) << " numbers" << endl;
		cout << "Press e to exit or Q to resume." << endl;
		while (true)
		{
			if (GetKeyState('E') & 0x80)
			{
					myfile.close()
					exit(0);														//exit with code 0 if E key is pressed.
			}
			else if (GetKeyState('Q') & 0x80)
			{
						Sleep(500);
						_exit = true;
			}
	
		}
	}

}

void WritePrime() {
	if (GetKeyState('G') & 0x80)
	{
		system("cls");
		cout << "You pressed g: Printed " << printedNumbers << " prime numbers" << endl;
	}
	i++;
	bool isPrime = true; // because i like doing things the wrong way
	for (long j = 3; j < i; j += 2) // only check if prime for odd numbers
	{
		if (i % j == 0) 
		{
			isPrime = false;
			break;
		} else {
			printedNumbers++;
			myfile << i << endl; //write i to myfile if it's prime
		}
	}

	if (GetKeyState('S') & 0x80) _exit = false; //break loop if s key is pressed.
}
