// Polynomial Class Implementation File
// 3-3-25
// Period 4
// Shrey Deogade & Dylan Staykov

#include "Polynomial.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Polynomial::Polynomial()
{
    setCoeffiecent(0, 10);
    setCoeffiecent(1, 5);
    setCoeffiecent(2, 1);
}

Polynomial::Polynomial(int coeffiecient[])
{
    for (int i = 0; i < 10; i++)
    {
        setCoeffiecent(i, coeffiecient[i]);
    }
}

void Polynomial::setCoeffiecent(int index, int value)
{
    if (index > 9 || index < 0)
    {
        throw invalid_argument("Index must be between 0 and 10");
    }
    else
    {
        coefficients[index] = value;
    }
}

int Polynomial::getCoeffiecent(int index)
{
    return coefficients[index];
}

Polynomial Polynomial::operator+(Polynomial &right)
{
    int sum[10] = {0};

    for (int i = 0; i < 10; i++)
    {
        sum[i] = coefficients[i] + right.getCoeffiecent(i);
    }

    return Polynomial(sum);
}

Polynomial Polynomial::operator-(Polynomial &right)
{
    int difference[10] = {0};

    for (int i = 0; i < 10; i++)
    {
        difference[i] = coefficients[i] - right.getCoeffiecent(i);
    }

    return Polynomial(difference);
}

Polynomial Polynomial::operator*(Polynomial &right)
{
    int tempCoefficients[10]{};

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

Polynomial Polynomial::operator/(Polynomial &)
{
    return Polynomial();
}

Polynomial Polynomial::operator=(Polynomial &right)
{
    return *this;
}

ostream &operator<<(ostream &output, Polynomial &p)
{
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
