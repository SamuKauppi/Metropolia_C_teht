#include <iostream>
#include <string>
using namespace std;

class Laskutoimitus
{
public:
	virtual double laske(double x, double y) = 0;
	virtual ~Laskutoimitus() {}
};

class YhteenLasku : public Laskutoimitus
{
public:
	double laske(double x, double y)
	{
		return x + y;
	}
};


class KertoLasku : public Laskutoimitus
{
public:
	double laske(double x, double y)
	{
		return x * y;
	}

};


int main()
{
	Laskutoimitus* lasku;
	lasku = new YhteenLasku();
	cout << lasku->laske(10, 10) << "\n";

	delete lasku;

	lasku = new KertoLasku();
	cout << lasku->laske(10, 10) << "\n";

	delete lasku;

	return 0;
}

