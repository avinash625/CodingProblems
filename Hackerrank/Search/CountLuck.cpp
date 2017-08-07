#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string.h>
#include<stdlib.h>

using namespace std;
bool isValid(int x, int y, int n, int m) {
	if ((x < 0 || x >= n) || y < 0|| y>=m)
		return false;
	return true;
}
void printMatrix(char **matrix, int n, int m) {
	for (int row = 0;row < n;row++) {
		for (int col = 0;col < m;col++) {
			cout << matrix[row][col] << " ";
		}
		cout << endl;
	}
}
void DFS(char **matrix, int n, int m, int startx, int starty, int endx, int endy, bool *guess, int currentGuess, int k) {
	int xValue[] = { 0,1,0,-1 };
	int yValue[] = { -1,0,1,0 };
	if (startx == endx && starty == endy) {
		if (currentGuess == k) {
			*guess = true;
			return;
		}
		
	}
	int count = 0;
	for (int iter = 0;iter< 4;iter++) {
		if (isValid(startx + xValue[iter], starty + yValue[iter], n, m) && (matrix[startx + xValue[iter]][starty + yValue[iter]] == '.'|| matrix[startx + xValue[iter]][starty + yValue[iter]] == '*'))
			count++;
	}
	for (int iter = 0;iter < 4;iter++) {
		if (count >1)
			currentGuess++;
		if (isValid(startx + xValue[iter], starty + yValue[iter], n, m) && (matrix[startx + xValue[iter]][starty + yValue[iter]] == '.' || matrix[startx + xValue[iter]][starty + yValue[iter]] == '*')) {
			matrix[startx + xValue[iter]][starty + yValue[iter]] = '#';
			DFS(matrix, n, m, startx + xValue[iter], starty + yValue[iter], endx, endy, guess, currentGuess, k);
			matrix[startx + xValue[iter]][starty + yValue[iter]] = '.';
		}
		if (count > 1)
			currentGuess--;
	}

}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		int startx, starty, endx, endy;
		cin >> n >> m;
		char **matrix = (char **)malloc(sizeof(char*)*(n));
		for (int iter = 0;iter< n;iter++) {
			(matrix[iter]) = (char *)malloc(sizeof(char)*(m + 1));
			cin >> matrix[iter];
			//cout << matrix[iter];
			for (int iter1 = 0;iter1 < m;iter1++) {
				if (matrix[iter][iter1] == 'M') {
					startx = iter;
					starty = iter1;
				}
				else if (matrix[iter][iter1] == '*') {
					endx = iter;
					endy = iter1;
				}
			}

		}
		int k;
		cin >> k;
		//cout << "starting :::: " << startx << " " << starty << endl;
		//cout << "ending :::: " << endx << " " << endy << endl;
		bool guess = false;
		DFS(matrix, n, m, startx, starty, endx, endy, &guess, 0, k);
		if (!guess) {
			cout << "Oops!" << endl;
		}
		else
			cout << "Impressed" << endl;
	}
	return 0;
}
