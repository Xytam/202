#include "Fraction.h"
#include <iostream>
using namespace std;
Fraction::Fraction()
{
  numerator=1;
  denominator=1;
}
Fraction::Fraction(int x, int y)
{
  numerator=x;
  denominator=y;
  if(denominator==0)
    {
      cout << "Invalid Denominator!\n";
    }
  else
    {
    }
}
void Fraction::Output()
{
  cout << numerator << "/" << denominator << "\n";
  return;
}
Fraction Fraction::Reciprocal()
{
  Fraction newFrac(denominator,numerator);
  return (newFrac);
}
