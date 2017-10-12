// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include  <windows.h>
#include <io.h>

using namespace std;

void main()
{
	ofstream myfile;
	remove("PrimeNumbers.txt");
	myfile.open("PrimeNumbers.txt");
	int i = 2;
	int printedNumbers = 1;
	printf("Writing prime numbers...\n");
	while (true)
	{
		if (GetKeyState('G') & 0x80)
		{
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
			}
		}
		if (isPrime)
		{
			printedNumbers++;
			myfile << i << endl; //write i to myfile if it's prime
		}

		if (GetKeyState('S') & 0x80)
		{
			break; //break loop if s key is pressed.
		}
	}
	printf("Stopped script because the S key was pressed.\n");
	cout << "Printed ~" << (printedNumbers - 4) << " numbers" << endl;
	cout << "Press e to exit." << endl;
	while (true)
	{
		if (GetKeyState('E') & 0x80)
		{
			exit(0);														//exit with code 0 if E key is pressed.
		}

	}
	
	
	myfile.close();

}