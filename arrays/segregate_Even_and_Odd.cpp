#include<iostream>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
int cmp(const void *a, const void *b){
    return (*(int *)a-*(int *)b);
}
int cmp2(const void *a, const void *b){
    return (*(int *)a&1 - (*(int *)b&1));
}
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
	    qsort(values,n,sizeof(int),cmp);
	    qsort(values,n,sizeof(int),cmp2);
	    for(int iter = 0 ;iter< n;iter++)
	        cout<<values[iter]<<" ";
	    cout<<endl;
	}
	return 0;
}