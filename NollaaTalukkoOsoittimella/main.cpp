#include <iostream>
using namespace std;

void nollaa(int *t, int lkm)
{
	for (int i = 0; i < lkm; i++)
	{
		cout << "Old value: " << t[i] << endl;
		t[i] = 0;
		cout << "New value: " << t[i] << endl;
		cout << endl;
	}
}

int main()
{
	int taulukko[] = { 3, 5, 8, 4, -2 };
	int lkm = 5;
	nollaa(taulukko, lkm);
	return 0;
}