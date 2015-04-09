#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
using namespace std;
class Fraction
{
 private:
  int numerator,denominator;
 public:
  Fraction();
  Fraction(int numerator,int denominator);
  void Output();
  Fraction Reciprocal();
};

#endif
