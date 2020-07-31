class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
        ArrayList<Integer> target = new ArrayList<Integer>();
        for(int iter = 0; iter< nums.length; iter++){
            int position = index[iter];
            int val = nums[iter];
            target.add(position, val);
        }
        return target.stream().mapToInt(i -> i).toArray();
    }
}