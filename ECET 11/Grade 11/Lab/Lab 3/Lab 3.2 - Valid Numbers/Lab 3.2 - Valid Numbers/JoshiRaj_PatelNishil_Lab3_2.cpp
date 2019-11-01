//Lab 3_2
//Raj Joshi & Nishil Patel
//Written by Raj Joshi

#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<bool> isUnique;
	isUnique.assign(101, 0);
	int choice;
	while (true) {
		cout << "Enter a number 0 to 100 (-1 to quit): ";
		cin >> choice;
		if (choice == -1)
			break;
		isUnique[choice] = true;
	}
	cout << "\n\n\nUnique Numbers: ";
	for (int i = 0; i < 101; i++) {
		if (isUnique[i] == true)
			if (i != 100)
				cout << i << ", ";
			else
				cout << i;
	}
	cout << endl;

	return 0;
}