#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#define MAX_LENGTH 100


int max(int a, int b) {
	if (a > b)
		return a;
	return b;
}

int getLongestPalindromicSubstring(char *input) {
	int length = strlen(input);
	int *odd = (int *)malloc(sizeof(int)*length);
	int *even = (int *)malloc(sizeof(int)*length);
	for (int iter = 0;iter < length;iter++) {
		odd[iter] = 0;
		even[iter] = 0;
	}
	for (int iter = 0;input[iter];iter++) {
		int left = iter - 1, right = iter + 1;
		for (;left >= 0 && right <= length;) {
			if (input[left] == input[right]) {
				left--;
				right++;
			}
			else {
				odd[iter] = max(odd[iter], right - left-1);
				break;
			}
		}
	}
	for (int iter = 0;input[iter];iter++) {
		for (int index = iter; index + 1 < length;index++) {
			int left = index, right = index + 1;
			for (;left >= 0 && right <= length;) {
				if (input[left] == input[right]) {
					left--;
					right++;
				}
				else {
					even[index] = max(even[index], right - left-1);
					break;
				}
			}
		}
	}
		int odd_max = INT_MIN;
		int even_max = INT_MIN;
		for (int iter = 0;iter < length;iter++) {
			if (odd[iter] > odd_max) {
				odd_max = odd[iter];
			}
			if (even[iter] > even_max) {
				even_max = even[iter];
			}
		}
		return max(even_max, odd_max);
	
}



void main(void) {
	char input[MAX_LENGTH];
	printf("Enter the input string\n");
	scanf("%s", input);
	int result = getLongestPalindromicSubstring(input);
	printf("The longest palindromic sustring is of length %d\n", result);
	char ch;
	fflush(stdin);
	fflush(stdin);
	fflush(stdin);
	scanf("%c", &ch);
}