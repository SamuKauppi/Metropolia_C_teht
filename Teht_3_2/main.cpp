#include <cstdlib>
#include <iostream>
using namespace std;

int n;
int* t;

int* varaa_taulukko()
{
	int* taulukko = new int[n];
	return taulukko;
}

void lue_arvot()
{
	for (size_t i = 0; i < n; i++)
	{
		cin >> t[i];
	}
}

void kaanna()
{
	for (int i = 0, j = n - 1; i < n / 2; i++, j--)
	{
		int temp = t[i];
		t[i] = t[j];
		t[j] = temp;
	}
}

void tulosta_arvot()
{
	cout << endl;
	for (size_t i = 0; i < n; i++)
	{
		cout << t[i] << endl;
	}
}

int main()
{
	cout << "Kuinka monta lukua jaksat kirjoittaa?" << endl;
	cin >> n;
	cout << endl;

	t = varaa_taulukko();
	lue_arvot();
	kaanna();
	tulosta_arvot();

	delete[] t;
	return 0;
}