#include<iostream>
#include<stdlib.h>
#include<vector>
#include<deque>
#include<limits.h>

using namespace std;

int getresult(int *values, int n, int window) {
	vector<int> maximums;
	deque<int> pset;
	for (int iter = 0;iter < window;iter++) {
		if (pset.empty() || values[pset.back()] >= values[iter]) {
			pset.push_back(iter);
		}
		else if (values[pset.back()] < values[iter]) {
			while (!pset.empty() && values[pset.back()] < values[iter]) {
				pset.pop_back();
			}
			pset.push_back(iter);
		}
	}
	maximums.push_back(values[pset.front()]);
	for (int iter = window;iter < n;iter++) {
		if (pset.empty() || values[pset.back()] >= values[iter]) {
			pset.push_back(iter);
		}
		else if (values[pset.back()] < values[iter]) {
			while (!pset.empty() && values[pset.back()] < values[iter]) {
				pset.pop_back();
			}
			pset.push_back(iter);
		}
		if (!pset.empty() && pset.front() <= iter - window) {
			pset.pop_front();
		}
		maximums.push_back(values[pset.front()]);
	}
	/*for (vector<int>::iterator it = maximums.begin(); it != maximums.end(); it++) {
		cout << values[*it] << " ";
	}
	cout << endl;
	return 0;*/
	int minValue = INT_MAX;
	for (vector<int>::iterator it = maximums.begin(); it != maximums.end();it++) {
		if (minValue > *it) {
			minValue = *it;
		}
	}
	return minValue;
}


int main(void) {
	int n, q;
	cin >> n >> q;
	int *values = (int *)malloc(sizeof(int)*n);
	for (int iter = 0;iter < n;iter++)
		cin >> values[iter];
	int window;
	while (q--) {
		cin >> window;
		cout << getresult(values, n, window) << endl;
	}
	return 0;
}