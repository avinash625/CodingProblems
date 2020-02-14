class Solution {
    public int fixedPoint(int[] A) {
        
        for(int iter = 0; iter< A.length; iter++){
            if(A[iter] == iter)
                return iter;
        }
        return -1;
        
    }
}