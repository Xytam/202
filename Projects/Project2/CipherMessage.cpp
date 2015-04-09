 /*
 * Template CipherMessage.cpp
 *
 * Students may NOT modify the provided constructors or LoadFromFile()
 * function.  Functions may be added AFTER LoadFromFile().
 */

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cmath>
#include <math.h>
#include "CipherMessage.h"
#include "Date.h"

using namespace std;

CipherMessage::CipherMessage() 
  : m_text(""), m_from(""), m_to(""), m_sentDate(Date(1,1,1970))
{ /* Empty function body */ }

CipherMessage::CipherMessage(string from, string to, Date sentDate, string text) 
  : m_from(from), m_to(to), m_sentDate(sentDate)
{ 
  m_text = "";

  /* Only copy uppercase letters to m_text */

  for (int i = 0; i < text.length(); i++)
    if (text[i] >= 'A' && text[i] <= 'Z')
      m_text += text[i];
}

bool CipherMessage::LoadFromFile(string fileName) {
  ifstream dataFile;
  string from;
  string to;
  int month, day, year;
  char text_cstr[MAX_CIPHERLEN];
  string text;

  /* Set exception flags for file input stream */ 

  dataFile.exceptions(ios::failbit | ios::badbit);

  try {

    dataFile.open(fileName.c_str());

    /* Read from, to, month, day, year */

    dataFile >> from;
    dataFile >> to;
    dataFile >> month >> day >> year;

    /* Read text.  First getline() clears previous newline */

    dataFile.getline(text_cstr, MAX_CIPHERLEN);
    dataFile.getline(text_cstr, MAX_CIPHERLEN);

    /* Only copy uppercase letters to string */
    
    for (int i = 0; i < strlen(text_cstr); i++)
      if (text_cstr[i] >= 'A' && text_cstr[i] <= 'Z')
	text += text_cstr[i];

    dataFile.close();
  } 
  catch (exception e) {
    return false;
  }

  /* Made it through file read; assign to class variables. */

  m_from = from;
  m_to = to;
  m_sentDate = Date(month, day, year);
  m_text = text;

  return true;
}
string CipherMessage:: Decipher()
{
	string 	keyString;

	// max key length of 6
	int alphabetKeys [6];
	
	for(int i=1;i<=6;i++)
	{
		double greatestLogOddsList[i];
		double sumOfList=0;
		memset(alphabetKeys,0,sizeof(alphabetKeys));


		//KEEPS TESTING FIRST INDEX VALUE K=0 RESETTI

		//number of substrings tested
		for(int j=0; j<i;j++)
		{
			double greatestLogOdds=0;
			int alphabetKey=0;
			//testing every letter in alphabet for substring
			for(int alphabetIterator = 0; alphabetIterator < 26; alphabetIterator++)
			{
				double tempLogOdds=0;
	
				//going through each letter in substring
				for(int k = j; k<m_text.length();k+=i)
				{
					int almostRelevantValue=0;

					if(m_text[k]-alphabetIterator < 65)
						almostRelevantValue=(m_text[k]-alphabetIterator+26-65);	
					else
						almostRelevantValue=(m_text[k]-alphabetIterator-65);
					tempLogOdds+=(log10(26*EN_FREQ[almostRelevantValue]));
				}
				if(alphabetIterator==0)
					greatestLogOdds=tempLogOdds;
				else if(tempLogOdds>greatestLogOdds)
				{
					greatestLogOdds=tempLogOdds;
					alphabetKeys[j]=alphabetKey;

				}
				alphabetKey++;
				

			}
			greatestLogOddsList[j]=greatestLogOdds;
			for(int sumOdds=0; sumOdds<i;sumOdds++)
			{
				sumOfList+=greatestLogOddsList[sumOdds];
			}
		}
		if(sumOfList>0)
			{
				for(int stringValue=0;stringValue<i;stringValue++)
				{
					keyString+=(ALPHABET[alphabetKeys[stringValue]]);
				}
				return Decipher(keyString);
			}
	}
}
string CipherMessage:: Decipher(string key)
{
	string plainText;
	int alphaKey;
	if(key.length()==1)
	{
		for(int i = 0;i<m_text.length();i++)
		{	

			if(((int)(m_text[i])-(int)(key[0]))<0)
				alphaKey=ALPHABET[26+((int)(m_text[i])-(int)(key[0]))];
			else
				alphaKey=ALPHABET[(int)(m_text[i])-(int)(key[0])];

			plainText+=alphaKey;
		}
	}
	else
	{
		int posInKey=0;
		for(int i = 0; i<m_text.length();i++)
		{
			if((m_text[i]-(key[posInKey]-65))<65)
				plainText+=(m_text[i]-(key[posInKey]-65)+26);
			else
				plainText+=(m_text[i]-(key[posInKey]-65));

			posInKey++;
			
			if(posInKey==key.length())
				posInKey=0;		
		}
	}
	return plainText;
}
string CipherMessage:: GetText() const
{
	string realText;
	for(int i=0;i<m_text.length();i++)
	{
		if(m_text[i]>='A' && m_text[i] <='Z')
			realText+=m_text[i];
	}
	return realText;
}
string CipherMessage:: GetFrom() const
{
	return m_from;
}
string CipherMessage:: GetTo() const
{
	return m_to;
}
Date CipherMessage:: GetSentDate() const
{
	return m_sentDate;
}
void CipherMessage:: SetFrom(string from)
{
	m_from=from;
}
void CipherMessage:: SetTo(string to)
{
	m_to=to;
}
void CipherMessage:: SetSentDate(const Date& sentDate)
{
	m_sentDate=sentDate;
}
void CipherMessage:: SetText(string text)
{
	m_text=text;
}