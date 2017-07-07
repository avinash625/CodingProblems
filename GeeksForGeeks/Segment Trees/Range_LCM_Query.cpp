// Function to build the segment tree
// Node starts beginning index of current subtree.
// start and end are indexes in arr[] which is global
void build(long long int arr[], long long int node,long long  int start,long long  int end)
{
    if(start == end){
        tree[node] = arr[start];
        return;
    }
    long long int mid = (start+end)/2;
    build(arr,2*node+1,start,mid);
    build(arr,2*node+2,mid+1,end);
    tree[node] = lcm(tree[2*node+1],tree[2*node+2]);
}

// Function to make queries for array range )l, r).
// Node is index of root of current segment in segment
// tree (Note that indexes in segment tree begin with 1
// for simplicity).
// start and end are indexes of subarray covered by root
// of current segment.
long long int query(long long int node,long long  int start,long long  int end,long long  int l,long long  int r)
{
    if(r<start || l>end){
        return 1;
    }
    else if(l<=start && end<= r){
        return tree[node];
    }
    else{
        int mid = (start+end)/2;
        return lcm(query(2*node+1,start,mid,l,r),query(2*node+2,mid+1,end,l,r));
    }
    return 0;

}