#include <iostream>
#include "Fraction.h"
using namespace std;
int main()
{
  int numerator,denominator;
  cout <<"Please enter the numerator.. \n";
  cin >> numerator;
  cout <<"Please enter the denominator.. \n";
  cin >> denominator;
  Fraction frac1(numerator,denominator);
  Fraction frac1Recip=frac1.Reciprocal();
  frac1Recip.Output();
  Fraction frac2;
  frac2.Output();
  Fraction frac3(1,0);
  return 0;

}
