//Lab 1_3
//Raj Joshi & Nishil Patel
//Written by Raj Joshi

#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
	string firstName;
	string lastName;
	int salary;
public:
	Employee(string f, string l, int s);
	void setFirstName(string f);
	string getFirstName();
	void setLastName(string l);
	string getLastName();
	void setSalary(int x);
	int getSalary();
};

Employee::Employee(string f, string l, int s) {
	this->firstName = f;
	this->lastName = l;
	this->salary = s;
}

void Employee::setFirstName(string f) {
	this->firstName = f;
	return;
}

string Employee::getFirstName() {
	return this->firstName;
}

void Employee::setLastName(string l) {
	this->lastName = l;
	return;
}

string Employee::getLastName() {
	return this->lastName;
}

void Employee::setSalary(int s) {
	if (s >= 0)
		this->salary = s;
	else
		this->salary = 0;
}

int Employee::getSalary() {
	return this->salary;
}

int main() {
	string f, l;
	int s;
	cout << "Enter first name: ";
	cin >> f;
	cout << "Enter last name: ";
	cin >> l;
	cout << "Enter salary: ";
	cin >> s;
	Employee e(f,l,s);
	while (true) {
		char choice;
		cout << "Would you like to e(d)it, (r)ead, or (e)xit? ";
		cin >> choice;

		switch (choice) {
		case 'd':
			system("cls");
			cout << "Enter first name: ";
			cin >> f;
			e.setFirstName(f);
			cout << "Enter last name: ";
			cin >> l;
			e.setLastName(l);
			cout << "Enter salary: ";
			cin >> s;
			e.setSalary(s);
			break;

		case 'r':
			system("cls");
			cout << "First name: " << e.getFirstName() << endl;
			cout << "Last name: " << e.getLastName() << endl;
			cout << "Salary: " << e.getSalary() << endl;
			break;

		case 'e':
			return 0;

		default:
			cout << "Invalid input." << endl;
		}
	}

	return 0;
}