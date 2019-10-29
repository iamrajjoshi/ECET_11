#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<bool> isUnique;
	isUnique.assign(100, 0);
	int choice;
	while (true) {
		cout << "Enter a number 0 to 100 (-1 to quit): ";
		cin >> choice;
		if (choice == -1)
			break;
		isUnique[choice] = true;
	}
	cout << "\n\n\nUnique Numbers: ";
	for (int i = 0; i < 100; i++) {
		if (isUnique[i] == true)
			cout << i << ", ";
	}
	cout << endl;

	return 1;
}