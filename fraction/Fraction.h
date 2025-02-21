// Shrey Deogade
// Period 4
// 2-18-25
// Fraction Header File

#ifndef FRACTION_H
#define FRACTION_H

// Enum to enumerate the comparison results
enum Comparison
{
    EQUAL,
    GREATER,
    LESS
};

class Fraction
{
// Restrict access to private attributes
private:
    int numerator;
    int denominator;

    // Helper function for simplifying the fraction
    int gcd(int, int);

    // Helper function for comparison operations - returns the Comparison enum
    Comparison compare(Fraction);

public:
    // Constructors
    Fraction(int, int);
    Fraction();

    // Setters for private attributes
    void setNumerator(int);
    void setDenominator(int);

    // Getters for private attributes
    int getNumerator();
    int getDenominator();

    // Arithmetic operations for Fractions
    Fraction add(Fraction);
    Fraction subtract(Fraction);
    Fraction multiply(Fraction);
    Fraction divide(Fraction);

    // For simplifying the fraction
    void simplify();
    Fraction simplified();

    // Comparison operations
    bool isEqual(Fraction);
    bool isGreater(Fraction);
    bool isLess(Fraction);

    // Input/Output operations
    void printFraction();
    void readFraction();
};

#endif // FRACTION_H
