#pragma once
#include <iostream>
#include <fstream>
#include "MyString.h"


class MyDate {
	int d, m, y;
	static int d0;
	static int m0;
	static int y0;
	static int dw0;
public:
	MyDate();
	MyDate(int, int, int);
	void Print();
	static void SetInitDate(int di, int mi, int yi, int dwi)
	{
		d0 = di;
		m0 = mi;
		y0 = yi;
		dw0 = dwi;
	}
	int DayOfYear();
	int NumberDayOfWeek();
	friend bool leapyear(MyDate);

	//operator char* ()
	//{
	//	char str[11];
	//	str[2] = str[5] = '.';
	//	str[0] = d / 10+'0';
	//	str[1] = d % 10+'0';
	//	str[3] = m / 10+'0';
	//	str[4] = m % 10+'0';
	//	str[6] = y / 1000+'0';
	//	str[7] = y % 1000/100+'0';
	//	str[8] = y % 100/10+'0';
	//	str[9] = y % 10+'0';
	//	str[10] = '\0';
	//	std::cout <<std::endl<< "|" << str << "|"<<std::endl;
	//	return str;
	//}

	operator MyString()
	{
		char str[11];
		str[2] = str[5] = '.';
		str[0] = d / 10 + '0';
		str[1] = d % 10 + '0';
		str[3] = m / 10 + '0';
		str[4] = m % 10 + '0';
		str[6] = y / 1000 + '0';
		str[7] = y % 1000 / 100 + '0';
		str[8] = y % 100 / 10 + '0';
		str[9] = y % 10 + '0';
		str[10] = '\0';
		return MyString(str);
	}

	MyDate operator++();
	MyDate operator++(int);

	MyDate operator--();
	MyDate operator--(int);

	friend std::ostream& operator<<(std::ostream& out, const MyDate& date);
	friend std::ofstream& operator<<(std::ofstream& out, const MyDate& date);
	friend std::istream& operator>>(std::istream& in, MyDate& date);

	MyDate& operator=(const MyDate& date);

	friend bool operator<(const MyDate&, const MyDate&);
	friend bool operator>(const MyDate&, const MyDate&);
	friend bool operator<=(const MyDate&, const MyDate&);
	friend bool operator>=(const MyDate&, const MyDate&);

	friend bool operator==(const MyDate&, const MyDate&);
	friend bool operator!=(const MyDate&, const MyDate&);

	MyDate& operator+=(const MyDate& date);
	MyDate& operator-=(const MyDate& date);

	MyDate operator+(const MyDate& date1);
	MyDate operator+(const int);
	MyDate operator-(const MyDate& date1);
	MyDate operator-(const int);
	bool valid(int, int, int);
private:


};