#include <iostream>
using namespace std;

class Solmu
{
public:
	int		_data;
	Solmu*	_next;
};

// Tulostaa solmujen arvot
void tulosta_lista(const Solmu* s)
{
	while (s)
	{
		cout << s->_data << "\n";
		s = s->_next;
	}
}

// Lue uuden solmun, jonka next arvo on alku
Solmu* lisaa_alkuun(Solmu* alku, int arvo)
{
	Solmu* uusi = new Solmu;
	uusi->_data = arvo;
	uusi->_next = alku;
	return uusi;
}

// Poistaa linkitetyn listan arvot yksitelllen
void tuhoa_lista(Solmu* s)
{
	while (s)
	{
		Solmu* seuraava = s->_next;
		delete s;
		s = seuraava;
	}
}

int main()
{

	Solmu* s1 = new Solmu;
	Solmu* s2 = new Solmu;
	Solmu* s3 = new Solmu;
	Solmu* s4 = new Solmu;

	s1->_data = 3;
	s1->_next = s2;

	s2->_data = 10;
	s2->_next = s3;

	s3->_data = 2;
	s3->_next = s4;

	s4->_data = 1;
	s4->_next = nullptr;

	Solmu* head = s1;
	
	tulosta_lista(head);
	cout << "\n";

	head = lisaa_alkuun(head, 1052);
	head = lisaa_alkuun(head, 582);
	tulosta_lista(head);

	tuhoa_lista(head);

	return 0;
}
