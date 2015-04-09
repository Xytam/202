#include <iostream>
#include <cstring>
using namespace std;
double ComputeVowelFrequency(char strArg[80]);
int main() {

  double vowelFreq;
  char line[80];
  cout << "Please enter a string: "<<endl;
  cin.getline(line, sizeof(line));
  vowelFreq = ComputeVowelFrequency(line);
  cout << "\nYour vowel frequency is: " << vowelFreq;
   return 0;
}

double ComputeVowelFrequency(char strArg[80])
{
  float numVowels;
  int countedChars=strlen(strArg);
  double frequency;
  int length=strlen(strArg);
  for(int i=0;i<=length;i++)
    {
      switch(strArg[i])
	{ 
	case 'a': case 'A': case 'e': case 'E':
	case 'i': case 'I': case 'o': case 'O':
	case 'u': case 'U':
	numVowels++;
	  break;
	case '.': case ',': case ';':case ' ':
	case ':': case '!': case '?':
	  countedChars--;  
	    break;
        }
    }
  frequency=numVowels/countedChars;
  return frequency;
}

