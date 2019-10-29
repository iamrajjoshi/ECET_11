//Lab 1_4
//Raj Joshi & Nishil Patel
//Written by Raj Joshi

#include <iostream>
using namespace std;

class Date {
private:
	int month;
	int day;
	int year;
public:
	Date(int m, int d, int y);
	void setMonth(int);
	int getMonth();
	void setDay(int);
	int getDay();
	void setYear(int);
	int getYear();
	void displayDate();
};

Date::Date(int m, int d, int y) {
	setMonth(m);
	setDay(d);
	setYear(y);
}

void Date::setMonth(int x) {
	if (x < 1 || x > 12)
		month = 1;
	else
		month = x;
}

int Date::getMonth() {
	return month;
}

void Date::setDay(int x) {
	day = x;
}

int Date::getDay() {
	return day;
}

void Date::setYear(int x) {
	year = x;
}

int Date::getYear() {
	return year;
}

void Date::displayDate() {
	cout << month << "/" << day << "/" << year << endl;
}

int main() {
	int d, m, y;
	cout << "Enter Day: ";
	cin >> d;
	cout << "Enter Month: ";
	cin >> m;
	cout << "Enter Year: ";
	cin >> y;
	Date date(m, d, y);
	while (true) {
		char choice;
		cout << "Would you like to e(d)it, (r)ead, or (e)xit? ";
		cin >> choice;

		switch (choice) {
		case 'd':
			system("cls");
			cout << "Enter Day: ";
			cin >> d;
			date.setDay(d);
			cout << "Enter Month: ";
			cin >> m;
			date.setMonth(m);
			cout << "Enter Year: ";
			cin >> y;
			date.setYear(y);
			break;

		case 'r':
			system("cls");
			date.displayDate();
			break;

		case 'e':
			return 0;

		default:
			cout << "Invalid input." << endl;
		}
	}
	return 0;
}