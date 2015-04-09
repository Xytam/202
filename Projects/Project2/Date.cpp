/*
 * Template Date.cpp
 *
 * Students must implement the entire class, including full handling
 * of leap years.
 */


#include <iostream>
#include "Date.h"

using namespace std;

/* IMPLEMENTATION GOES HERE */

Date::Date()
{
  	m_month=1;
  	m_day=1;
  	m_year=MIN_YEAR; 
}
Date::Date(int month,int day,int year)
{
	SetMonth(month);
	SetDay(day);
	SetYear(year);
}
int Date::GetMonth() const
{
	return m_month;
}
int Date::GetDay() const
{
	return m_day;
}
int Date::GetYear() const
{
	return m_year;
}
void Date::SetMonth(int month)
{
	if(month > 0 && month <= 12)
		m_month = month;
	else
	{
		cout <<  "Invalid Month setting to default\n";
		m_month = 1;
	}
}
void Date::SetDay(int day)
{
	int lengthOfMonth[]={31,28,31,30,31,30,31,31,30,31,30,31};
	if( (m_year%400==0 || m_year%100!=0) &&(m_year%4==0))
	{
		//Leap Year
	 	if(m_month==2 && day > 0 && day <= 29)
			m_day=day;
	 	else if(m_month != 2 && day > 0 && day <= lengthOfMonth[m_month-1])
			m_day=day;
     		else
			{
				cout << "Invalid Day setting to default\n";
				m_day=1;
			}
	}
	else
  	{	
		//Not Leap Year
		if(day > 0 && day <= lengthOfMonth[m_month-1])
			m_day=day;
    		else
			{
				cout << "Invalid Day setting to default\n";
				m_day=1;
			}
	}

}
void Date::SetYear(int year)
{
	if(year >= MIN_YEAR && year <= MAX_YEAR)
		m_year=year;
	else
	{
		cout << "Invalid Year setting to default\n";
		m_year=MIN_YEAR;
	}
}
void Date::PrintDate() const
{
	cout << m_month << "/" << m_day <<  "/" <<  m_year <<  "\n";
}