#include <iostream>
#include "functions.h"

using namespace std;

int main()
{
	double kanta, korkeus;

	cout << "Anna kolmion kanta ja kokeus\n";
	cin >> kanta;
	cin >> korkeus;

	double tulos;
	tulos = laske_kolmio_ala(kanta, korkeus);
	cout << "Kolmion ala on " << tulos << endl;

	return 0;
}