class Juttu {
public:
	int arvo;
};

class Luokka {
public:

	Luokka()
	{
		_jutska = new Juttu();
		_jutska->arvo = 10;
	}

	Luokka(const Luokka& original)
	{
		_jutska = 0;
		kopioi(original);
	}

	Luokka& operator= (const Luokka& original)
	{
		kopioi(original);
		return *this;
	}

	~Luokka()
	{
		delete _jutska;
	}

private:
	Juttu* _jutska;

	void kopioi(const Luokka& original)
	{
		if (_jutska) delete _jutska;

		_jutska = new Juttu();

		_jutska->arvo = original._jutska->arvo;
	}
};

void kokeilu1()
{
	Luokka eka;
	Luokka toka(eka);
}

void kokeilu2()
{
	Luokka eka;
	Luokka toka;
	toka = eka;
}

int main()
{
	kokeilu1();
	kokeilu2();

	return 0;
}