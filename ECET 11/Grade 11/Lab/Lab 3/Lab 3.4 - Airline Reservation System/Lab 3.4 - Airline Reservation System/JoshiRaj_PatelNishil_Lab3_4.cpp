//Lab 3_4
//Raj Joshi & Nishil Patel
//Written by Raj Joshi

#include <iostream>
#include <vector>
using namespace std;
void economy(vector<bool>&, int);
void first(vector<bool>&, int);

vector<bool> chart;

int main() {

	int x, fmax;
	cout << "Enter the total seats of the plane: ";
	cin >> x;
	fmax = x / 5;
	chart.assign(x, 0);
	while (true) {
		int a = -1;
		cout << "Please type 1 for \"First Class\"" << endl;
		cout << "Please type 2 for \"Economy\"" << endl;
		cout << "Please type 3 to exit program" << endl;
		cin >> x;
		if (x == 1) {
			first(chart, fmax);
		}
		else if (x == 2) {
			economy(chart, fmax);
		}
		else if (x == 3) {
			return 1;
		}

	}
	return 1;
}

void economy(vector<bool>& chart, int fmax) {
	int a = -1;
	for (int i = fmax; i < chart.size(); i++) {
		if (chart[i] == false) {
			a = i + 1;
			chart[i] = true;
			break;
		}
	}
	if (a == -1) {
		char ch;
		cout << "All seats in Economy full, would you like to be accomodated in First Class? (y or n): ";
		cin >> ch;
		if (ch == 'y')
			first(chart, fmax);
		else
			cout << "Next Flight leaves in 3 hours" << endl;
		return;
	}
	system("cls");
	cout << "Boarding Pass" << endl;
	cout << "Seat Number: " << a << endl;
	cout << "Class: Economy\n\n" << endl;
	return;
}
void first(vector<bool>& chart, int fmax) {
	int a = -1;
	for (int i = 0; i < fmax; i++) {
		if (chart[i] == false) {
			a = i + 1;
			chart[i] = true;
			break;
		}
	}
	if (a == -1) {
		char ch;
		cout << "All seats in First Class full, would you like to be accomodated in Economy? (y or n): ";
		cin >> ch;
		if (ch == 'y')
			economy(chart, fmax);
		else
			cout << "Next Flight leaves in 3 hours" << endl;
		return;
	}
	system("cls");
	cout << "Boarding Pass" << endl;
	cout << "Seat Number: " << a << endl;
	cout << "Class: First Class\n\n" << endl;
	return;
}
