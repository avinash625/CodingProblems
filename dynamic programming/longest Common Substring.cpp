#include<iostream>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
int getLongestCommonSubstring(char *input1,char *input2, int len1, int len2){
    int **result = (int **)malloc(sizeof(int*)*(len1+1));
    for(int iter = 0 ;iter< len1+1;iter++){
        result[iter] = (int *)malloc(sizeof(int)*len2+1);
        result[iter][0]=  0;
    }
    for(int iter = 0 ;iter<len2+1;iter++){
        result[0][iter]= 0;
    }
    for(int iter1=1 ;iter1< len1+1 ;iter1++){
        for(int iter2 = 1 ;iter2< len2+1;iter2++){
            if(input1[iter1-1]== input2[iter2-1])
                result[iter1][iter2] = result[iter1-1][iter2-1] + 1;
            else
                result[iter1][iter2] = 0;
        }
    }
    int max = 0;
    for(int iter = 0 ;iter< len1+1;iter++){
        for(int i = 0 ;i<len2+1;i++){
            if(result[iter][i] > max)
                max = result[iter][i];
        }
    }
    return max;
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int len1,len2;
	    cin>>len1>>len2;
	    char input1[101],input2[101];
	    cin>>input1>>input2;
	    cout<<getLongestCommonSubstring(input1,input2,len1,len2)<<endl;
	}
	return 0;
}