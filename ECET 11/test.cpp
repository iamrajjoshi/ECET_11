#include <iostream>
#include<string>
#include<Windows.h>
#include <iomanip>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

class MonkeyEatReport {
private:
	float food[3][7];
public:
	void setMonkeyData(float food[][7]);
	void dispTotalEaten();
	void dispAvgWeekly();
	void dispAvgDaily();
	void dispLeastEaten();
	void dispMostEaten();
};

void printFloat(float num) {
	if (int(num) == num)
		cout << fixed << setprecision(0) << num;
	else cout << fixed << setprecision(2) << num;
	cout << fixed << setprecision(0);
}

void MonkeyEatReport::setMonkeyData(float food[][7]) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 7; j++)
			this->food[i][j] = food[i][j];
}

void MonkeyEatReport::dispTotalEaten() {
	cout << "Total food eaten for the week:\n";
	for (int i = 0; i < 3; i++) {
		float totalFood = 0;
		for (int j = 0; j < 7; j++)
			totalFood += food[i][j];
		cout << "Monkey " << i + 1 << " total food intake: ";
		printFloat(totalFood);
		cout << " lbs" << endl;
	}
	cout << endl;
}

void MonkeyEatReport::dispAvgWeekly() {
	cout << "Average food eaten for the week:\n";
	for (int i = 0; i < 3; i++) {
		float totalFood = 0;
		for (int j = 0; j < 7; j++)
			totalFood += food[i][j];
		cout << "Monkey " << i + 1 << " average food intake: ";
		printFloat(totalFood / 7.0);
		cout << " lbs" << endl;

	}
	cout << endl;
}



void MonkeyEatReport::dispAvgDaily() {
	cout << "The average amount eaten by the three monkeys:\n";
	for (int i = 0; i < 7; i++) {
		float totalFood = 0;
		for (int j = 0; j < 3; j++)
			totalFood += food[j][i];
		cout << "The average amount eaten on day " << i + 1 << " is: ";
		printFloat(totalFood / 3.0);
		cout << " lbs" << endl;
	}
	cout << endl;
}

string numToDay(int day) {
	switch (day) {
	case 1:
		return "Monday";
	case 2:
		return "Tuesday";
	case 3:
		return "Wednesday";
	case 4:
		return "Thursday";
	case 5:
		return "Friday";
	case 6:
		return "Saturday";
	case 7:
		return "Sunday";
	}
}

void MonkeyEatReport::dispLeastEaten() {
	float leastEaten = pow(2, 31) - 1;
	float monkeyNumLeastEaten;
	int dayLeastEaten;
	cout << "Least amount of food eaten:\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 7; j++) {
			float oldLeastEaten = leastEaten;
			leastEaten = min(leastEaten, food[i][j]);
			if (leastEaten != oldLeastEaten) {
				monkeyNumLeastEaten = i + 1;
				dayLeastEaten = j + 1;
			}
		}

	}
	cout << "Monkey " << monkeyNumLeastEaten << " ate the least amount of food of ";
	printFloat(leastEaten);
	cout << " lbs on " << numToDay(dayLeastEaten) << endl;
	cout << endl;
}

void MonkeyEatReport::dispMostEaten() {
	float mostEaten = 0;
	float monkeyNumMostEaten;
	int dayMostEaten;
	cout << "Most amount of food eaten:\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 7; j++) {
			float oldMostEaten = mostEaten;
			mostEaten = max(mostEaten, food[i][j]);
			if (mostEaten != oldMostEaten) {
				monkeyNumMostEaten = i + 1;
				dayMostEaten = j + 1;
			}
		}

	}
	cout << "Monkey " << monkeyNumMostEaten << " ate the most amount of food of ";
	printFloat(mostEaten);
	cout << " lbs on " << numToDay(dayMostEaten) << endl;
}




int main() {

	float food[3][7];
	float input;
	cout << "Enter lbs of food for each monkey for the 7 days on one line starting with Monday's value (i.e. M Tu W Th F Sa Su):\n";

	for (int i = 0; i < 3; i++) {
		cout << "Enter pounds of food for monkey " << i + 1 << " (day 1 - day 7): ";
		for (int j = 0; j < 7; j++) {
			cin >> input;
			food[i][j] = input;
		}
	}

	MonkeyEatReport report;
	report.setMonkeyData(food);

	cout << "\n\t\tMonkey Eating Habit Report\n\n";

	report.dispTotalEaten();
	report.dispAvgWeekly();
	report.dispAvgDaily();
	report.dispLeastEaten();
	report.dispMostEaten();

	return 0;
}