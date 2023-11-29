#include <string>
#include <iostream>
using namespace std;

template <class T, int Size>
class Stack
{
public:

	void push(T value)
	{
		if (_index >= _maxCount)
		{
			return;
		}

		_values[_index] = value;
		_index++;
	}

	T pop()
	{ 
		if (_index > 0)
		{
			_index--;
		}
		T value = _values[_index];
		return value;
	}

	int size()
	{
		return _maxCount;
	}

private:
	int _maxCount = Size;
	int _index = 0;
	T _values[Size];
};


int main()
{
	Stack<int, 3> myInts;

	myInts.push(10);
	myInts.push(12);
	myInts.push(14);
	myInts.push(16);

	for (int i = 0; i < 3; i++)
	{
		cout << myInts.pop() << "\n";
	}

	Stack<string, 3> myStrings;

	myStrings.push("a");
	myStrings.push("b");
	myStrings.push("c");
	myStrings.push("d");

	for (int i = 0; i < 3; i++)
	{
		cout << myStrings.pop() << "\n";
	}

	return 0;
}