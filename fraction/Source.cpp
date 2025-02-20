// Shrey Deogade
// Period 4
// 2-18-25
// Fraction Source File

#include "Fraction.h"
#include <iostream>
using namespace std;

int main()
//    // Test the denominator being 0
//    try {
//        Fraction f1(1, 0);
//    }
//    catch (invalid_argument& e) {
//        cout << "DivByZero - pass!: " << e.what() << endl;
//    }
//
//    // Default constuctor
//    Fraction default_fraction;
//    cout << "Default constructor: ";
//    default_fraction.printFraction();
//    cout << "^ should be 1" << endl << endl;
//
//    // Correct simplify
//    cout << "Test simplification: " << endl;
//    Fraction simplifyTest(3, -6);
//    cout << "\tNormal: ";
//    simplifyTest.printFraction();
//    cout << "\tSimplified: ";
//    simplifyTest.simplify();
//    simplifyTest.printFraction();
//
//    // Testing for addition/subtraction
//    cout << endl << "Testing for additon & subtraction" << endl;
//
//    Fraction frac1(2, 3);
//    cout << "\tFirst fraction: ";
//    frac1.printFraction();
//
//    Fraction frac2(1, 5);
//    cout << "\tSecond fraction: ";
//    frac2.printFraction();
//
//    cout << "\tSum:";
//    Fraction sum = frac1.add(frac2);
//    sum.printFraction();
//
//    cout << "\tDifference (raw): ";
//    Fraction difference = sum.subtract(frac2);
//    difference.printFraction();
//
//    cout << "\tDifference (simplified) (should be first fraction): ";
//    difference.simplified().printFraction();
//
//    // Testing for multiplication/divison
//    cout << endl << "Testing for multiplication & division" << endl;
//
//    Fraction frac3(2, 3);
//    cout << "\tFirst fraction: ";
//    frac3.printFraction();
//
//    Fraction frac4(3, 2);
//    cout << "\tSecond fraction: ";
//    frac4.printFraction();
//
//    cout << "\tMultiplication: ";
//    frac3.multiply(frac4).printFraction();
//
//    cout << "\Multiplication (simplified): ";
//    frac3.multiply(frac4).simplified().printFraction();
//
//    cout << "\Division: ";
//    frac3.divide(frac4).printFraction();
//
//    cout << "\Division (simplified): ";
//    frac3.divide(frac4).simplified().printFraction();
//
//    // Testing to comparison
//    cout << endl << "Testing for comparison" << endl;
//
//    Fraction frac5(2, 3);
//    cout << "\tFirst fraction: ";
//    frac5.printFraction();
//
//    Fraction frac6(2, 3);
//    cout << "\tSecond fraction: ";
//    frac6.printFraction();
//
//    Fraction frac7(3, 3);
//    cout << "\Third fraction: ";
//    frac7.printFraction();
//
//    cout << "\tFirst is equal to second? (should be 1): ";
//    cout << frac5.isEqual(frac6);
//    cout << endl;
//
//    cout << "\tFirst is equal to Third? (should be 0): ";
//    cout << frac5.isEqual(frac7);
//    cout << endl;
//
//
//    cout << "\tFirst is greater than third? (should be 0): ";
//    cout << frac5.isGreater(frac7);
//    cout << endl;
//
//
//    cout << "\tFirst is less than third? (should be 1): ";
//    cout << frac5.isLess(frac7);
//    cout << endl;
//
//    // Read fraction
//    Fraction read;
//    read.readFraction();
//
//    read.printFraction();
{
    Fraction f1;
    f1.readFraction();

    cout << endl;
    
    Fraction f2;
    f2.readFraction();

    cout << "Sum: ";
    f1.add(f2).printFraction();

    cout << "Difference: ";
    f1.subtract(f2).simplified().printFraction();

    return 0;
}
