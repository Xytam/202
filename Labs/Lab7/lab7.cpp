#include <iostream>
#include "IntArray.h"

using namespace std;

int main()
{
  // Create IntArray objects and call methods here...
	IntArray workingArray(3);
	IntArray emptyArray(0);
	IntArray firstArray(-1);
	firstArray.~IntArray();
	firstArray.~IntArray();
	IntArray operatorArrayOne(2);
	IntArray operatorArrayTwo(3);
	operatorArrayTwo==operatorArrayOne;
	operatorArrayTwo!=operatorArrayOne;
	workingArray[-1];
	workingArray.Get(-1);
	workingArray.Get(5);
	workingArray.SetItem(-1,89);
	workingArray.SetItem(5,80);	
	workingArray.Insert(-1,20);
	workingArray.Insert(5,20);
	emptyArray.Insert(2,30);
	emptyArray.Del(1);
	workingArray.Del(-1);
	workingArray.Del(8);
	workingArray.Remove(777);
	emptyArray.Remove(50);
	emptyArray.Clear();
	emptyArray.Contains(60);
	emptyArray.Contains(21,1);
	workingArray.Contains(99,-1);
	workingArray.Contains(99,9);
	
	

  
  // Print out the number of errors/edge cases found
  cout << endl << endl << IntArray::GetProgress() << endl;
    
  return 0;
}
