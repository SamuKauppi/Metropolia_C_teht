#include <iostream>
using namespace std;

int main()
{
	cout << "Pelataan Kiinalaista Numeropelia!\n";
	while (true)
	{
		int numero = 0;
		cout << "Anna luku: ";
		cin >> numero;

		if (numero == 0)
			break;

		if (numero == INT_MAX) 
		{
			cout << "Well played, bucko... Tasapeli\n";
		}
		else
		{
			numero++;
			cout << "Voitin, minun luku on " << numero << "!" << endl;
		}
	}
	return 0;
}

