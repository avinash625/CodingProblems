#include<iostream>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	   char input[101];
	   cin>>input;
	   int odd = 0 ;
	   int even = 0 ;
	   for(int iter =0 ; input[iter] ;iter++){
	       if(iter&1){
	           odd  = odd + (input[iter]-'0');
	       }
	       else{
	           even = even + (input[iter]-'0');
	       }
	   }
	   if(abs(odd-even)%3 == 0)
	        cout<<1<<endl;
	   else
	        cout<<0<<endl;
	}
	return 0;
}