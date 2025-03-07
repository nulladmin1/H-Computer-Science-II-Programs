// Polynomial Class Implementation File
// 3-3-25
// Period 4
// Shrey Deogade & Dylan Staykov
#include "Polynomial.h"
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

// Default constructor initializes a Vector of 10 coefficients to 0
Polynomial::Polynomial() {
  for (int i = 0; i < 10; i++) {
    coefficients.push_back(0);
  }
}

// Constructor initializes a Vector of 10 coefficients to the values in the
//  argument
Polynomial::Polynomial(vector<int> coefficients) {
  for (int i = 0; i < 10; i++) {
    this->coefficients.push_back(0);
  }

  for (int i = 0; i < coefficients.size(); i++) {
    setCoefficient(i, coefficients[i]);
  }
}

// Set the coefficient at the given index to the given value
void Polynomial::setCoefficient(int index, int value) {
  if (index > 9 || index < 0) {
    throw invalid_argument("Index must be between 0 and 9");
  } else {
    coefficients.at(index) = value;
  }
}

// Calculate the degree of the Polynomial
int Polynomial::degree() {
  // Loop through the coefficients in reverse order and return the index of the
  // first non-zero coefficient, which is the degree
  for (int i = 9; i >= 0; i--) {
    if (coefficients[i] != 0) {
      return i;
    }
  }
  return 0;
}

// Return true if the Polynomial is zero
bool Polynomial::isZero() {
  // Loop through the coefficients and return false if any are not zero
  for (int i = 0; i < 10; i++) {
    if (getCoefficient(i) != 0) {
      return false;
    }
  }
  return true;
}

// Add two Polynomials together - used by the + operator
Polynomial Polynomial::add(Polynomial &right) {
  vector<int> sum(10, 0);

  for (int i = 0; i < 10; i++) {
    sum.at(i) = coefficients.at(i) + right.getCoefficient(i);
  }

  return Polynomial(sum);
}

// Subtract two Polynomials - used by the - operator
Polynomial Polynomial::subtract(Polynomial &right) {
  vector<int> difference(10, 0);

  for (int i = 0; i < 10; i++) {
    difference[i] = coefficients[i] - right.getCoefficient(i);
  }

  return Polynomial(difference);
}

// Multiply two Polynomials - used by the * operator
Polynomial Polynomial::multiply(Polynomial &right) {
  vector<int> tempCoefficients(10, 0);

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (i + j < 10) {
        tempCoefficients.at(i + j) +=
            coefficients.at(i) * right.getCoefficient(j);
      }
    }
  }

  return Polynomial(tempCoefficients);
}

// Divide two Polynomials - used by the / operator
// Adapted from the polynomial division algorithm (n/d):
Polynomial Polynomial::divide(Polynomial &divisor) {
  // Require that the divisor is not zero
  // require d =/ 0
  if (divisor.isZero()) {
    throw invalid_argument("Divisor cannot be zero when dividing");
  }

  // Initialize quotient Polynomial to 0
  //  q <- 0
  Polynomial quotient;

  // Initialize remainder Polynomial to the dividend
  //  r <- n
  Polynomial remainder = *this;

  // Iterate while the remainder is not zero and the degree of the remainder
  //  while r ≠ 0 and degree(r) ≥ degree(d) do
  while (!remainder.isZero() && remainder.degree() >= divisor.degree()) {
    // Calculate the difference in degrees between the remainder and the divisor
    //  t <- lead(r) / lead(d)
    int difference = remainder.degree() - divisor.degree();
    int leadingCoefficient = remainder.getCoefficient(remainder.degree()) /
                             divisor.getCoefficient(divisor.degree());

    vector<int> termCoefficients(difference + 1, 0);
    termCoefficients[difference] = leadingCoefficient;
    Polynomial term(termCoefficients);

    // Create a temporary Polynomial to store the sum of the quotient and the
    // term
    Polynomial tempQuotient = quotient.add(term);
    Polynomial division = divisor.multiply(term);

    // Update the quotient to the sum of the previous quotient and the term
    //  q <- q + t
    quotient = tempQuotient;

    // Update the remainder to the difference of the previous remainder and the
    // product of the divisor and the term
    //  r <- r - t * d
    Polynomial subtracted = remainder.subtract(division);
    remainder = subtracted;
  }

  return quotient;
}

// Modulo two Polynomials - used by the % operator
// Exactly identical to the division method except returning the remainder
// instead
Polynomial Polynomial::mod(Polynomial &divisor) {
  if (divisor.isZero()) {
    throw invalid_argument("Divisor cannot be zero when dividing");
  }

  Polynomial quotient;

  //  r <- n
  Polynomial remainder = *this;

  //  while r ≠ 0 and degree(r) ≥ degree(d) do
  while (!remainder.isZero() && remainder.degree() >= divisor.degree()) {
    //  t <- lead(r) / lead(d)
    int difference = remainder.degree() - divisor.degree();
    int leadingCoefficient = remainder.getCoefficient(remainder.degree()) /
                             divisor.getCoefficient(divisor.degree());

    vector<int> termCoefficients(difference + 1, 0);
    termCoefficients[difference] = leadingCoefficient;
    Polynomial term(termCoefficients);

    Polynomial tempQuotient = quotient.add(term);
    Polynomial division = divisor.multiply(term);

    //  q <- q + t
    quotient = tempQuotient;

    //  r <- r - t * d
    Polynomial subtracted = remainder.subtract(division);
    remainder = subtracted;
  }

  return remainder;
}

// Return the coefficient at the given index
int Polynomial::getCoefficient(int index) { return coefficients.at(index); }

// All of the following methods are overloaded operators for the Polynomial,
// using the methods defined above
Polynomial Polynomial::operator+(Polynomial &right) { return add(right); }

Polynomial Polynomial::operator-(Polynomial &right) { return subtract(right); }

Polynomial Polynomial::operator*(Polynomial &right) { return multiply(right); }

Polynomial Polynomial::operator/(Polynomial &divisor) {
  return divide(divisor);
}

Polynomial Polynomial::operator%(Polynomial &divisor) { return mod(divisor); }

Polynomial &Polynomial::operator=(Polynomial &right) {
  // Set the coefficients of the Polynomial on the left to the coefficients of
  // the right if they are not the same
  if (this != &right) {
    coefficients = right.coefficients;
  }
  return *this;
}

// Overloaded output operator to print the Polynomial
ostream &operator<<(ostream &output, Polynomial &p) {
  if (p.isZero()) {
    output << "0";
    return output;
  }

  int count = 0;
  for (int i = 9; i >= 0; i--) {
    if (p.getCoefficient(i) != 0) {
      if (abs(p.getCoefficient(i)) != 1) {
        if (p.getCoefficient(i) > 0) {
          if (count > 0) {
            output << "+";
          }
          output << p.getCoefficient(i);
        } else {
          output << "-";
          output << p.getCoefficient(i) * -1;
        }
      } else if (abs(p.getCoefficient(i)) == 1) {
        if (p.getCoefficient(i) > 0) {
          if (count > 0) {
            output << "+";
          }
        } else {
          output << "-";
        }
      }
      if (i != 0) {
        output << "x";
      }
      if (i != 0 && i != 1) {
        output << "^";
        output << i;
      }
      count++;
    }
  }

  return output;
}

// Overloaded input operator to read the coefficients of the Polynomial
istream &operator>>(istream &input, Polynomial &p) {
  for (int i = 0; i < 10; i++) {
    int value;
    cout << "Enter a coefficient: ";
    input >> value;
    p.setCoefficient(i, value);
  }
  return input;
}
