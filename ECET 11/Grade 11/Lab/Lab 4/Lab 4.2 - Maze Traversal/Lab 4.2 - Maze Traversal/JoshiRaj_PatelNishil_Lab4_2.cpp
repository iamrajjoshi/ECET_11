//Lab 4_2
//Raj Joshi & Nishil Patel
//Written by Raj Joshi

#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

void displayMaze(vector<vector<char> > maze) {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++)
			cout << maze[i][j] << " ";
		cout << endl;
	}
}

bool traverseMaze(vector<vector<char> >& maze, int r, int c, int tr, int tc) {
	if (r >= 12 || c >= 12)
		return false;
	if (r == tr && c == tc) {
		maze[r][c] = 'O';
		return true;
	}
	if (maze[r][c] == '#')
		return false;
	if (maze[r][c] == 'O')
		return false;

	maze[r][c] = 'O';

	system("cls");
	displayMaze(maze);
	//system("pause");
	Sleep(500);
	if (traverseMaze(maze, r - 1, c, tr, tc) == true)//N
		return true;
	if (traverseMaze(maze, r, c + 1, tr, tc) == true)//E
		return true;
	if (traverseMaze(maze, r + 1, c, tr, tc) == true)//S
		return true;
	if (traverseMaze(maze, r, c - 1, tr, tc) == true)//W
		return true;
	maze[r][c] = '.';
	return false;
}

int main() {
	vector<vector<char> > maze;
	int r = -1, c = -1, tr = -1, tc = -1;
	while (true) {
		maze.clear();
		cout << "Please input a 12 by 12 maze with '#' as walls and '.' as an acceptable path to solve." << endl;

		for (int i = 0; i < 12; i++) {
			vector<char> eachrow;
			for (int j = 0; j < 12; j++) {
				char in;
				cin >> in;
				eachrow.push_back(in);
			}
			maze.push_back(eachrow);
		}

		for (int i = 0; i < 12; i++) {
			if (maze[0][i] == '.') {
				r = 0;
				c = i;
				break;
			}
			else if (maze[11][i] == '.') {
				r = 11;
				c = i;
				break;
			}
			else if (maze[i][0] == '.') {
				r = i;
				c = 0;
				break;
			}
			else if (maze[i][11] == '.') {
				r = i;
				c = 11;
				break;
			}
		}
		maze[r][c] = ' ';

		for (int i = 0; i < 12; i++) {
			if (maze[0][i] == '.') {
				tr = 0;
				tc = i;
				break;
			}
			else if (maze[11][i] == '.') {
				tr = 11;
				tc = i;
				break;
			}
			else if (maze[i][0] == '.') {
				tr = i;
				tc = 0;
				break;
			}
			else if (maze[i][11] == '.') {
				tr = i;
				tc = 11;
				break;
			}
		}
		maze[r][c] = '.';

		traverseMaze(maze, r, c, tr, tc);
		system("cls");
		displayMaze(maze);
		cout << endl << "Maze has been solved!" << endl;
	}
	return 0;
}
