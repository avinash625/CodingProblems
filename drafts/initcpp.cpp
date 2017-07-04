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
#include<string.h>
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
#define forabc(a,b,c) for(int iter = (int)a; iter< (int)b;iter+=(int)c)
#define clr(a) memset((a),0,sizeof(a))
#define fill(a,value) memset((a), value, sizeof(a))
#define read(a,n) for(int iter = 0;iter< n;iter++){cin>>a[iter];}
#define print(a) for(int iter = 0;iter<(a).size;i++ ){ cout<<a[iter]<<" ";}

template <class tempA, class tempB> bool compareWithOne(const pair<tempA, tempB> &a, const pair<tempA, tempB> *b) { if (a->first > b->first)		return true;	return false; }
template <class tempA, class tempB> bool compareWithTwo(const pair<tempA, tempB> &a, const pair<tempA, tempB> *b) { if (a->second > b->second)		return true;	return false; }
template <class templateData> templateData maxab(templateData a, templateData b) { if (a>b) 	return a;	return b; }
template <class templateData> templateData minab(templateData a, templateData b) { if (a<b)		return a;	return b; }


int main(void) {
	int t;
	cin>>t;
	while(t--){
	    char  input[101];
	    cin>>input;
	    stack<char> st;
	    forabc(0,strlen(input),1){
	        if(st.empty()){
	            st.push(input[iter]);
	        }
	        else if(st.top() == '(' && input[iter] == ')'){
	            st.pop();
	        }
	        else if(st.top() == '{' && input[iter] == '}'){
	            st.pop();
	        }
	        else if(st.top() == '[' && input[iter] == ']'){
	            st.pop();
	        }
	        else{
	            st.push(input[iter]);
	        }
	    }
	    if(st.empty()){
	        cout<<"balanced"<<endl;
	    }
	    else{
	        cout<<"not balanced"<<endl;
	    }
	}
    return 0;
}