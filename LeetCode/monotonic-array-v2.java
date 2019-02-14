class Solution {
    public boolean isMonotonic(int[] A) {
        
        boolean increasing = true;
        boolean decreasing = true;
        for(int iter = 0;iter< A.length-1;iter++){
            if(A[iter] > A[iter+1])
                increasing = false;
            if(A[iter]< A[iter+1])
                decreasing = false;
        }
        return (increasing || decreasing);
    }
}