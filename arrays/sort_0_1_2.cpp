#include<iostream>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
void sort012(int *values, int n){
    int ones = 0;
    int zeros = 0;
    int twos = 0;
    for(int iter =0 ;iter< n;iter++){
        if(values[iter] == 0)
            zeros++;
        else if(values[iter] == 1)
            ones++;
        else if(values[iter] == 2)
            twos++;
    }
    int iter;
    for( iter = 0 ;iter< zeros;iter++)
        values[iter] = 0;
    for(;iter<zeros+ones;iter++)
        values[iter] = 1;
    for(;iter<zeros+ones+twos;iter++)
        values[iter] = 2;
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int *values = (int *)malloc(sizeof(int)*n);
	    for(int iter =0;iter<n;iter++){
	        scanf("%d",&values[iter]);
	    }
	    sort012(values,n);
	    for(int iter = 0 ;iter<n;iter++){
	        cout<<values[iter]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}