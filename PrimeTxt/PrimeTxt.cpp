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
		bool isPrime = true; // Move initialization to here
		for (long j = 3; j < i; j += 2) // you actually only need to check up to sqrt(i)
		{
			if (i % j == 0) // you don't need the first condition
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime)
		{
			printedNumbers++;
			myfile << i << endl;
		}

		if (GetKeyState('S') & 0x80)
		{
			break;
		}
	}
	printf("Stopped script because the S key was pressed.\n");
	cout << "Printed ~" << (printedNumbers - 4) << " numbers" << endl;
	cout << "Press e to exit." << endl;
	while (true)
	{
		if (GetKeyState('E') & 0x80)
		{
			exit(0);														//TODO fix repeat issue
		}

	}
	
	
	myfile.close();

}