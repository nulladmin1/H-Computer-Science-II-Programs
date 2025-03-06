// Polynomial Class Implementation File
// 3-3-25
// Period 4
// Shrey Deogade & Dylan Staykov

#include "Polynomial.h"
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

Polynomial::Polynomial()
{
    for (int i = 0; i < 10; i++)
    {
        coefficients.push_back(0);
    }
}

Polynomial::Polynomial(vector<int> coefficients)
{
    for (int i = 0; i < coefficients.size(); i++)
    {
        setCoeffiecent(i, coefficients[i]);
    }

    for (int i = coefficients.size(); i < 10; i++)
    {
        setCoeffiecent(i, 0);
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

void Polynomial::updateDegree()
{
    int degree = 0;

    for (int i = 9; i >= 0; i--)
    {
        if (coefficients[i] != 0)
        {
            degree = i;
            break;
        }
    }

    this->degree = degree;
}

int Polynomial::getDegree()
{
    return degree;
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
    vector<int> difference(10);

    ;

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
                tempCoefficients[i + j] += coefficients[i] *
                                           right.getCoeffiecent(j);
            }
        }
    }

    return Polynomial(tempCoefficients);
}

Polynomial Polynomial::operator/(Polynomial &divisor)
{
    bool isDivisorZero = true;

    for (int i = 0; i < 10; i++)
    {
        if (divisor.getCoeffiecent(i) != 0)
        {
            isDivisorZero = false;
        }
    }

    if (isDivisorZero)
    {
        throw invalid_argument("Divisor cannot be zero");
    }

    vector<int> quotient(10, 0);
    vector<int> remainder = coefficients;

    return Polynomial();
}

Polynomial &Polynomial::operator=(Polynomial &right)
{
    if (this != &right)
    {
        coefficients = right.coefficients;
    }
    return *this;
}

ostream &operator<<(ostream &output, Polynomial &p)
{
    int zeroCount = 0;

    for (int i = 9; i >= 0; i--)
    {
        if (p.getCoeffiecent(i) == 0)
        {
            zeroCount++;
        }
    }
    if (zeroCount == 10)
    {
        output << "0";
        return output;
    }

    int count = 0;
    for (int i = 9; i >= 0; i--)
    {
        if (p.getCoeffiecent(i) != 0)
        {
            if (p.getCoeffiecent(i) != 1)
            {
                if (p.getCoeffiecent(i) > 0)
                {
                    if (count > 0)
                    {
                        output << "+";
                    }
                    output << p.getCoeffiecent(i);
                }
                else
                {
                    output << "-";
                    output << p.getCoeffiecent(i) * -1;
                }
            }
            if (i != 0)
            {
                output << "x";
            }
            if (i != 0 && i != 1)
            {
                output << "^";
                output << i;
            }
            count++;
        }
    }

    return output;
}

istream &operator>>(istream &input, Polynomial &p)
{
    for (int i = 0; i < 10; i++)
    {
        input >> p.coefficients[i];
    }
    return input;
}
