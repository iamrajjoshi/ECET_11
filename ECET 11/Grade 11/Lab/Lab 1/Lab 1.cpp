#include <iostream>

using namespace std;

class Account {

private:
	int balance;

public:
	Account(int input) {
		if (input >= 0)
			balance = input;
		else {
			cout << "The input amount is invalid! " << endl;
			balance = 0;
		}
	}

