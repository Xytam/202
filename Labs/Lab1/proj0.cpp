/*****************************************
 ** File:    proj0.cpp
 ** Project: CMSC 202 Project 0, Spring 2015
 ** Author:  John Horvers
 ** Date:    01/29/2015
 ** Section: 19
 ** E-mail:  horvers1@umbc.edu 
 **
 **  This program adds two numbers. 
 **
 **
 ***********************************************/
#include <iostream>
using namespace std;
int main() 
{  
  int num1;
  int num2;
  int sum;
  cout << "Enter the first number: ";
  cin >> num1;
  cout <<"Enter the second number: ";
  cin >> num2;
  sum=num1+num2;
  cout << "The sum is " << sum << "\n";
  return 0;
}