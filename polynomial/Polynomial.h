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
int degree;

void updateDegree();

public:
Polynomial();
Polynomial(vector<int>);

void setCoeffiecent(int, int);
int getCoeffiecent(int);
vector<int> getCoefficients();

int getDegree();

Polynomial operator+(Polynomial &);
Polynomial operator-(Polynomial &);
Polynomial operator*(Polynomial &);
Polynomial operator/(Polynomial &);
Polynomial &operator=(Polynomial &);

friend ostream &operator<<(ostream &, Polynomial &);
};

#endif // POLYNOMIAL_H
