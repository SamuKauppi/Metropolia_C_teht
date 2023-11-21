#include <iostream>
#include <algorithm>
#include <list>
#include <string>
#include <cstdlib>
using namespace std;

class Auto 
{
private:
	string _rekisteri;
	double _huippuNopeus;
	double _nopeus;
	double _matka;

public:
	Auto(const string& rekisteri, double huippuNopeus)
	{
		_rekisteri = rekisteri;
		_huippuNopeus = huippuNopeus;
		_nopeus = 0;
		_matka = 0;
	}
	void kiihduta(double nopeudenMuutos)
	{
		_nopeus += nopeudenMuutos;
		_nopeus = fmax(0, fmin(_nopeus, _huippuNopeus));
	}
	void kulje(double aika)
	{
		_matka += _nopeus * aika;
	}

	double palautaNopeus() const
	{
		return _nopeus;
	}

	string palautaRekisteri() const
	{
		return _rekisteri;
	}

	double palautaMatka() const
	{
		return _matka;
	}
};

string riviVaiht()
{
	return "\n";
}

void kokeilu()
{
	Auto formula = Auto("ABC-123", 142);
	cout << "rekisteri: " << formula.palautaRekisteri() << riviVaiht();
	formula.kiihduta(30);
	formula.kiihduta(70);
	formula.kiihduta(50);
	cout << formula.palautaNopeus() << riviVaiht();
	formula.kiihduta(-200);
	cout << formula.palautaNopeus() << riviVaiht();
}

int DetermineRandomValue(int offset, int range)
{
	int random = offset + (rand() % range + 1);
	return random;
}

int main()
{
	srand((unsigned)time(NULL));
	kokeilu();


	string nimi = "ABC-";
	list<Auto> kilpailijat;

	for (int i = 0; i < 10; i++)
	{
		double satunnainenNopeus = DetermineRandomValue(100, 200);
		Auto tempAuto = Auto(nimi + to_string(i + 1), satunnainenNopeus);
		kilpailijat.push_back(tempAuto);
	}

	Auto* voittaja = nullptr;
	while (!voittaja)
	{
		for (Auto& i : kilpailijat)
		{
			double satunnainenNopeus = DetermineRandomValue(-10, 15);
			i.kiihduta(satunnainenNopeus);
			i.kulje(1);

			if (i.palautaMatka() >= 1000)
			{
				voittaja = &i;
				break;
			}
		}
	}

	cout << "Voittaja loytyi!" << riviVaiht();
	for (auto& i : kilpailijat)
	{
		cout << "Kilpailija " << i.palautaRekisteri() << " kulki " << i.palautaMatka() << riviVaiht();
	}
	cout << riviVaiht() << "Voittaja on: " << voittaja->palautaRekisteri() << riviVaiht();

	return 0;
}