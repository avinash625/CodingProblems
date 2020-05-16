class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        HashMap<Integer, Boolean> map = new HashMap<Integer, Boolean>();
        if(nums.length == 0 || k == 0) return false;
        int current_window = 0;
        for(int iter = 0; iter< nums.length; iter++){
            if(map.containsKey(nums[iter])) return true;
            if(map.size() < k){
                //System.out.println("Inserting " + nums[iter]);
                map.put(nums[iter], true);
                //System.out.println("window size: " + map.size());
            }else{
                //System.out.println(" removing :" + nums[iter-k]);
                map.remove(nums[iter-k]);
                //System.out.println("inserting " + nums[iter]);
                map.put(nums[iter], true);
                //System.out.println("window size: " + map.size());
            }
        }
        return false;
    }
}