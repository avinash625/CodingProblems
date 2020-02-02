class Solution {
    public boolean canJump(int[] nums) {
        boolean[] status = new boolean[nums.length];
        status[nums.length-1] = true;
        int safePosition = nums.length-1;
        for(int iter = nums.length-2; iter >=0; iter--){
                if(nums[iter] >= 1 && status[iter+1] == true){
                    status[iter] = true;
                    safePosition = iter;
                }else if(nums[iter] >= 1){
                    if(safePosition - iter <= nums[iter]){
                        safePosition = iter;
                        status[iter] = true;
                    }else{
                        status[iter] = false;
                    }
                }else{
                    status[iter] = false;
                }
        }
        
        return status[0];
    }
}