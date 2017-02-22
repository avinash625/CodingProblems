//Given an array of digits (values are from 0 to 9), find the minimum possible sum of two numbers formed from digits of the array.
//All digits of given array must be used to form the two numbers.


#include<iostream>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
struct comparator{
    bool operator()(int i,int j){
        return i > j;
    }
};
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int *values = (int *)malloc(sizeof(int)*n);
	    for(int iter = 0 ;iter<n;iter++){
	        scanf("%d",&values[iter]);
	    }
	    priority_queue<int,vector<int>,comparator> minHeap;
	    for(int iter =  0 ;iter<n;iter++){
	        minHeap.push(values[iter]);
	    }
	    int flag = 1;
	    int first = 0 ;
	    int second = 0 ;
	    while(!minHeap.empty()){
	        if(flag == 1){
	            first = (first*10)+minHeap.top();
	            minHeap.pop();
	            flag = 0;
	        }
	        else{
	            second = (second *10)+minHeap.top();
	            minHeap.pop();
	            flag = 1;
	        }
	    }
	    cout<<first+second<<endl;
	}
	return 0;
}
