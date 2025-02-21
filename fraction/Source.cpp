// Shrey Deogade
// Period 4
// 2-18-25
// Fraction Source File

#include "Fraction.h"
#include <iostream>
using namespace std;

int main()
{
  cout << "Testing: additon & subtraction: " << endl;
  Fraction f1;
  f1.readFraction();
  cout << endl;

  Fraction f2;
  f2.readFraction();

  cout << "Sum: ";
  f1.add(f2).printFraction();

  cout << "Difference: ";
  f1.subtract(f2).simplified().printFraction();

  cout << "\nTesting: multiplication & division: " << endl;
  Fraction f3;
  f3.readFraction();
  cout << endl;

  Fraction f4;
  f4.readFraction();

  cout << "Product: ";
  f3.multiply(f4).simplified().printFraction();

  cout << "Quotient: ";
  f3.divide(f4).simplified().printFraction();

  cout << "\nTesting: comparison: " << endl;
  Fraction f5;
  f5.readFraction();
  cout << endl;

  Fraction f6;
  f6.readFraction();

  cout << "Equal?: ";
  if (f5.isEqual(f6))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  cout << "First greater than second?: ";
  if (f5.isGreater(f6))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  cout << "First less than second?: ";
  if (f5.isLess(f6))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  cout << "Testing simplification: " << endl;
  Fraction f7;
  f7.readFraction();
  cout << "Simplified: ";
  f7.simplified().printFraction();

  return 0;
}
