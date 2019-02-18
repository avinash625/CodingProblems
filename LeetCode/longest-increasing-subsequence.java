class Solution {
    public int lengthOfLIS(int[] nums) {
        if(nums.length == 0) return 0;
        int[] result = new int[nums.length];
        Arrays.fill(result,1);
        result[0] = 1;
        for(int i = 0;i < nums.length; i++){
            for(int j = 0;j<i;j++){
                if(nums[i] > nums[j]){
                    if(result[j]+ 1 > result[i]){
                        result[i]  = result[j]+1;
                    }
                }
            }
        }
        
        int maximum = 0;
        for(int iter = 0;iter< nums.length;iter++){
            if(maximum < result[iter])
                maximum =result[iter];
        }
        return maximum;
    }
}