/*Given a N X N matrix (M) filled with 1 , 0 , 2 , 3 . Your task is to find whether there is a path possible from source to destination, while traversing through blank cells only. You can traverse up, down, right and left.

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Blank Wall.
Note : there is only single source and single destination.*/


#include<iostream>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
int isPathExist(int **maze, int n, int sR, int sC, int dR, int dC){
	int x[] = { 0, -1, 0, 1 };
	int y[] = { -1, 0, 1, 0 };
	int modifiedX, modifiedY;
	if (sR == dR && sC == dC)
		return true;
	for (int iter = 0; iter<4; iter++){
		modifiedX = sR + x[iter];
		modifiedY = sC + y[iter];
		maze[sR][sC] = 0;
		if ((modifiedX >= 0 && modifiedX <n && modifiedY >= 0 && modifiedY< n) && (maze[modifiedX][modifiedY] == 3 || maze[modifiedX][modifiedY] == 2)){
			if (isPathExist(maze, n, modifiedX, modifiedY, dR, dC))
				return true;
		}
		maze[sR][sC] = 3;
	}
	return false;
}
int main()
{
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int sourceRow, sourceCol, destRow, destCol;
		int **maze = (int **)malloc(sizeof(int*)*n);
		for (int iter = 0; iter< n; iter++){
			maze[iter] = (int *)malloc(sizeof(int)*n);
		}
		for (int row = 0; row<n; row++){
			for (int col = 0; col<n; col++){
				scanf("%d", &maze[row][col]);
				if (maze[row][col] == 1){
					sourceRow = row;
					sourceCol = col;
				}
				else if (maze[row][col] == 2){
					destRow = row;
					destCol = col;
				}
			}
		}
		if (isPathExist(maze, n, sourceRow, sourceCol, destRow, destCol)){
			cout << 1 << endl;
		}
		else
			cout << 0 << endl;
	}
	return 0;
}