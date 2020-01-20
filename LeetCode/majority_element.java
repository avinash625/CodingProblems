class Solution {
    public int majorityElement(int[] nums) {
        int element  = nums[0];
        int count = 1;
        for(int iter = 1;iter< nums.length; iter++){
            if(element != nums[iter]){
                count--;
                if(count == -1){
                    element = nums[iter];
                    count = 1;
                }
            }
            else
                count++;
        }
        return element;
    }
}