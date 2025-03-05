// Polynomial Class Header File
// 3-3-25
// Period 4
// Shrey Deogade & Dylan Staykov

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
using namespace std;

class Polynomial {
private:
  int coefficients[10]{};

public:
  Polynomial();
  Polynomial(int[]);

  void setCoeffiecent(int, int);
  int getCoeffiecent(int);

  Polynomial operator+(Polynomial &);
  Polynomial operator-(Polynomial &);
  Polynomial operator*(Polynomial &);
  Polynomial operator/(Polynomial &);
  Polynomial operator=(Polynomial &);

  friend ostream &operator<<(ostream &, Polynomial &);
};

#endif // POLYNOMIAL_H
