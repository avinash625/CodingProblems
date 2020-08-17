class Solution {
    public int maxProduct(int[] nums) {
        int first, second;
        if(nums[0] > nums[1]){
            first = nums[0];
            second = nums[1];
        }else{
            first= nums[1];
            second = nums[0];
        }
        for(int iter = 2; iter< nums.length; iter++){
            if(nums[iter] > first){
                second = first;
                first = nums[iter];
            }else if(nums[iter] > second){
                second = nums[iter];
            }
        }
        return (first-1)* (second-1);
    }
}