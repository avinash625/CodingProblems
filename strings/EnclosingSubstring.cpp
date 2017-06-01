
#include<map>
#include<vector>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<cstdint>
#include<limits.h>
#include<algorithm>
#include<queue>

using namespace std;

int getEnclosingSubstringLength(char *text, char *pattern) {
	
	int a = INT_MAX;

	map<char, int> pf;
	map<char, int> rf;
	map<char, int> df;
	for (int iter = 0;pattern[iter];iter++) {
		pf[pattern[iter]]++;
		df[pattern[iter]]++;
	}
	queue<char> result;
	int characters = 0;
	for (map<char, int>::iterator it = pf.begin(); it != pf.end(); it++) {
		characters += (it)->second;
	}
	
	int start = 0;
	for (int iter = 0;text[iter];iter++) {
		if (df[text[iter]] > 0 || characters>0) {
			result.push(text[iter]);
			rf[text[iter]]++;
			if (df[text[iter]]>0)
				characters--;
			df[text[iter]]--;
			if (text[iter] == text[start] && iter != 0) {
				while (rf[text[start]] > pf[text[start]]) {
					rf[text[start]]--;
					start++;
					result.pop();
				}
			}
			if (characters == 0) {
				int size = result.size();
				if (size < a)
					a = size;
			}
		}
		else {
			result.push(text[iter]);
			rf[text[iter]]++;
			if (text[iter] == text[start] && iter != 0) {
				while (rf[text[start]] > pf[text[start]]) {
					rf[text[start]]--;
					start++;
					result.pop();
				}
			}
			if (size(result) < a)
				a = size(result);
		}
	}
	return a;
}

int main(void) {
	int t;
	cin >> t;
	while (t--) {
		char text[10001], pattern[10001];
		cin >> text >> pattern;
		int a = getEnclosingSubstringLength(text, pattern);
		if (a == INT_MAX)
			cout << -1 << endl;
		else
			cout << a << endl;
		
	}
	return 0;
}