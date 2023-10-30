#include <iostream>
#include "functions.h";
using namespace std;

int main()
{
	cout << "Numeropeli! Maarita numeroiden rajat" << endl;

	int offset = 0;
	cout << "Anna ala-raja: ";
	cin >> offset;

	int range = 0;
	cout << "Anna yla-raja: ";
	cin >> range;

	int random = DetermineRandomValue(offset, range);
	int guessCount = 0;

	while (true)
	{
		guessCount++;
		int guess = GetAndValidateInput(offset, range);

		if (CheckGuess(guess, random, guessCount))
			break;
	}

	return 0;
}