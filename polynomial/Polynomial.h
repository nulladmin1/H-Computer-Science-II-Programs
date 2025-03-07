// Polynomial Class Header File
// 3-3-25
// Period 4
// Shrey Deogade & Dylan Staykov

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <vector>
using namespace std;

class Polynomial {
private:
  vector<int> coefficients;

public:
  Polynomial();
  Polynomial(vector<int>);

  void setCoefficient(int, int);
  int getCoefficient(int);

  int degree();

  bool isZero();

  Polynomial add(Polynomial &);
  Polynomial subtract(Polynomial &);
  Polynomial multiply(Polynomial &);
  Polynomial divide(Polynomial &);
  Polynomial mod(Polynomial &);

  Polynomial operator+(Polynomial &);
  Polynomial operator-(Polynomial &);
  Polynomial operator*(Polynomial &);
  Polynomial operator/(Polynomial &);
  Polynomial operator%(Polynomial &);
  Polynomial &operator=(Polynomial &);

  friend ostream &operator<<(ostream &, Polynomial &);
  friend istream &operator>>(istream &, Polynomial &);
};

#endif // POLYNOMIAL_H
