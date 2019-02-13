class Solution {
    public boolean isPerfectSquare(int num) {
        int count =0;
        if(num == 1) return true;
        for(int iter = 1; iter <= num/2;iter++){
            if((iter*iter) == num)
                return true;
        }
        return false;
    }
}