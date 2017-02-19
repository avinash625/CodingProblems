#include<iostream>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
int getMax1Row(int **values, int row, int column){
	int result = 0;
	int rowIter = 0;
	int maxOnes = column - 1;
	while (rowIter < row){
		if (values[rowIter][maxOnes]){
			while (maxOnes >= 0){
				if (values[rowIter][maxOnes]){
					maxOnes--;
				}
				else{
					result = rowIter;
					rowIter++;
					break;
				}
			}if (maxOnes == -1)
				return rowIter;
		}
		else
			rowIter++;
	}
	return result;
}

int main()
{
	int t;
	cin >> t;
	while (t--){
		int row, column;
		cin >> row >> column;
		int **values = (int **)malloc(sizeof(int *)*row);
		for (int iter = 0; iter<row; iter++)
			values[iter] = (int *)malloc(sizeof(int)*column);
		for (int r = 0; r<row; r++){
			for (int c = 0; c< column; c++){
				scanf("%d", &values[r][c]);
			}
		}
		cout << getMax1Row(values, row, column) << endl;
	}
	return 0;
}