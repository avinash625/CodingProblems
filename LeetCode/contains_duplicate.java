class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashMap<Integer, Boolean> map = new HashMap<Integer, Boolean>();
        for(int current_number : nums){
            if(map.containsKey(current_number)) return true;
            else{
                map.put(current_number, true);
            }
        }
        return false;
    }
}