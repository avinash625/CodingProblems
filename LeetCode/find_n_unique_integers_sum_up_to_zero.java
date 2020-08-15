class Solution {
    public int[] sumZero(int n) {
        int[] result = new int[n];
        boolean odd = false;
        if(n%2 != 0){
            odd = true;
            n = n-1;
        }

        for(int iter= 0; iter< n; ){
            result[iter] = iter+1;
            result[iter+1] = (iter+1) * -1;;
            iter+=2;
        }

        if(odd){
            result[n] =  0;
        }
        return result;
    }
}