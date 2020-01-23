class Solution {
    public int[] countBits(int num) {
        int [] result = new int[(num+1)];
        result[0] = 0;
        if(num == 0) return result;
        result[1] = 1;
        int lowestPerfectSquare = 2;
        for(int iter = 2; iter <= num; iter++){
            if((iter&(iter-1))==0){
                lowestPerfectSquare = iter;
                result[iter] = 1;
            }else{
                result[iter] = result[lowestPerfectSquare] + result[iter - lowestPerfectSquare];
            }
        }
        return result;
    }
}