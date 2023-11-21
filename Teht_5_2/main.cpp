#include <string>
#include <iostream>
#include <stdlib.h>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
using namespace std;

class Viisari
{
private:
	Viisari* _next;
	int _arvo;
	int _max;
public:
	Viisari(int arvo, int max, Viisari* next = nullptr)
	{
		_arvo = arvo;
		_max = max;
		_next = next;
	}
	void nayta()
	{
		string sArvo;
		if (_arvo < 10)
			sArvo += to_string(0);
		sArvo += to_string(_arvo);
		cout << sArvo;
	}

	void kay()
	{
		_arvo = (_arvo + 1) % _max;
		if (_arvo == 0 && _next)
			_next->kay();
	}
};

class Kello
{
private:
	Viisari* tunnit;
	Viisari* minuutit;
	Viisari* sekunnit;

public:
	// luodaan ja alustetaan viisarit
	Kello(int h, int m, int s)
	{
		tunnit = new Viisari(h, 24);
		minuutit = new Viisari(m, 60, tunnit);
		sekunnit = new Viisari(s, 60, minuutit);
	}
	~Kello()
	{
		delete tunnit;
		delete minuutit;
		delete sekunnit;
	}
	void nayta()
	{
		system("cls");
		tunnit->nayta();
		cout << ":";
		minuutit->nayta();
		cout << ":";
		sekunnit->nayta();
	}
	void kay()
	{
		sekunnit->kay();
	}
};

int main()
{
	Kello rolex = Kello(21, 59, 55);

	while (1)
	{
		rolex.kay();
		rolex.nayta();
		std::this_thread::sleep_for(1000ms);
	}
}