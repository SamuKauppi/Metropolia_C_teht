#include <iostream>
using namespace std;

class Ihminen
{
public:

	int _syntvuosi;
	int _pituus;
	// Voi aiheuttaa muistivuodon
	// char* muistot;

	Ihminen(int svuosi, int pituus)
	{
		_syntvuosi = svuosi;
		_pituus = pituus;
	}
	Ihminen(const Ihminen& alkuper) = delete;

	void operator=(const Ihminen& rhs) = delete;

	~Ihminen()
	{
		cout << "cya" << "\n";
	}
};

void foo(Ihminen& i)
{
	cout << i._syntvuosi << "\n";
	cout << i._pituus << "\n";
}

int main()
{
	Ihminen pena(1999, 160);
	foo(pena);

	return 0;
}