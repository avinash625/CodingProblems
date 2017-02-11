#include<iostream>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
int comparator(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int value;
	    
	    int *values = (int *)malloc(sizeof(int)*n);
	    for(int iter = 0 ;iter<n;iter++){
	        scanf("%d",&values[iter]);
	    }
	    qsort(values,n,sizeof(int),comparator);
	    int result = 1;
	    int tempResult = 1;
	    int prev = values[0];
	    for(int iter =  1;iter< n;iter++){
	        if(values[iter] == prev+1){
	            tempResult++;
	            if(tempResult> result)
	                result = tempResult;
	        }
	        else{
	            tempResult = 1;
	        }
	        prev = values[iter];
	    }
	    cout<<result<<endl;
	}
	return 0;
}