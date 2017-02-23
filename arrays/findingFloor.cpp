#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<algorithm>
#include<iostream>

using namespace std;

int comparator(const void *a, const void *b) {
	return (*(int *)a - *(int *)b);
}
int getFloor(int *values,int n, int starting , int ending, int key) {
	int start = starting;
	int end = ending;
	int mid = (start)+(end - start) / 2;
	if (values[start] > key) {
		if (start == 0)
			return INT_MIN;
		else
			return values[start - 1];
	}
	if (values[end] < key)
		return values[end];
	if (start > end)
		return values[start - 1];
	if (values[mid] == key)
		return key;
	else if (values[mid] < key) {
		return getFloor(values,n, mid + 1,end, key);
	}
	else if (values[mid] > key) {
		return getFloor(values,n, start, mid - 1,key);
	}
    return 0 ;
}
int  main(void) {
	
		int n;
		cin >> n;
		int *values = (int *)malloc(sizeof(int)*n);
		for (int iter = 0;iter < n;iter++) {
			scanf("%d", &values[iter]);
		}
		qsort(values, n, sizeof(int), comparator);
		int q;
		cin >> q;
		while (q--) {
			int key;
			cin >> key;
			cout << getFloor(values,n,0,n-1,key) << endl;
		}
	
}
