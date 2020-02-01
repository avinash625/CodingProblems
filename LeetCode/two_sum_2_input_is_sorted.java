class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int[] result = new int[2];
        
        int first=0, second = numbers.length-1;
        
        while(first < second){
            if(numbers[first]+ numbers[second] < target){
                first++;
            }else if(numbers[first] + numbers[second] > target){
                second--;
            }else{
                result[0] = first+1;
                result[1] = second+1;
                break;
            }
        }
        return result;
    }
}