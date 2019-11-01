//Lab 4_1
//Raj Joshi & Nishil Patel
//Written by Nishil Patel

#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>&, int, int);
void quickSort(vector<int>&, int, int);


int partition(vector<int>& us, int front, int back)
{
	int testee = us[front];
	bool dir = true; //true is starting right, moving left
	int backshifter = 0;
	int frontshifter = 0;
	bool found = false;

	int pos = front;

	while (true)
	{
		found = false;
		if (dir)
		{
			for (int i = back - backshifter; i > pos; i--)
			{
				if (us[i] < testee)
				{
					int temp = us[pos];
					us[pos] = us[i];
					us[i] = temp;
					frontshifter = pos + 1 - front;
					pos = i;
					found = true;
					break;

				}
			}

			if (!found)
				return pos;
		}
		else
		{
			for (int i = front + frontshifter; i < pos; i++)
			{
				if (us[i] > testee)
				{
					int temp = us[pos];
					us[pos] = us[i];
					us[i] = temp;
					backshifter = back - pos + 1;
					pos = i;
					found = true;
					break;

				}
			}

			if (!found)
				return pos;
		}

		dir = !dir;

	}



}



void quickSort(vector<int>& unsort, int front, int back)
{
	if (back > front)
	{
		//cout << front << ' ' << back << endl;
		int ind = partition(unsort, front, back);
		quickSort(unsort, front, ind - 1);
		quickSort(unsort, ind + 1, back);

	}




}
int main()
{
	while (true)
	{
		vector<int> test;

		cout << "Welcome to QuickSorter\n\n";
		cout << "How many numbers would you like to sort: ";
		int size;
		cin >> size;
		for (int i = 0; i < size; i++)
		{
			int temp;
			system("cls");
			cout << i + 1 << ") Enter A Number (enter seperately): ";

			cin >> temp;
			test.push_back(temp);

			if (test.size() > size)
			{
				cout << "Entry Complete\n\n";
				break;
			}
		}
		system("cls");
		cout << "Original Sequence:\n";
		for (int i = 0; i < test.size(); i++)
		{
			cout << test.at(i) << " ";
		}
		cout << "\n\nQuickSorted Sequence:\n";
		quickSort(test, 0, test.size() - 1);
		cout << endl;
		for (int i = 0; i < test.size(); i++)
		{
			cout << test.at(i) << " ";
		}
		cout << endl;
		system("pause");
		system("cls");

		}

	return 0;
	}