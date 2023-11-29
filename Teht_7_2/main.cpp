#include <iostream>
using namespace std;

class Hevonen
{
private:
	int _kavio = 0;

public:
	void setKavio(int kavio)
	{
		_kavio = kavio;
	}

	int getKavio()
	{
		return _kavio;
	}

	bool operator<(const Hevonen& h) const
	{
		return _kavio < h._kavio;
	}
};

template <typename T>
void jarjesta(T* t, int koko)
{
	for (int i = 0; i < koko - 1; i++)
	{
		for (int j = i + 1; j < koko; j++)
		{
			if (t[j] < t[i])
			{
				T temp = t[i];
				t[i] = t[j];
				t[j] = temp;
			}
		}
	}
}
void Teht1()
{
	int arr[] = { 5, 3, 4, 5, 75, -1, -100 };
	int* t = arr;
	for (auto i : arr)
	{
		cout << i << "\n";
	}
	cout << "\n";
	jarjesta(t, 7);
	for (auto i : arr)
	{
		cout << i << "\n";
	}

	cout << "\n";

	float arr2[] = { 5, 3, 4, 5, 75, -1, -100 };
	float* t2 = arr2;
	for (auto i : arr)
	{
		cout << i << "\n";
	}
	cout << "\n";
	jarjesta(t, 7);
	for (auto i : arr)
	{
		cout << i << "\n";
	}
}
void Teht2()
{
	Hevonen hevoset[5];
	int swap = 1;
	for (int i = 0; i < 5; i++)
	{
		hevoset[i].setKavio((i + 1) * swap * 10);
		swap *= -1;
	}
	Hevonen* h = hevoset;
	for (auto i : hevoset)
	{
		cout << i.getKavio() << "\n";
	}
	cout << "\n";
	jarjesta(h, 5);
	for (auto i : hevoset)
	{
		cout << i.getKavio() << "\n";
	}
	
}

int main()
{
	Teht1();
	Teht2();
	return 0;
}