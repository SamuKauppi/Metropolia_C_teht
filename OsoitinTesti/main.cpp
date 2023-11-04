#include <iostream>
using namespace std;

int main() 
{

	int x = 10;
	int* y;
	y = &x;

	cout << "x value: " << x << endl;
	cout << "x location: " << &x << endl;
	cout << "y value: " << *y << endl;
	cout << "y location: " << &y << endl;


	return 0;

}