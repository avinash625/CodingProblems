class Solution {
    public int[] shuffle(int[] nums, int n) {
        int[] result = new int[n*2];
        for(int first = 0, second = n, write =0 ; first < n; first++, second++, write+=2){
            result[write] = nums[first];
            result[write+1] = nums[second];
        }
        return result;
    }
}