class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
        ArrayList<Integer> result = new ArrayList<Integer>();
        for(int iter = left; iter<= right; iter++){
            if(isSelfDividing(iter)){
                result.add(iter);
            }
        }
        return result;
    }
    
    public boolean isSelfDividing(int num){
        if(num%10 == 0) return false;
        else{
            int currentDigit;
            int value = num;
            while(num > 0){
                currentDigit = num%10;
                if(currentDigit == 0 || (value % currentDigit != 0))
                    return false;
                else{
                    num = num/10;
                }
            }
            return true;
        }
    }
}