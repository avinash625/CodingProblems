/*
Problem Link:
https://www.hackerrank.com/challenges/simple-text-editor/problem
*/

/*
"author"	:	"avinash bondalapati"
"date"		:	"28-08-2017"
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
//#define sort(a) sort(a.begin(),a.end())
#define log(text) cout<<"log:"<<" "<<text<<endl
#define forabc(a,b,c) for(int iter = (int)a; iter< (int)b;iter+=(int)c)
#define clr(a) memset((a),0,sizeof(a))
#define fill(a,value) memset((a), value, sizeof(a))
#define read(a,n) for(int iter = 0;iter< n;iter++){cin>>a[iter];}
#define print(a) for(int iter = 0;iter<(a).size();iter++ ){ cout<<a[iter]<<" ";}

bool compareWithOne(const pair<int,string> &a, const pair<int,string> &b) { if (a.first >= b.first)		return false;	return true; }
bool compareWithTwo(const pair<int,string> &a, const pair<int,string> &b) { if (a.second > b.second)		return true;	return false; }
template <class templateData> templateData maxab(templateData a, templateData b) { if (a>b) 	return a;	return b; }
template <class templateData> templateData minab(templateData a, templateData b) { if (a<b)		return a;	return b; }


int main(void) {
	int q;
    cin>>q;
    string resultantString;
    string word;
    stack<string> st;
    int operation;
    int k;
    while(q--){
        cin>>operation;
        if(operation == 1){
            st.push(resultantString);
            cin>>word;
            resultantString.append(word);
            //cout<<"resultantString after operation 1 "<<resultantString<<endl;
        }
        else if(operation == 2){
            st.push(resultantString);
            cin>>k;
            resultantString.assign(resultantString, 0, resultantString.length()-k);
            //cout<<"resultantString after operation 2 "<<resultantString<<endl;
        }
        else if(operation == 3){
            cin>>k;
            cout<<resultantString[k-1]<<endl;;
        }
        else{
            resultantString = st.top();
            st.pop();
            //cout<<"resultantString after operation 4 "<<resultantString<<endl;
        }
    }
}
