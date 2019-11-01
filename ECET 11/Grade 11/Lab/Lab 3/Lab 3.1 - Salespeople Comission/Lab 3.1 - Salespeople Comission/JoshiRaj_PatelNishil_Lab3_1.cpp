//Lab 3_1
//Raj Joshi & Nishil Patel
//Written by Raj Joshi

#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector <int> counter;
	double amount;
	counter.assign(9, 0);
	while (true) {
		cout << "Enter Salesperson gross sales: (-1 to quit): ";
		cin >> amount;
		if (amount == -1)
			break;
		else {
			amount *= 0.09;
			amount += 200;
			amount = int(amount);
			
			if (amount >= 200 && amount <= 299)
				counter[0]++;
			else if (amount >= 300 && amount <= 399)
				counter[1]++;
			else if (amount >= 400 && amount <= 499)
				counter[2]++;
			else if (amount >= 500 && amount <= 599)
				counter[3]++;
			else if (amount >= 600 && amount <= 699)
				counter[4]++;
			else if (amount >= 700 && amount <= 799)
				counter[5]++;
			else if (amount >= 800 && amount <= 899)
				counter[6]++;
			else if (amount >= 900 && amount <= 999)
				counter[7]++;
			else
				counter[8]++;
		}
			
	}
	system("cls");
	cout << "\n\n\nSalesperson Salaries" << endl;
	cout << "$200 - $299:  " << counter[0] << endl;
	cout << "$300 - $399:  " << counter[1] << endl;
	cout << "$400 - $499:  " << counter[2] << endl;
	cout << "$500 - $599:  " << counter[3] << endl;
	cout << "$600 - $699:  " << counter[4] << endl;
	cout << "$700 - $799:  " << counter[5] << endl;
	cout << "$800 - $899:  " << counter[6] << endl;
	cout << "$900 - $999:  " << counter[7] << endl;
	cout << "$1000 - over: " << counter[8] << endl;
	return 0;
	
}