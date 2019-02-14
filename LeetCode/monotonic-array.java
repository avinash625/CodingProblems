class Solution {
    public boolean isMonotonic(int[] A) {
        if(A.length == 0 || A.length == 1) return true;
        else{
            if(A[0] > A[1])
                return checkMonotonicIncreasing(A);
            else if(A[0] < A[1])
                return checkMonotonicDecreasing(A);
            else{
                 return (checkMonotonicIncreasing(A) || checkMonotonicDecreasing(A));
            }
        }
    }
    
    public boolean checkMonotonicIncreasing(int[] A){
        int count = 0;
        for(int iter = 0;iter< A.length-1; iter++){
            if(A[iter] - A[iter+1] < 0)
                count++;
        }
        if(count > 0) return false;
        return true;
    }
    
    public boolean checkMonotonicDecreasing(int[] A){
        int count = 0;
        for(int iter = 0;iter< A.length-1; iter++){
            if(A[iter] - A[iter+1] > 0)
                count++;
        }
        if(count > 0) return false;
        return true;
    }
    
}