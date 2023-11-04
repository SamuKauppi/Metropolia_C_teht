#include <iostream>
#include <string>
using namespace std;

int main()
{
	char mjono[] = "Hellow";
	char* merkki;
	merkki = mjono;

	int pituus;
	pituus = 0;

	while (*merkki != 0)
	{
		cout << *merkki << endl;
		pituus++;
		merkki++;
	}

	cout << "This long: " << pituus;
	return 0;
}