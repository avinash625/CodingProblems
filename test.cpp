#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<limits.h>
#include<iostream>
#include<cstdint>
#include<algorithm>
using namespace std;
void print(int *values, int n) {
	for (int iter = 0;iter < n;iter++) {
		cout << values[iter] << " ";
	}
	cout << endl;
}
int  merge(int *values, int start, int middle, int end) {
	int inversions = 0;
	int *temp = (int *)malloc(sizeof(int)*(end - start + 1));
	int firstIter = start;
	int secondIter = middle + 1;
	int writeIter = 0;

	while (firstIter <= middle && secondIter <= end) {
		if (values[firstIter] >= values[secondIter]) {
			temp[writeIter] = values[secondIter];
			inversions += (middle-firstIter);
			secondIter++;
		}
		else {
			temp[writeIter] = values[firstIter];
			firstIter++;
		}
		writeIter++;
	}

	if (firstIter <= middle) {
		inversions += (middle-firstIter);
		while (firstIter <= middle) {
			temp[writeIter] = values[firstIter];
			writeIter++;
			firstIter++;
		}
		//inversions += (end - middle);
	}

	if (secondIter <= end) {
		while (secondIter <= end) {
			temp[writeIter] = values[secondIter];
			writeIter++;
			secondIter++;
		}
	}

	for (int iter = start, readIter = 0; iter <= end;iter++, readIter++) {
		values[iter] = temp[readIter];
	}

	return inversions;
}
int mergeSort(int *values, int start, int end) {
	int inversions = 0;
	if ((end - start) >= 1) {
		int middle = start + (end - start) / 2;
		inversions+=mergeSort(values, start, middle);
		inversions+=mergeSort(values, middle + 1, end);
		inversions+=merge(values, start, middle, end);
	}
	return inversions;
}
int main(void) {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int *values = (int *)malloc(sizeof(int)*n);
		for (int iter = 0;iter < n;iter++) {
			cin >> values[iter];
		}
		cout<<"the inversions are " << mergeSort(values, 0, n - 1);
		print(values, n);
	}
	return 0;
}
