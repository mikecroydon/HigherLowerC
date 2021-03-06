// HigherLowerC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <sstream>

using namespace std;

//This function takes as an input the guesses vector, and the number of attempts and then asks the user if the most recent guess is high or low. It returns the response of the user
string userCheck(vector <int> g, int a)
{
	string r;
	cout << "Is your number higher, lower, or exactly " << g.back() << "? (h/l/e)" << endl;
	getline(cin, r);
	return r;
}

int main()
{
	cout << "Please think of a number between 1 and 100 and I'll guess what it is" << endl;
	cout << "Press enter when you've chosen your number";
	cin.ignore();
	vector <int> guesses, highs, lows;
	
	srand(time(NULL));
	guesses.push_back(rand() % 100 + 1);

	int attempts = 0; 
	string response;

	response = userCheck(guesses, attempts);

	++attempts;
	highs.push_back(100);
	lows.push_back(0);

	if (response == "h")
	{
		lows.push_back(guesses.back());		//Add the guess to the list of numbers that are lower than the user's number
		guesses.push_back(round((guesses.back() + highs.back()) / 2));
	}

	if (response == "l")
	{
		highs.push_back(guesses.back());		//Add the guess to the list of numbers that are lower than the user's number
		guesses.push_back(round((guesses[0]) / 2));
	}

	response = userCheck(guesses, attempts);

	while (response != "e")
	{
		if (response == "h")
		{
			lows.push_back(guesses.back());
		}
		if (response == "l")
		{
			highs.push_back(guesses.back());
		}
		int nextGuess = (highs.back() + lows.back()) / 2;
		
		//handles edge case where the number won't round to 100
		if ((highs.back() == 100) && (lows.back() == 99))
		{
			nextGuess = 100;
		}
		guesses.push_back(nextGuess);
		response = userCheck(guesses, attempts);
		attempts++;
	}
	attempts++;
	cout << "I have solved your number guessing puzzle in " << attempts << " attempts!";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
