// Polynomial Class Source File
// 3-3-25
// Period 4
// Shrey Deogade & Dylan Staykov

#include <iostream>
#include "Polynomial.h"
using namespace std;

int main() 
{
	int a[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	Polynomial p1;
	cout << p1 << endl;

	Polynomial p2 = p1;
	Polynomial p3 = p1 * p2;

	cout << p3 << endl;

	Polynomial sum = p1 + p2;
	cout << "Sum: " << sum << endl;

	Polynomial difference = p1 - p2;
	cout << "Difference: " << difference << endl;
	return 0;
}	
