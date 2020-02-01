class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] values = new int[nums.length];
        for(int iter = 0;iter< nums.length; iter++){
            values[iter] = nums[iter];
        }
        
        int first = 0, second = nums.length-1;
        Arrays.sort(values);
        while(first < second){
            if(values[first] + values[second] < target){
                first++;
            }else if(values[first] + values[second] > target){
                second--;
            }else{
                return getIndexof(nums,values[first], values[second]);
            }
        }
        return nums;
        
    }
    
    public int[] getIndexof(int[] nums, int first, int second){
        int[] result = new int[2];
        Arrays.fill(result,-1);
        int iter = 0;
        for(;iter<nums.length;iter++){
            if(nums[iter] == first && result[0] == -1){
                result[0] = iter;
            }else if(nums[iter] == second){
                result[1] = iter;
            }
        }
        return result;
    }
    
}