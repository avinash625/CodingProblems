#include<iostream>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;
int getMaximumSubArraySum(int *values,int n){
    int max_ending_here = 0 ;
    int max_ending = 0;
    bool negative = true;
    for(int iter = 0 ;iter< n;iter++){
        
        if(values[iter] > 0)
            negative = false;
         max_ending_here = max_ending_here+values[iter];
        if(max_ending_here> max_ending)
            max_ending = max_ending_here;
        if(max_ending_here <= 0 ){
            max_ending_here = 0;
        }
    }
    if(negative){
        int maximum = INT_MIN;
        for(int iter=0;iter<n;iter++){
            if(maximum < values[iter])
                maximum  = values[iter];
        }
        return maximum;
    }
    else
        return max_ending;
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int *values = (int *)malloc(sizeof(int)*n);
	    for(int iter =0 ;iter<n;iter++){
	        scanf("%d",&values[iter]);
	    }
	    cout<<getMaximumSubArraySum(values,n)<<endl;
	}
	return 0;
}