/*the input matrix is sorted row and column wise*/
#include<queue>
struct comparator{
    bool operator()(int i, int j){
        return i>j;
    }
};
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    priority_queue<int,vector<int>,comparator> minHeap;
    for(int row = 0;row<n;row++){
        for(int col = 0; col< n; col++){
            minHeap.push(mat[row][col]);
        }
    }
    while(k>1){
        minHeap.pop();
        k--;
    }
    return minHeap.top();
}
