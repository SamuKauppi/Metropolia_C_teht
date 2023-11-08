#include <cstdlib>
#include <iostream>
using namespace std;

int* varaa_taulukko(int n)
{
	int* taulukko = new int[n];
	int* osoitin = taulukko;
	return osoitin;
}

void lue_arvot(int* t, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		cin >> t[i];
	}
}

void kaanna(int* t, int n)
{
	for (int i = 0, j = n - 1; i < n / 2; i++, j--)
	{
		int temp = t[i];
		t[i] = t[j];
		t[j] = temp;
	}
}

void tulosta_arvot(const int* t, int n)
{
	cout << endl;
	for (size_t i = 0; i < n; i++)
	{
		cout << t[i] << endl;
	}
}

int main()
{
	int n;
	cout << "Kuinka monta lukua jaksat kirjoittaa?" << endl;
	cin >> n;
	cout << endl;

	int* t = varaa_taulukko(n);
	lue_arvot(t, n);
	kaanna(t, n);
	tulosta_arvot(t, n);

	delete[] t;
	return 0;
}