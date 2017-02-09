#include<iostream>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int *values = (int *)malloc(sizeof(int)*n);
	    for(int iter = 0;iter<n;iter++){
	        scanf("%d",&values[iter]);
	    }
	    stack<int> minimum;
	    for(int iter = 0;iter<n;iter++){
	        if(minimum.size() == 0){
	            cout<<-1<<" ";
	            minimum.push(values[iter]);
	        }
	       else if(minimum.top() < values[iter]){
	           cout<<minimum.top()<<" ";
	           minimum.push(values[iter]);
	       }
	       else{
	           while(!minimum.empty() && minimum.top()>=values[iter]){
	               minimum.pop();
	           }
	           if(!minimum.empty())
	                cout<<minimum.top()<<" ";
	           else
	                cout<<-1<<" ";
	           minimum.push(values[iter]);
	       }
	    }
	    cout<<endl;
	}
	return 0;
}