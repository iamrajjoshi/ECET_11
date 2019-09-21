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
		cout << "Account balance cannot be initially negative" << endl;
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
		cout << "Debit amount exceeded account balance or is negative." << endl;
}


int main() {
	double amount;
	cout << "Enter account initial balance: ";
	cin >> amount;
	
	Account acc(amount);
	
	while (true) {
		char choice;
		cout << endl << "Currenct balance is " << acc.getBalance() << endl;
		cout << "Would you like to (c)reate a new account, (a)dd money, (w)ithdraw money, or (e)xit? ";
		cin >> choice;
		
		switch (choice) {
		case 'a':
			cout << "How much would you like to add?" << endl;
			cin >> amount;
			acc.credit(amount);
			break;

		case 'w':
			cout << "How much would you like to withdraw?" << endl;
			cin >> amount;
			acc.debit(amount);
			break;

		case 'e':
			return 0;
			break;

		case 'c':
			cout << "Enter initial account balance: ";
			cin >> amount;
			acc = Account(amount);
			break;

		default:
			cout << "Invalid input." << endl;
		}

	}

	return 0;
}