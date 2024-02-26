
#include <iostream>

using namespace std;
class Solmu
{
public:
	Solmu(int data, Solmu* vasen = nullptr, Solmu* oikea = nullptr) :
		_data(data), _vasen(vasen), _oikea(oikea)
	{}

	int _data;
	Solmu* _vasen;
	Solmu* _oikea;

};

void traverse(Solmu* s)
{
	// Rekursion kantatapaus

	if (s == nullptr)
		return;

	// Tulostus
	cout << s->_data << "\n";

	// Rekursiokutsu
	traverse(s->_vasen);
	traverse(s->_oikea);
}

int count(Solmu* s)
{
	if (s == nullptr)
		return 0;
	
	return 1 + count(s->_vasen) + count(s->_oikea);
}

bool search(Solmu* s, int value)
{
	if (s == nullptr)
		return false;

	if (s->_data == value)
		return true;

	if (value < s->_data)
	{
		search(s->_vasen, value);
	}
	else
	{
		search(s->_oikea, value);
	}
}

int main()
{
	// Hardkoodattu puu
	//Solmu s5(5);
	//Solmu s11(11);
	//Solmu s6(6, &s5, &s11);
	//Solmu s2(2);
	//Solmu s7(7, &s2, &s6);
	//Solmu s5b(5);
	//Solmu s9(9, &s5);
	//Solmu s9b(9, nullptr, &s9);
	//Solmu s1(1, &s7, &s9b);

	//traverse(&s1);
	//cout << count(&s1);


	// Binäärihakupuu
	Solmu s2(2);
	Solmu s3(3, &s2);
	Solmu s7(7);
	Solmu s9(9);
	Solmu s8(8, &s7, &s9);
	Solmu s5(5, &s3, &s8);

	cout << search(&s5, 7) << "\n";
	cout << search(&s5, 8) << "\n";
	cout << search(&s5, 1) << "\n";

	return 0;
}