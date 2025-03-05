// Polynomial Class Implementation File
// 3-3-25
// Period 4
// Shrey Deogade & Dylan Staykov

#include <iostream>
#include <stdexcept>
#include "Polynomial.h"
using namespace std;

Polynomial::Polynomial()
{
	for (int i = 0; i < 10; i++)
	{
		coefficients.push_back(0);
	}
}

Polynomial::Polynomial(vector<int> coeffiecients)
{
	for (int i = 0; i < 10; i++) 
	{
		setCoeffiecent(i, coeffiecients[i]);
	}
}

void Polynomial::setCoeffiecent(int index, int value)
{
	if (index > 9 || index < 0) 
	{
		throw invalid_argument("Index must be between 0 and 9");
	}
	else 
	{
		coefficients.at(index) = value;
	}
}

int Polynomial::getCoeffiecent(int index)
{
	return coefficients.at(index);
}

Polynomial Polynomial::operator+(Polynomial &right)
{
	vector<int> sum(10);

	for (int i = 0; i < 10; i++) 
	{
		sum[i] = coefficients[i] + right.getCoeffiecent(i);
	}

	return Polynomial(sum);
}

Polynomial Polynomial::operator-(Polynomial &right)
{
	vector<int> difference(10);;

	for (int i = 0; i < 10; i++) 
	{
		difference[i] = coefficients[i] - right.getCoeffiecent(i);
	}

	return Polynomial(difference);
}

Polynomial Polynomial::operator*(Polynomial &right)
{
	vector<int> tempCoefficients(10);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i + j < 10)
			{
				tempCoefficients[i + j] += coefficients[i] * right.getCoeffiecent(j);
			}
		}
	}

	return Polynomial(tempCoefficients);
}

Polynomial Polynomial::operator/(Polynomial&)
{
	return Polynomial();
}

Polynomial Polynomial::operator=(Polynomial &right)
{
	return *this;
}

ostream& operator<<(ostream &output, Polynomial &p)
{
	int zeroCount = 0;
	for (int i = 9; i >= 0; i--) {
		if(p.getCoeffiecent(i) == 0){
			zeroCount++;
		}
	}
	if(zeroCount==10){
		output << "0";
		return output;
	}

	int count = 0;
	for (int i = 9; i >= 0; i--){
		if (p.getCoeffiecent(i) != 0) {
			if (p.getCoeffiecent(i) != 1) {
				if (p.getCoeffiecent(i) > 0) {
					if (count > 0){
						output << "+";
					}
					output << p.getCoeffiecent(i);
				}else{
					output << "-";
					output << p.getCoeffiecent(i) * -1;
				}
			}
			if (i != 0) {
				output << "x";
			}
			if(i != 0 && i != 1){
				output << "^";
				output << i;
			}
			count++;
		}
	}

	return output;
}

istream& operator>>(istream& input, Polynomial& p){
	for(int i = 0; i < 10; i++){
		input >> p.coefficients[i];
	}
	return input;
}
