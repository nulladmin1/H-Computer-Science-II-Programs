// Shrey Deogade
// Period 4
// 2-18-25
// Fraction Implementation Details

#include "Fraction.h"

// Needed for input/output operations
#include <iostream>

// Needed for exception handling and throwing errors
#include <stdexcept>
using namespace std;

// The constructors

// Constructor with parameters for numerator and denominators,
//   using setters to set the values for error checking
Fraction::Fraction(int n, int d)
{
    setNumerator(n);
    setDenominator(d);
}

// Default constructor, setting the numerator and denominator to 1
Fraction::Fraction()
{
    setNumerator(1);
    setDenominator(1);
}

// Set the numerator to the given value (doesn't need any error checking)
void Fraction::setNumerator(int numerator)
{
    this->numerator = numerator;
}

// Set the denominator to the given value, with error checking for 0
void Fraction::setDenominator(int denominator)
{
    if (denominator == 0)
    {
        throw invalid_argument("Denominator cannot be zero");
    }
    else
        this->denominator = denominator;
}

// Get the numerator
int Fraction::getNumerator()
{
    return numerator;
}

// Get the denominator
int Fraction::getDenominator()
{
    return denominator;
}

// Return a new Fraction that is the sum of this Fraction and another Fraction
Fraction Fraction::add(Fraction other)
{
    // Find the common denominator
    int commonDenominator = this->denominator * other.denominator;

    // Add the numerators together using butterfly method
    int addedNumerator =
        this->numerator * other.denominator + other.numerator *
        this->denominator;

    // Return the new Fraction with the new numerator and common denominator
    return Fraction(addedNumerator, commonDenominator);
}

// Return a new Fraction that is the difference of this Fraction and another
//  fraction
Fraction Fraction::subtract(Fraction other)
{
    // Find the common denominator
    int commonDenominator = this->denominator * other.denominator;

    // Subtract the numerators using butterfly method
    int subtractedNumerator =
        this->numerator * other.denominator - other.numerator *
        this->denominator;

    // Return the new Fraction with the new numerator and common denominator
    return Fraction(subtractedNumerator, commonDenominator);
}

// Return a new Fraction that is the product of this Fraction and another
Fraction Fraction::multiply(Fraction other)
{
    // Cross-multiply the numerators and denominators to get the product
    return Fraction(numerator * other.numerator,
                    denominator * other.denominator);
}

// Return a new Fraction that is the quotient of this Fraction and another
Fraction Fraction::divide(Fraction other)
{
    // Divide by multiplying by the reciprocal
    return multiply(Fraction(other.denominator, other.numerator));
}

// Recursive function to find the greatest common divisor of two numbers
int Fraction::gcd(int a, int b)
{
    // Base case: if b is 0, return a
    if (b == 0)
        return a;
    else
        // Works due to the Euclidean algorithm - the gcd of a and b
        //   is the same as the GCD of b and a % b, and so on
        //   and so forth until you get the common GCD;
        return gcd(b, a % b);
}

// Return a new Fraction that is the simplified version of this Fraction
Fraction Fraction::simplified()
{
    // Make a copy of the numerator and denominator
    int tempNumerator = numerator;
    int tempDenominator = denominator;

    // Find the greatest common divisor of the numerator and denominator
    int gcd_value = gcd(tempNumerator, tempDenominator);

    // Divide both the numerator and denominator by the GCD to simplify
    tempNumerator /= gcd_value;
    tempDenominator /= gcd_value;

    // Return the simplified Fraction
    return Fraction(tempNumerator, tempDenominator);
}

// Set the simiplified version of this Fraction to the current Fraction
void Fraction::simplify()
{
    // Get the simplified version of the Fraction
    Fraction simplifiedFraction = simplified();

    // Use setters to set the numerator and denominator to the simplified values
    setNumerator(simplifiedFraction.numerator);
    setDenominator(simplifiedFraction.denominator);
}

Comparison Fraction::compare(Fraction other)
{
    // Get the simplified versions of both Fractions
    Fraction selfSimplified = this->simplified();
    Fraction otherSimplified = other.simplified();

    // If the simplified numerators and denominators are the same, return EQUAL
    if (selfSimplified.numerator == otherSimplified.numerator &&
        selfSimplified.denominator == otherSimplified.denominator)
        return EQUAL;
    // Convert to decimal. If the current Fraction is greater, return GREATER
    else if ((numerator / denominator) > (other.numerator / other.denominator))
        return GREATER;
    // Else: the current Fraction is less, return LESS
    else
        return LESS;
}

// Compare this and another Fraction to see if they are equal
bool Fraction::isEqual(Fraction other)
{
    // Use the compare function to see if the Fractions are equal
    return compare(other) == EQUAL;
}

// Compare this and another Fraction to see if this Fraction is greater
bool Fraction::isGreater(Fraction other)
{
    // Use the compare function to see if the current Fraction is greater
    return compare(other) == GREATER;
}

// Compare this and another Fraction to see if this Fraction is less
bool Fraction::isLess(Fraction other)
{
    // Use the compare function to see if the current Fraction is less
    return compare(other) == LESS;
}

// Print the Fraction in the form "numerator/denominator"
void Fraction::printFraction()
{
    // If the denominator is negative, make the numerator negative and the
    //   denominator positive
    if (denominator < 0)
    {
        numerator = -numerator;
        denominator = -denominator;
    }

    if (numerator % denominator == 0)
    {
        // Print whole number if numerator divides evenly with denominator
        cout << numerator / denominator;
    }
    else if (abs(numerator) > denominator)
    {
        // Print the Fraction in mixed form if numerator > denominator
        int tempNumerator = numerator;

        int integer = (int)(abs(tempNumerator) / abs(denominator));

        if (tempNumerator < 1)
        {
            integer = -integer;
            tempNumerator = -tempNumerator;
        }

        tempNumerator -= abs(integer) * denominator;

        cout << integer << " " << tempNumerator << '/' << denominator;
    }

    else
    {
        // Print the Fraction in improper form if numerator < denominator
        cout << numerator << '/' << denominator;
    }

    cout << endl;
}

// Read the Fraction from user input
void Fraction::readFraction()
{
    // Read the numerator and denominator from the user,
    //  and store them in temporary variables
    int tempNumerator;

    cin >> tempNumerator;

    cout << "-" << endl;

    int tempDenominator;
    cin >> tempDenominator;

    // Use setters to set the numerator and denominator to the temporary values
    //   for error checking
    setNumerator(tempNumerator);
    setDenominator(tempDenominator);
}