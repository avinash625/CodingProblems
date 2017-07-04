/*
"author"	:	"avinash bondalapati"
"date"		:	"02-07-2017"
"language"	:	"c++"
*/

#include<iostream>
#include<stdlib.h>
#include<memory.h>
#include<math.h>
#include<limits.h>
#include<cstdint>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<utility>
#include<algorithm>
using namespace std;

#define F first
#define S second
#define ll long long int 
#define l long int 
#define ld long double
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define mod 1e10+7
#define vint vector<int>
#define vchar vector<char>
#define all(a) (a.begin(),a.end())
#define sort(a) sort(a.begin(),a.end())
#define log(text) cout<<"log:"<<" "<<text<<endl
#define forabc(a,b,c) for(int iter = a; iter<b;iter+= c)
#define clr(a) memset((a),0,sizeof(a))
#define fill(a,value) memset((a), value, sizeof(a))
#define read(a,n) for(int iter = 0;iter< n;iter++){cin>>a[iter];}
#define print(a) for(int iter = 0;iter<(a).size();iter++ ){ cout<<a[iter]<<" ";}

template <class tempA, class tempB> bool compareWithOne(const pair<tempA, tempB> &a, const pair<tempA, tempB> *b) { if (a->first > b->first)		return true;	return false; }
template <class tempA, class tempB> bool compareWithTwo(const pair<tempA, tempB> &a, const pair<tempA, tempB> *b) { if (a->second > b->second)		return true;	return false; }
template <class templateData> templateData maxab(templateData a, templateData b) { if (a>b) 	return a;	return b; }
template <class templateData> templateData minab(templateData a, templateData b) { if (a<b)		return a;	return b; }


int main(void) {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vint a(n);
		read(a, n);
		queue<int> first;
		queue<int> second;
		sort(a);
		forabc(0, n, 1) {
			if (iter % 2 == 0) {
				first.push(a[iter]);
			}
			else
				second.push(a[iter]);
		}
		ll fn = 0;
		while (!first.empty()) {
			fn = (fn * 10) + first.front();
			first.pop();
		}
		ll sn = 0;
		while(!second.empty()) {
			sn = (sn * 10) + second.front();
			second.pop();
		}
		cout << fn + sn << endl;
	}
}
