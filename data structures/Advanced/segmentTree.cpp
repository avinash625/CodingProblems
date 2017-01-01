#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<map>

using namespace std;
int min(int a, int b){
	if (a > b)
		return b;
	return a;
}

int next2Power(int n){
	int count = 0;
	while (n){
		count++;
		n = n >> 1;
	}
	return 1 << (count);
}

int rangeMinimumQuery(int *segTree, int qlow, int qhigh, int low, int high, int pos){
	if (qlow <= low && high <= qhigh){
		return segTree[pos];
	}
	else if (qlow > high || qhigh < low){
		return INT_MAX;
	}
	else {
		int mid = (low + high) / 2;
		return min(rangeMinimumQuery(segTree, qlow, qhigh, low, mid, 2 * pos + 1), rangeMinimumQuery(segTree, qlow, qhigh, mid+1, high, 2 * pos + 2));
	}
}

void constructTree(int *values, int *segTree, int low, int high, int pos){
	if (high == low){
		segTree[pos] = values[low];
		return;
	}
	int mid = ((low + high) / 2);
	constructTree(values, segTree, low, mid, (2 * pos) + 1);
	constructTree(values, segTree, mid+1, high, (2 * pos) + 2);
	segTree[pos] = min(segTree[2 * pos + 1], segTree[2 * pos + 2]);
}

void main(void){
	int n;
	cout << "Enter the number of values" << endl;
	cin >> n;
	int *segTree;
	int *values = (int *)malloc(sizeof(int)*n);
	cout << "Enter the values \n";
	for (int iter = 0; iter < n; iter++){
		scanf("%d", &values[iter]);
	}
	if (n&(n - 1) == 0){
		segTree = (int *)malloc(sizeof(int)*(n*2 - 1));
		for (int iter = 0; iter < n * 2 - 1; iter++){
			segTree[iter] = INT_MAX;
		}
	}
	else{
		int modifiedN =  next2Power(n);
		segTree = (int *)malloc(sizeof(int)*(modifiedN * 2 - 1));
		for (int iter = 0; iter < modifiedN*2-1; iter++){
			segTree[iter] = INT_MAX;
		}
	}
	int q;
	constructTree(values, segTree, 0, n, 0);
	cout << "enter the number of queries" << endl;
	int a, b;
	cin >> q;
	for (int iter = 0; iter < q; iter++){
		cout << "enter the range(use zero based index)" << endl;
		cin >> a >> b;
		printf("the minimum value in the range %d to %d is %d\n",a, b, rangeMinimumQuery(segTree, a, b, 0, n, 0));
	}
}