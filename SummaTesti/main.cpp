#include <iostream>
using namespace std;

int summaa(int luku1, int luku2)
{
	int summa = luku1 + luku2;
	return summa;
}

void summaaOsoitin(int& luku1, int& luku2, int& summa)
{
	summa = luku1 + luku2;
}

int main()
{
	int x = 1;
	int y = 2;
	int summa = summaa(x, y);
	cout << summa << endl;

	x = 5;
	y = 56457;
	summaaOsoitin(x, y, summa);
	cout << summa << endl;

	return 0;
}

