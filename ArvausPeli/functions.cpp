#include <iostream>
#include <cstdlib>
using namespace std;

int DetermineRandomValue(int offset, int range)
{
	srand((unsigned)time(NULL));
	int random = offset + (rand() % range);
	return random;
}

int GetAndValidateInput(int offset, int range)
{
	int arvaus = 0;
	cout << "Anna luku: ";
	cin >> arvaus;
	while (!cin.good() || arvaus < offset || arvaus > range)
	{
		cout << "Vaara luku. Anna uusi luku: ";
		cin >> arvaus;
	}

	return arvaus;
}

bool CheckGuess(int guess, int random, int guessCount)
{
	if (guess < random)
	{
		cout << "Liian pieni!" << endl;
		return false;
	}
	else if (guess > random)
	{
		cout << "Liian suuri!" << endl;
		return false;
	}

	cout << "Oikein! Teit " << guessCount << " arvausta." << endl;
	return true;
}