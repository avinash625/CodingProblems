#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long int getPower(unsigned int a, unsigned int b) {
	unsigned long long int result = 1;
	unsigned long long int temp = a;
	while (b) {
		
			result = (result % 1000000007)*(temp % 1000000007) % 1000000007;
		
		b--;
		//temp = ((temp)*(a));
	}
	return result;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		unsigned int a, b;
		cin >> a >> b;
		cout << getPower(a, b) << endl;
	}
	return 0;
}
