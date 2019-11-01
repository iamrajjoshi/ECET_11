//Lab 4_3
//Raj Joshi & Nishil Patel
//Written by Raj Joshi

#include<iostream>
#include<string>
using namespace std;

int main() {

	string ones[] = { "", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
	string een[] = { "TEN" , "ELEVEN", "TWELVE", "THIRTEEN", "FOURTEEN", "FIFTEEN", "SIXTEEN", "SEVENTEEN", "EIGHTEEN", "NINETEEN" };
	string t[] = { "TWENTY" , "THIRTY", "FORTY", "FIFTY", "SIXTY", "SEVENTY", "EIGHTY", "NINETY" };

	while (true) {
		double a;
		cout << "Enter amount: $";
		cin >> a;

		if (a >= 1000 || a <= 0)
			cout << "Invalid amount! Please enter an a less than $1000." << endl;
		else {

			int hundred = int(a) / 100;
			int ten = (int(a) / 10) % 10;
			int one = int(a) % 10;
			int cent = int(round(a * 100)) % 100;

			if (hundred != 0) {
				cout << ones[hundred] + " HUNDRED";
				if (ten != 0 || one != 0)
					cout << " ";
			}
			if (ten == 1)
				cout << een[one];
			else {
				if (ten > 1) {
					cout << t[ten - 2];
					if (one != 0)
						cout << " ";
				}
				cout << ones[one];
			}
			if ((hundred + ten + one) != 0)
				cout << " and ";
			cout << cent << "/100" << endl;
		}
	}
	return 0;
}