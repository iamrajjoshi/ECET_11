#include<iostream>
#include<vector>
using namespace std;

void getPrimeList(int n) {
	vector<bool> a;
	a.assign(n, true);

	for (int i = 2; i < a.size(); i ++) {
		if (a[i]) {
			for (int j = i*2; j < a.size(); j += i)
				a[j] = false;
		}
	}
	cout << "Primes: ";
		for (int i = 0; i < a.size(); i++)
			if (a[i])
				cout << i << " ";
	return;

}

int main() {


	int input;
	while (true) {
		cout << "Enter the size of vector to use: ";
		cin >> input;

		getPrimeList(input);

	}	
	return 0;
}