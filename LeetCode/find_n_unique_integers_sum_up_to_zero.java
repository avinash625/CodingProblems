class Solution {
    public int[] sumZero(int n) {
        int[] result = new int[n];
        if(n == 1) return result;
        else{
            if(n %2 == 0){
                for(int iter = 0; iter< n; iter+= 2){
                    result[iter] = iter+1;
                    result[iter+1] = -1 * (iter+1);
                }
            }else{
                result[0] = 0;
                
                for(int iter = 1; iter< n; iter+= 2){
                    result[iter] = iter;
                    result[iter+1] = -1* iter;
                }
            }
        }
        return result;
    }
}