#include<iostream>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int t;
	cin >> t;
	char value;
	while (t--) {
		int len;
		int count[26] = { 0 };
		cin >> len;
		deque<char> result;
		for (int iter = 0;iter<len;iter++) {
			cin >> value;
			count[value - 'a'] = count[value - 'a'] + 1;
			if (count[value - 'a'] == 1) {
				result.push_back(value);
			}
			while (!(result.empty()) && count[result.front() - 'a'] != 1) {
				//count[result.front() - 'a']--;
				result.pop_front();
			}
			if (result.empty())
				cout << -1 << " ";
			else {
				cout << result.front() << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
