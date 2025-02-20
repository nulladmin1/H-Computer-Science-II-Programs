// Shrey Deogade
// Period 4
// 2-18-25
// Fraction Header File

#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
private:
  int numerator;
  int denominator;

public:
  Fraction(int, int);
  Fraction();

  void setNumerator(int);
  void setDenominator(int);

  int getNumerator();
  int getDenominator();

  Fraction add(Fraction);
  Fraction subtract(Fraction);
  Fraction multiply(Fraction);
  Fraction divide(Fraction);

  void simplify();
};

#endif // FRACTION_H
