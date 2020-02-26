class Solution {
    public int climbStairs(int n) {
        int[] steps = new int[n+1];
        if(n>2){
            steps[0] = 0;
            steps[1] = 1;
            steps[2] = 2;
            for(int iter = 3; iter <= n ;iter++){
                steps[iter] = steps[iter-1] + steps[iter-2];
            }
            
            return steps[n];
        }
        return n;
    }
}