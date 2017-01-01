#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int getMaximumAppleCount(int **values, int row, int column) {
	int **result = (int **)malloc(sizeof(int*)*row);
	for (int iter = 0;iter < row;iter++) {
		result[iter] = (int *)malloc(sizeof(int)*column);
	}
	result[0][0] = values[0][0];
	for (int iter = 1;iter < column;iter++) {
		result[0][iter] = result[0][iter - 1] + values[0][iter];
	}
	for (int iter = 1;iter < row;iter++) {
		result[iter][0] = result[iter - 1][0] + values[iter][0];
	}
	for (int r = 1;r < row;r++) {
		for (int c = 1;c < column;c++) {
			result[r][c] = max(result[r - 1][c], result[r][c - 1]) + values[r][c];
		}
	}
	return result[row - 1][column - 1];
}

void main(void) {
	int t;
	cin >> t;
	while (t--) {
		int row, column;
		cin >> row >> column;
		int **values = (int **)malloc(sizeof(int*)*row);
		for (int iter = 0;iter < row;iter++) {
			values[iter] = (int *)malloc(sizeof(int)*column);
		}
		for (int r = 0;r < row;r++) {
			for (int c = 0;c < column;c++) {
				scanf("%d", &values[r][c]);
			}
		}
		int result = getMaximumAppleCount(values, row, column);
		printf("%d\n", result);
	}
}