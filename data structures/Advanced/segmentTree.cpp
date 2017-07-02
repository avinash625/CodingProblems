#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdint>
#include<stdlib.h>
#include<limits.h>
using namespace std;

int getNext2power(int n) {
	int count = 0;
	while (n) {
		count++;
		n = n >> 1;
	}
	return (1 << count);
}

int queryRMQ(int *segTree, int start, int end, int qstart, int qend,int pos) {
	if (qend<start || qstart > end) {
		return INT_MIN;
	}
	else if (qstart <= start && end <= qend) {
		return segTree[pos];
	}
	else {
		int mid = (start + end) / 2;
		return max(queryRMQ(segTree, start, mid, qstart, qend, 2 * pos + 1), queryRMQ(segTree, mid + 1, end, qstart, qend, 2 * pos + 2));
	}
}

void constructTree(int *values, int *segTree, int start, int end, int currentNode) {
	if (start == end) {
		segTree[currentNode] = values[start];
		return;
	}
	int middle = (start + end) / 2;
	constructTree(values, segTree, start, middle, 2 * currentNode + 1);
	constructTree(values, segTree, middle + 1, end, 2 * currentNode + 2);
	segTree[currentNode] = max(segTree[2 * currentNode + 1], segTree[2 * currentNode + 2]);
}

void updateValue(int *values, int *segTree, int start, int end, int currentNode,int newValue,int position) {
	if (end == start && start == position) {
		segTree[currentNode] = newValue;
		values[position] = newValue;
		return;
	}
	int mid = (start + end) / 2;
	if(start <= position && position <= mid){
		updateValue(values, segTree, start, mid, 2 * currentNode + 1, newValue,position);
	}
	else {
		updateValue(values, segTree, mid + 1, end, 2 * currentNode + 2, newValue, position);
	}
	segTree[currentNode] = max(segTree[2 * currentNode + 1], segTree[2 * currentNode + 2]);
}
int main(void) {
	int n;
	cin >> n;
	int *values = (int *)malloc(sizeof(int)*n);
	for (int iter = 0;iter < n;iter++)
		cin >> values[iter];
	int *seg;
	int newN;
	if (n & (n - 1) == 0) {
		newN = 2 * n - 1;
		seg = (int *)malloc(sizeof(int)*(n * 2 - 1));
		for (int iter = 0;iter< n * 2 - 1;iter++)
			seg[iter] = INT_MIN;
	}
	else {
		newN = getNext2power(n);
		seg = (int *)malloc(sizeof(int)*(newN * 2 - 1));
		for (int iter = 0;iter < newN;iter++)
			seg[iter] = INT_MIN;
	}
	constructTree(values, seg, 0, n-1, 0);
	/*for (int iter = 0;iter < newN;iter++) {
		cout << seg[iter] << " ";
	}*/
	int query, position, value;
	cin >> query;
	char q;
	while (query--) {
		int l, r;
		cout << "Enter the query type" << endl;
		cin >> q;
		if (q == 'r') {
			cin >> l >> r;
			cout << queryRMQ(seg, 0, n - 1, l - 1, r - 1, 0) << endl;;
		}
		else if (q=='u'){
			cin >> position;
			cin >> value;
			updateValue(values, seg, 0, n - 1, 0, value, position-1);
		}
		
	}
	return 0;
}