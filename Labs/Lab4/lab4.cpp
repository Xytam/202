#include <iostream>
#include "lab4.h"

using namespace std;

int main() {

  /* Compute and display Factorial(i) for i = 5..10 */

  for (int i = 5; i <= 10; ++i)
    cout << "Factorial(" << i << ") = " << Factorial(i) << endl;

  /* Compute and display ChooseTwo(i) for i = 5..10 */

  for (int i = 5; i <= 10; ++i)
    cout << "ChooseTwo(" << i << ") = " << ChooseTwo(i) << endl;
}

int ChooseTwo(int n) {
  if (n < 2)
    return -1;
  else
    return (n*(n-1))/2;
}
int Factorial(int j)
{
  int n=1;
  if(j==0)
    return 1;
  else if (j<0)
    return -1;
  else
    {
      for (int i=1;i<=j;i++)
	{
	  n= n*i;
	}
      return n;
    }
}

    
  
