#include<iostream>
#include<cstdint>
#include<stdlib.h>
#include<limits.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string.h>
#include<deque>
using namespace std;

void getNextPalindrome(char *input) {
	int len = strlen(input);
	int left, right,middle;
	if (len & 1) {
		left = (len / 2) - 1;
		right = left + 2;
		middle = (len / 2);
	}
	else {
		left = (len / 2) - 1;
		right = left + 1;
		middle = (len / 2)-1;
	} 
	while (left >= 0 && right < len) {
		if (input[left] == input[right]) {
			left--;
			right++;
			continue;
		}
		else if (input[left] < input[right]) {
			if ((len&1) == 0) {
				input[middle + 1] = ((input[middle + 1] - '0' + 1) % 10) + '0';
			}
			int carry = ((input[middle] - '0' + 1)/ 10) ;
			input[middle] = ((input[middle] - '0' + 1) % 10) + '0';
			for (left = middle - 1;left >= 0 && carry;left--) {
				carry = ((input[left] - '0' + 1) / 10);
				input[left] = ((input[left] - '0' + 1) % 10) + '0';
			}
			for (int iter = 0;iter <= len / 2;iter++) {
				input[len - iter - 1] = input[iter];
			}
			cout << input << endl;
			return;
		}
		else if (input[left] > input[right]) {
			for (int iter = 0;iter <= len / 2;iter++) {
				input[len - iter - 1] = input[iter];
			}
			cout << input << endl;
			return;
		}
	}
	if (left == -1) {
		int carry = ((input[middle] - '0' + 1) / 10);
		input[middle] = ((input[middle] - '0' + 1) % 10) + '0';
		for (left = middle - 1;left >= 0 && carry ;left--) {
			carry = (input[left] - '0' + 1) / 10;
			input[left] = ((input[left] - '0' + 1) % 10) + '0';
		}
		if (!carry) {
			for (int iter = 0;iter < len / 2;iter++) {
				input[len - iter - 1] = input[iter];
			}
			cout << input << endl;
			return;
		}
		else {
			for (int iter = 0;iter < len / 2;iter++) {
				input[len - iter - 1] = input[iter];
			}
			input[len - 1] = '1';
			cout << 1 << input << endl;
			return;
		}
	}
}
int main(void) {
	int t;
	cin >> t;
	char input[1000001];
	while (t--) {
		cin >> input;
		getNextPalindrome(input);
	}
	return 0;
}