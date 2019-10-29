#include <iostream>
#include <vector>
#include<time.h> 
using namespace std;

int roll() {
	
	return rand()%6 + 1;
}

int main() {
	srand(time(0));
	vector<int> sum;
	sum.assign(13, 0);
	int dice1, dice2;
	for (int i = 0; i < 36000; i++) {
		dice1 = roll();
		dice2 = roll();
		sum[dice1 + dice2]++;
	}
	cout << "Dice Simulation Results" << endl << endl;
	cout << "Sum     Frequency" << endl;
	cout << " 2" << "         " << sum[2] << endl;
	cout << " 3" << "         " << sum[3] << endl;
	cout << " 4" << "         " << sum[4] << endl;
	cout << " 5" << "         " << sum[5] << endl;
	cout << " 6" << "         " << sum[6] << endl;
	cout << " 7" << "         " << sum[7] << endl;
	cout << " 8" << "         " << sum[8] << endl;
	cout << " 9" << "         " << sum[9] << endl;
	cout << " 10" << "        " << sum[10] << endl;
	cout << " 11" << "        " << sum[11] << endl;
	cout << " 12" << "        " << sum[12] << endl;
	return 1;
}