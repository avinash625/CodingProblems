#include<iostream>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
int getLCSlength(char *input1, char *input2, int len1, int len2) {
	int** result;
	result = (int **)malloc(sizeof(int*)*(len1 + 1));
	for (int iter = 0;iter < len1 + 1;iter++) {
		result[iter] = (int *)malloc(sizeof(int)*(len2 + 1));
	}
	for (int iter = 0;iter<len1 + 1;iter++) {
		if (iter == 0) {
			for (int i = 0;i < len2 + 1;i++)
				result[iter][i] = 0;
		}
		else
			result[iter][0] = 0;
	}
	for (int iter = 0;iter<len1 + 1;iter++) {
		for (int i = 0; i < len2 + 1;i++) {
			cout << result[iter][i] << " ";
		}
		cout << endl;
	}
	for (int first = 1;first < len1 + 1;first++) {
		for (int second = 1;second < len2 + 1;second++) {
			if (input1[first - 1] == input2[second - 1])
				result[first][second] = result[first - 1][second - 1]+1;
			else
				result[first][second] = max(result[first - 1][second], result[first][second - 1]);
		}
	}
	for (int iter = 0;iter<len1 + 1;iter++) {
		for (int i = 0; i < len2 + 1;i++) {
			cout << result[iter][i] << " ";
		}
		cout << endl;
	}
	return result[len1][len2];
}
int main()
{
	int t;
	cin >> t;
	while (t--) {
		int len1, len2;
		cin >> len1 >> len2;
		char input[101], input1[101];
		cin >> input >> input1;
		cout << getLCSlength(input, input1, len1, len2) << endl;
	}
	return 0;
}