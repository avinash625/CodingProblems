/* The functions which 
builds the segment tree */
#include<limits.h>
int minab(int a, int b){
    if(a<b)return a;
    return b;
}
int getNextN(int n){
    int count = 0;
    while(n){
        count++;
        n = n>>1;
    }
    return (1<<count);
}
void constructSegTreeUtil(int *arr, int *segTree, int starting, int ending, int currentIndex){
    if(starting == ending){
        segTree[currentIndex] = arr[starting];
        return;
    }
    int mid = (starting+ending)/2;
    constructSegTreeUtil(arr,segTree,starting,mid,2*currentIndex+1);
    constructSegTreeUtil(arr,segTree,mid+1,ending,2*currentIndex+2);
    segTree[currentIndex] = minab(segTree[2*currentIndex+1],segTree[2*currentIndex+2]);
}
int temp ;
int *constructST(int arr[],int n)
{
    int segSize ;
    if(n&(n-1) == 0){
        segSize = 2*n-1;
    }
    else{
        segSize = 2*getNextN(n)-1;
    }
    temp = segSize;
    int *segTree = (int *)malloc(sizeof(int)*segSize);
    for(int iter = 0;iter<segSize;iter++)
        segTree[iter]= 0;
    constructSegTreeUtil(arr,segTree,0,n-1,0);
    return segTree;
}


int RMQutil(int *st, int starting,int ending, int a, int b,int index){
    if(a>ending || b<starting)
        return INT_MAX;
    else if(a<=starting && ending<=b){
        return st[index];
    }
    else{
        int mid  =  (starting+ending)/2;
        return minab(RMQutil(st,starting,mid,a,b,2*index+1),RMQutil(st,mid+1,ending,a,b,2*index+2));
    }
}
int RMQ(int st[] , int n, int a, int b)
{
    return RMQutil(st,0,n-1,a,b,0);
}