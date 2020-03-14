class Solution {
    public int arrayPairSum(int[] nums) {
        Arrays.sort(nums);
        int total = 0;
        for(int iter = 0; iter< nums.length; iter+=2){
            total+= nums[iter];   
        }
        return total;
    }
}