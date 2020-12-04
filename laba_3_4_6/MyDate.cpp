#include "MyDate.h"
#include <iostream>

char daytab[2][13] = { {0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31} };

int MyDate::d0, MyDate::m0, MyDate::y0, MyDate::dw0;
int leap(int);

bool MyDate::valid(int d, int m, int y)
{
	int v = leap(y) ? 0 : 1;
	if (m > 12 || m < 1)
	{
		return false;
	}
	if (d > daytab[v][m] || d < 1)
	{
		return false;
	}
	return true;
}

MyDate::MyDate()
{
	this->d = 0;
	this->m = 0;
	this->y = 0;
}

MyDate::MyDate(int d, int m, int y)
{
	this->d = d;
	this->m = m;
	this->y = y;
}

MyDate MyDate::operator++()
{
	MyDate d1(d, m, y);
	int v = leapyear(d1) ? 0 : 1;
	if (d == daytab[v][m])
	{
		d = 1;
		m++;
		if (m == 13)
		{
			m = 1;
			y++;
		}
		return MyDate(d, m, y);
	}
	return MyDate(++d, m, y);
}
MyDate MyDate::operator++(int)
{
	return ++ * this;
}

MyDate MyDate::operator--()
{
	MyDate d1(this->d, this->m, this->y);
	int v = leapyear(d1) ? 0 : 1;
	if (d == 1)
	{
		d = daytab[v][--m];
		if (m == 0)
		{
			y--;
			m = 12;
			d = 31;
		}
		return MyDate(d, m, y);
	}
	return MyDate(--d, m, y);
}
MyDate MyDate::operator--(int)
{
	return -- * this;
}

int leap(int year)
{
	return((year % 4 && year % 100 != 0) || (year % 400 == 0));
}
bool leapyear(MyDate dt)
{
	return leap(dt.y);
}

int MyDate::DayOfYear()
{
	int days = d;
	int lp = leap(y);
	for (int i = 1; i < m; i++)
	{
		days += daytab[lp][i];
	}
	return ++days;
}
int MyDate::NumberDayOfWeek()
{
	MyDate dti(d0, m0, y0);
	long days = dw0 - 1;
	days += 365 + leap(y0) - dti.DayOfYear();
	for (int i = y0; i < y; i++)
	{
		days += 365 + leap(i);
	}
	days += DayOfYear();
	return (days + 3) % 7;
}

void MyDate::Print()
{
	std::cout << this->d << '.' << this->m << '.' << this->y;
}

std::ostream& operator<<(std::ostream& out, const MyDate& date)
{
	out << date.d << "." << date.m << "." << date.y;
	return out;
}
std::ofstream& operator<<(std::ofstream& out, const MyDate& date)
{
	out << date.d << " " << date.m << " " << date.y;
	return out;
}
std::istream& operator>>(std::istream& in, MyDate& date)
{
	in >> date.d;
	in >> date.m;
	in >> date.y;
	return in;
}

MyDate& MyDate::operator=(const MyDate& date)
{
	this->d = date.d;
	this->m = date.m;
	this->y = date.y;
	return *this;
}

bool operator<=(const MyDate& date1, const MyDate& date2)
{
	if (date1.y > date2.y)
	{
		return false;
	}
	else if (date1.m > date2.m)
	{
		return false;
	}
	else if (date1.d > date2.d)
	{
		return false;
	}
	return true;
}
bool operator>=(const MyDate& date1, const MyDate& date2)
{
	if (date1.y < date2.y)
	{
		return false;
	}
	else if (date1.m < date2.m)
	{
		return false;
	}
	else if (date1.d < date2.d)
	{
		return false;
	}
	return true;
}
bool operator>(const MyDate& date1, const MyDate& date2)
{
	if (date1.y < date2.y)
	{
		return false;
	}
	else if (date1.m < date2.m)
	{
		return false;
	}
	else if (date1.d <= date2.d)
	{
		return false;
	}
	return true;
}
bool operator<(const MyDate& date1, const MyDate& date2)
{
	if (date1.y > date2.y)
	{
		return false;
	}
	else if (date1.m > date2.m)
	{
		return false;
	}
	else if (date1.d >= date2.d)
	{
		return false;
	}
	return true;
}

MyDate& MyDate::operator+=(const MyDate& date)
{
	MyDate d1(this->d, this->m, this->y);
	int v = leapyear(d1) ? 0 : 1;

	this->d += date.d;
	this->m += date.m;
	this->y += date.y;

	if (this->d > daytab[v][this->m])
	{
		this->d -= daytab[v][this->m++];
	}
	if (this->d > daytab[v][this->m])
	{
		this->d -= daytab[v][this->m++];
	}
	if (this->m > 12)
	{
		this->y++;
		this->m -= 12;
	}

	return *this;
}

MyDate& MyDate::operator-=(const MyDate& date)
{
	int v = leapyear(*this) ? 0 : 1;
	this->d -= date.d;
	if (this->d < 1)
	{
		this->m--;
		this->d += daytab[v][this->m];
		if (this->m < 1)
		{
			this->y--;
			this->m = 12;
		}
	}
	if (this->d < 1)
	{
		this->m;
		this->d += daytab[v][this->m];
		if (this->m < 1)
		{
			this->y--;
			this->m = 12;
		}
	}
	this->m -= date.m;
	if (this->m < 1)
	{
		this->m += 12;
		this->y--;
		if (this->d > daytab[v][this->m])
		{
			this->m++;
			this->d -= daytab[v][this->m];
		}
	}
	this->y -= date.y;
	if (this->d > daytab[v][m])
	{
		d -= daytab[v][m++];
	}
	return *this;
}

MyDate MyDate::operator+(const MyDate& date1)
{
	return *this += date1;
}

MyDate MyDate::operator+(const int days)
{
	MyDate date(this->d, this->m, this->y);
	for (int i = 0; i < days; i++)
	{
		date++;
	}
	return date;
}

MyDate MyDate::operator-(const MyDate& date1)
{
	return *this -= date1;
}

MyDate MyDate::operator-(const int days)
{
	MyDate date(this->d, this->m, this->y);
	for (int i = 0; i < days; i++)
	{
		date--;
	}
	return date;
}

bool operator==(const MyDate& date1, const MyDate& date2)
{
	if (date1.d == date2.d && date1.m == date2.m && date1.y == date2.y)
	{
		return true;
	}
	return false;
}

bool operator!=(const MyDate& date1, const MyDate& date2)
{
	return !(date1 == date2);
}