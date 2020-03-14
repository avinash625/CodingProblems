class Solution {
    public boolean checkPerfectNumber(int num) {
        if(num == 0) return false;
        int total = 0;
        for(int iter =1; iter<= num/2; iter++){
            if(num%iter == 0){
                total += iter;
                //System.out.println("total updated to "+ total);
            }
        }
        return (total == num);
    }
}