// Shrey Deogade
// Period 4
// 2-18-25
// Fraction Implementation Details

#include "Fraction.h"
#include <iostream>
using namespace std;

Fraction::Fraction(int n, int d) {
  setNumerator(n);
  setDenominator(d);
}

Fraction::Fraction() {
  setNumerator(1);
  setDenominator(1);
}

void Fraction::setNumerator(int numerator) { this->numerator = numerator; }

void Fraction::setDenominator(int denominator) {
  this->denominator = denominator;
}

int Fraction::getNumerator() { return numerator; }

int Fraction::getDenominator() { return denominator; }

Fraction Fraction::add(Fraction other) {
  int commonDenominator = this->denominator * other.denominator;

  int addedNumerator =
      this->numerator * other.denominator + other.numerator * this->denominator;

  return Fraction(addedNumerator, commonDenominator);
}

Fraction Fraction::subtract(Fraction other) {
  int commonDenominator = this->denominator * other.denominator;

  int subtractedDenominator =
      this->numerator * other.denominator + other.numerator * this->denominator;

  return Fraction(subtractedDenominator, commonDenominator);
}

Fraction Fraction::multiply(Fraction other) {
  return Fraction(numerator * other.numerator, denominator * other.denominator);
}

Fraction Fraction::divide(Fraction other) {
  return multiply(Fraction(other.denominator, other.numerator));
}

void Fraction::simplify() {
  Fraction simplifiedFraction = simplified();

  numerator = simplifiedFraction.numerator;
  denominator = simplifiedFraction.denominator;
}

Fraction Fraction::simplified() {
  // GCD
  int tempNumerator = abs(numerator);
  int tempDenominator = abs(denominator);

  while (tempDenominator != 0) {
    int tmp = tempDenominator;
    tempDenominator = tempNumerator % tempDenominator;
    tempNumerator = tmp;
  }

  tempNumerator = numerator / tempNumerator;

  if (tempDenominator < 0) {
    tempNumerator = -tempNumerator;
    tempDenominator = -tempDenominator;
  }

  return Fraction(tempNumerator, tempDenominator);
}

bool Fraction::isEqual(Fraction other) {
  Fraction selfSimplified = this->simplified();
  Fraction otherSimplified = other.simplified();

  if (selfSimplified.numerator == otherSimplified.numerator &&
      selfSimplified.denominator == otherSimplified.denominator)
    return true;
  else
    return false;
}

bool Fraction::isGreater(Fraction other) {
  return (numerator / denominator) > (other.numerator / other.denominator);
}

bool Fraction::isLess(Fraction other) {
  return (numerator / denominator) < (other.numerator / other.denominator);
}

void Fraction::printFraction() {
  if (denominator < 0) {
    numerator = -numerator;
    denominator = -denominator;
  }

  cout << numerator << '/' << denominator << endl;
}

void Fraction::readFraction() {
  int tempNumerator;
  cin >> tempNumerator;

  int tempDenominator;
  cin >> tempDenominator;

  setNumerator(tempNumerator);
  setDenominator(tempDenominator);
}
