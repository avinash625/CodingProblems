#include<iostream>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
unsigned long int getModifiedNumber(unsigned long int n){
    unsigned int even = n & 0xAAAAAAAA;
    unsigned int odd = n & 0x55555555;
    even>>=1;
    odd<<=1;
    return (even | odd);
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    unsigned long int n;
	    cin>>n;
	    cout<<getModifiedNumber(n)<<endl;
	}
	return 0;
}
