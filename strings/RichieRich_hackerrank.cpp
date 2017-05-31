#include<iostream>
#include<vector>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main(void) {
	int n, k;
	cin >> n >> k;
	char *input = (char *)malloc(sizeof(char)*n);
	cin >> input;
	int len = n;
	if (k >= n) {
		for (int iter = 0;input[iter];iter++)
			input[iter] = '9';
	}
	else {
		int edits = 0;
		for (int iter = 0;iter < len / 2;iter++) {
			if (input[len - iter - 1] != input[iter])
				edits++;
		}
		if (edits > k) {
			cout << -1 << endl;
			return 0;
		}
		else if (edits == k) {
			for (int iter = 0;iter < len / 2;iter++) {
				if (input[len - iter - 1] > input[iter]) {
					input[iter] = input[len - iter - 1];
				}
				else {
					input[len - iter - 1] = input[iter];
				}
			}
		}
		else if (edits == 0) {
			for (int iter = 0;iter < len / 2 && k>1;iter++) {
				if (input[iter] != '9') {
					input[len - iter - 1] = '9';
					input[iter] = '9';
					k -= 2;
				}
			}
			if (k == 1 && n % 2 == 1) {
				input[len / 2] = '9';
			}
		}
		else {
			bool *edited = (bool *)malloc(sizeof(bool)*n);
			for (int iter = 0;iter < n;iter++)
				edited[iter] = false;
			for (int iter = 0;iter < len/2;iter++) {
				if (input[len - iter - 1] != input[iter]) {
					edited[len - iter - 1] = true;
					if (input[len - iter - 1] > input[iter]) {
						input[iter] = input[len-iter-1];
					}
					else {
						input[len-iter-1] = input[iter];
					}
				}
			}
			int k_remaining = k - edits;
			for (int iter = 0;iter < n/2 && k_remaining;iter++) {
				if ((edited[len - iter - 1] || edited[iter]) && input[iter] != '9') {
					input[len - iter - 1] = '9';
					input[iter] = '9';
					k_remaining--;
				}
				else if (input[len - iter - 1] == input[iter] && input[iter] != '9' && k_remaining >1) {
					input[len - iter - 1] = '9';
					input[iter] = '9';
					k_remaining -= 2;
				}
				else if (input[len - iter - 1] == input[iter]) {
					continue;
				}
			}
			if (k == 1 && n % 2 == 1) {
				input[n / 2] = '9';
			}
		}
	}
	cout << input << endl;
	return 0;
}