//Lab 1_1
//Raj Joshi & Nishil Patel
//Written by Raj Joshi

#include<iostream>
using namespace std;

class Account {
private:
	double balance;

public:
	Account(double);
	double getBalance();
	void credit(double);
	void debit(double);
};

double Account::getBalance() {
	return balance;
}

Account::Account(double balance) {
	if (balance >= 0)
		this->balance = balance;
	else {
		this->balance = 0;
		cout << "Account created with insufficient funds" << endl;
	}
}

void Account::credit(double amount) {
	if (amount >= 0)
		balance += amount;
	else 
		cout << "Credited amount cannot be negative" << endl;
}

void Account::debit(double amount) {
	if (amount <= balance && amount >= 0)
		balance -= amount;
	else 
		cout << "Debit amount exceeded account balance or is negative" << endl;
}


int main() {
	double amount;
	cout << "Enter account initial balance: ";
	cin >> amount;
	
	Account acc(amount);
	
	while (true) {
		char choice;
		cout << "Currenct balance is " << acc.getBalance() << endl;
		cout << "Would you like to (c)reate a new account, (a)dd money, or (w)ithdraw money or (e)xit? ";
		cin >> choice;
		
		switch (choice) {
		case 'c':
			system("cls");
			cout << "Enter initial account balance: ";
			cin >> amount;
			acc = Account(amount);
			break;

		case 'a':
			cout << "How much would you like to add? ";
			cin >> amount;
			acc.credit(amount);
			break;

		case 'w':
			cout << "How much would you like to withdraw? ";
			cin >> amount;
			acc.debit(amount);
			break;

		case 'e':
			return 0;

		default:
			cout << "Invalid input." << endl;
		}
	}
	return 0;
}