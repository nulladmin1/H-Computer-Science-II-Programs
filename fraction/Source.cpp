// Shrey Deogade
// Period 4
// 2-18-25
// Fraction Source File

#include "Fraction.h"
#include <iostream>
using namespace std;

int main() {
  // Test the denominator being 0
  try {
    Fraction f1(1, 0);
  } catch (invalid_argument &e) {
    cout << "DivByZero - pass!: " << e.what() << endl;
  }

  return 0;
}
