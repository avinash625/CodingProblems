class Solution {
    public boolean validMountainArray(int[] A) {
        int maximum = 0;
        if(A.length < 3) return false;
        
        for(int iter = 1;iter< A.length; iter++){
            if(A[maximum] < A[iter])
                maximum = iter;
        }
        
        if(maximum == 0 || maximum == A.length-1)
            return false;
        else{
            int previous = maximum;
            for(int iter = maximum+1; iter< A.length;iter++){
                if( A[previous] - A[iter] > 0){
                    previous = iter;
                }
                else{
                    return false;
                }
            }
            previous = maximum;
            for(int iter = maximum-1;iter>=0;iter--){
                if(A[previous] - A[iter] > 0){
                    previous = iter;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
}