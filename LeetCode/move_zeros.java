class Solution {
    public void moveZeroes(int[] nums) {
        int writeIterator = 0;
        for(int readIterator = 0;readIterator < nums.length; readIterator++){
            if(nums[readIterator] != 0){
                nums[writeIterator] = nums[readIterator];
                writeIterator++;
            }
        }
        for(; writeIterator < nums.length; writeIterator++){
            nums[writeIterator] = 0;
        }
    }
}