class Solution {
    public boolean isPerfectSquare(int num) {
        if(num == 0) return false;
        else if(num == 1) return true;
        for(int iter = 1; iter<= num/2; iter++){
            if(iter * iter == num)
                return true;
        }
        return false;
    }
}