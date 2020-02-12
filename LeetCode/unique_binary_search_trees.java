class Solution {
    public int numTrees(int n) {
        if(n == 0 || n == 1) return 1;
        if(n == 2) return 2;
        int[] uniqueTrees = new int[n+1];
        uniqueTrees[0] = 1;
        uniqueTrees[1] = 1;
        uniqueTrees[2] = 2;
        getUniqueTreesCount(n, uniqueTrees);
        return uniqueTrees[n];
    }
    
    public int getUniqueTreesCount(int n, int[] uniqueTrees){
        int uniqueTreesSum = 0;
        if(n == 0 || n == 1 || n == 2) return uniqueTrees[n];
        else if(uniqueTrees[n] != 0) return uniqueTrees[n];
        else{
            int product = 1;
            int left = 1;
            int right = 1;
            for(int iter = 1; iter<= n; iter++){
                left = getUniqueTreesCount(iter -1, uniqueTrees);
                right = getUniqueTreesCount(n - iter, uniqueTrees);
                
                uniqueTreesSum = uniqueTreesSum + (left * right);
            }
        }
        uniqueTrees[n] = uniqueTreesSum;
        return uniqueTreesSum;
    }
}