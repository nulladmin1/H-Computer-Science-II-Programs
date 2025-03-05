// Polynomial Class Source File
// 3-3-25
// Period 4
// Shrey Deogade & Dylan Staykov

#include "Polynomial.h"
#include <iostream>
using namespace std;

int main() {
  Polynomial p1;
  cout << p1 << endl;

  Polynomial p2 = p1;

  Polynomial p3 = p1 * p2;

  cout << p3 << endl;
  cout << "²" << endl;

  return 0;
}
