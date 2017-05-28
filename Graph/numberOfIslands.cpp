#include <cmath>
#include <cstdio>
#include<stdlib.h>
#include<cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void DFS(char **matrix, int r, int c, int row, int col, bool **visited) {
	int x[] = { -1,0,1,0,-1,1,1,-1 };
	int y[] = { 0,-1,0,1,-1,-1,1,1 };

	for (int neighbours = 0;neighbours < 8; neighbours++) {
		if ((r + x[neighbours] >= 0 && r + x[neighbours]<row) && (c + y[neighbours] >= 0 && c + y[neighbours]<col) && (matrix[r + x[neighbours]][c + y[neighbours]] == '1') && (!visited[r + x[neighbours]][c + y[neighbours]])) {
			visited[r + x[neighbours]][c + y[neighbours]] = true;
			DFS(matrix, r + x[neighbours], c + y[neighbours], row, col, visited);
		}
	}
}

int getNumberOfIslands(char **matrix, int row, int col) {
	int islands = 0;
	bool **visited = (bool **)malloc(sizeof(bool *)*row);
	for (int iter = 0;iter<row;iter++) {
		visited[iter] = (bool *)malloc(sizeof(bool)*col);
		for (int cell = 0;cell < col;cell++) {
			visited[iter][cell] = false;
		}
	}
	for (int r = 0;r<row;r++) {
		for (int c = 0;c<col;c++) {
			if (matrix[r][c] == '1' && !visited[r][c]) {
				visited[r][c] = true;
				DFS(matrix, r, c, row, col, visited);
				islands++;
			}
		}
	}
	return islands;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int r, c;
		cin >> r >> c;
		char **matrix = (char **)malloc(sizeof(char*)*r);
		for (int iter = 0;iter<r;iter++) {
			matrix[iter] = (char *)malloc(sizeof(char)*(c+1));
		}
		for (int row = 0;row<r;row++) {
			cin >> matrix[row];
		}
		int islands = getNumberOfIslands(matrix, r, c);
		cout << islands << endl;
	}
	return 0;
}
