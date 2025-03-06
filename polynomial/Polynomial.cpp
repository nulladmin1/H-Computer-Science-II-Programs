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
    for (int i = 0; i < 10; i++)
    {
        this->coefficients.push_back(0);
    }

    for (int i = 0; i < coefficients.size(); i++)
    {
        setCoeffiecent(i, coefficients[i]);
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

int Polynomial::degree()
{
    for (int i = 9; i >= 0; i--)
    {
        if (coefficients[i] != 0)
        {
            return i;
        }
    }
}

bool Polynomial::isZero() {
    for (int i = 0; i < 10; i++)
    {
        if (getCoeffiecent(i) != 0)
        {
            return false;
        }
    }
    return true;
}

Polynomial Polynomial::add(Polynomial right)
{
    vector<int> sum(10, 0);

    for (int i = 0; i < 10; i++)
    {
        sum.at(i) = coefficients.at(i) + right.getCoeffiecent(i);
    }

    return Polynomial(sum);
}

Polynomial Polynomial::subtract(Polynomial right)
{
    vector<int> difference(10, 0);

    for (int i = 0; i < 10; i++)
    {
        difference[i] = coefficients[i] - right.getCoeffiecent(i);
    }

    return Polynomial(difference);
}

Polynomial Polynomial::multiply(Polynomial right)
{
    vector<int> tempCoefficients(10, 0);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i + j < 10)
            {
                tempCoefficients.at(i + j) += coefficients.at(i) * right.getCoeffiecent(j);
            }
        }
    }

    return Polynomial(tempCoefficients);
}

Polynomial Polynomial::divide(Polynomial divisor)
{
    if (!divisor.isZero())
    {
        throw invalid_argument("Divisor cannot be zero when dividing");
    }

    vector<int> quotient(10, 0);
    Polynomial remainder = *this;

    while (!remainder.isZero() && remainder.degree() > divisor.degree()) {

    }

    return Polynomial();
}

int Polynomial::getCoeffiecent(int index)
{
    return coefficients.at(index);
}

Polynomial Polynomial::operator+(Polynomial& right)
{
    return add(right);
}

Polynomial Polynomial::operator-(Polynomial& right)
{
    return subtract(right);
}

Polynomial Polynomial::operator*(Polynomial& right)
{
    return multiply(right);
}

Polynomial Polynomial::operator/(Polynomial& divisor)
{
    return Polynomial();
}

Polynomial Polynomial::operator%(Polynomial& divisor) {

    return divide(divisor);
}

Polynomial& Polynomial::operator=(Polynomial& right)
{
    if (this != &right)
    {
        coefficients = right.coefficients;
    }
    return *this;
}

ostream& operator<<(ostream& output, Polynomial& p)
{
    if (p.isZero())
    {
        output << "0";
        return output;
    }

    int count = 0;
    for (int i = 9; i >= 0; i--)
    {
        if (p.getCoeffiecent(i) != 0)
        {
            if (abs(p.getCoeffiecent(i)) != 1)
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
            }else if(abs(p.getCoeffiecent(i))==1){
                if (p.getCoeffiecent(i) > 0)
                {
                    if (count > 0)
                    {
                        output << "+";
                    }
                }
                else
                {
                    output << "-";
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

istream& operator>>(istream& input, Polynomial& p)
{
    for (int i = 0; i < 10; i++)
    {
        int value;
        cout << "Enter a coefficient: ";
        input >> value;
        p.setCoeffiecent(i, value);
    }
    return input;
}
