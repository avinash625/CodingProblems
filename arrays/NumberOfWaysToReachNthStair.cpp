#include<iostream>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
unsigned long long int getNoOfWays(int n,unsigned long long int *result){
    if(n ==0 || n == 1)
        return 1;
    else{
        if(result[n] != -1)
            return result[n];
        else
            result[n] =  (getNoOfWays(n-1,result)%1000000007 +(getNoOfWays(n-2,result))%1000000007)%1000000007;
        return result[n];
    }
}
int main()
 {
	int t;
	cin>>t;
	unsigned long long int result[101] ;
	for(int iter = 0 ;iter< 101;iter++){
	    result[iter] = -1;
	}
	result[0] = result[1] = 1;
	while(t--){
	    int n;
	    cin>>n;
	    cout<<getNoOfWays(n,result)<<endl;
	}
	return 0;
}