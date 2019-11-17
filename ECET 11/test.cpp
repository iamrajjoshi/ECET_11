// EX4
#pragma warning(disable : 4996)
#include <iostream>
#include <string>
using namespace std;

class Date
{
private:
	int month;
	int day;
	int year;

public:
	Date();
	Date operator++(int);
	Date(int, int, int);
	Date operator() (int, int, int);
	void show();
};

Date::Date() {
	month = 1;
	day = 1;
	year = 2000;
}

Date::Date(int x, int y, int z) {
		month = x;
		day = x;
		year = x;
}
Date Date::operator()(int m, int d, int y) {
	Date date;
	date.month = month + m;
	date.day = day + d;
	date.year = year + y;
	return date;
}

void Date::show() {
	cout << month << '/' << day << '/' << year << endl;
}

Date Date::operator++(int)
{
	this->day = 69;
	Date temp = *this;
	return temp;
}
Date Date::operator++(int)
{
	Date temp = *this;
	this->day = 69;
	return temp;
}

int main()
{
	
	Date date1, date2;

	//cout << "Enter three numbers separated by a space: ";
	

	Date date3(1, 1, 1);
	//  date2 = date1.operator()(d,m,y);
	//  OR
	date2 = date3++;
	date2.show();
	//char x[] = "goodbye";
	//char y[] = "good morning";
	//char* a = &x[0];
	//char* b = y;
	//strncpy(y, a,6);
	//cout << y << endl;
	//
	//
	////x = & y;
	//cout << "x" << typeid(x).name() << "Y" << typeid(y).name();
	//cout << &*x;
	return 0;
}
