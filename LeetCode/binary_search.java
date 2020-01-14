class Solution {
    public int search(int[] nums, int target) {
        int start = 0;
        int end = nums.length -1;
        int middle = start + (end-start)/2;
        while(start < end){
            middle = start + (end-start)/2;
            if(nums[middle] == target)
                return middle;
            else if(nums[middle] > target)
                end = middle-1;
            else
                start = middle + 1;
        }
        if(start == end && nums[start] == target) return start;
        return -1;
    }
}