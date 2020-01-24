class Solution {
    public int[] decompressRLElist(int[] nums) {
        ArrayList<Integer> arr = new ArrayList<Integer>();
        int value, frequency;
        for(int iter = 0; iter < nums.length; ){
            frequency = nums[iter];
            value = nums[iter+1];
            for(int i = 0; i< frequency; i++){
                arr.add(value);
            }
            iter = iter+2;
        }
        int[] result = new int[arr.size()];
        for(int iter = 0;iter< arr.size(); iter++){
            result[iter] = arr.get(iter);
        }
        return result;
    }
}