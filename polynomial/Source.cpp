// Polynomial Class Source File
// 3-3-25
// Period 4
// Shrey Deogade & Dylan Staykov

#include "Polynomial.h"
#include <iostream>
using namespace std;

int main() {
  Polynomial p1;
  cin >> p1;
  cout << p1 << endl;

  Polynomial p2;
  cin >> p2;
  cout << p2 << endl;

  Polynomial sum = p1 + p2;
  cout << "Sum: " << sum << endl;

  Polynomial difference = p1 - p2;
  cout << "Difference: " << difference << endl;

  Polynomial product = p1 * p2;
  cout << "Product: " << product << endl;

  Polynomial quotient = p1 / p2;
  cout << "Quotient: " << quotient << endl;

  Polynomial remainder = p1 % p2;
  cout << "Remainder: " << remainder << endl;

  return 0;
}
