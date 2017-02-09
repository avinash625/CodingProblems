#include<iostream>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;
int getMinimumJumps(int *values, int n){
	int *result = (int *)malloc(sizeof(int)*n);
	for (int iter = 0; iter<n; iter++)
		result[iter] = INT_MAX;
	result[0] = 0;
	if (values[0] == 0)
		return -1;
	for (int iter = 1; iter<n; iter++){
		for (int start = 0; start <iter; start++){
			if (start + values[start] >= iter){
				result[iter] = min(result[start] + 1, result[iter]);
			}
		}
	}
	for (int iter = 0; iter<n; iter++)
		cout << result[iter] << " ";
	return result[n - 1];
}
int main()
{
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int *values = (int *)malloc(sizeof(int)*n);
		for (int iter = 0; iter<n; iter++){
			scanf("%d", &values[iter]);
		}
		cout << getMinimumJumps(values, n) << endl;
	}
	cin >> t;
	return 0;
}