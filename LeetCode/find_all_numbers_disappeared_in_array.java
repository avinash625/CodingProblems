class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        int currentValue;
        ArrayList<Integer> result = new ArrayList<Integer>();
        for(int iter = 0;iter< nums.length;iter++){
            currentValue = nums[iter];
            //System.out.println("currentValue : "+ currentValue);
            if(currentValue < 0){
                currentValue = (currentValue * -1);
                //System.out.println("making currentValue as positive");
            }
            if(nums[currentValue-1] > 0){
                nums[currentValue -1 ] = nums[currentValue-1]* -1;
            }
        }
        for(int iter = 0;iter< nums.length; iter++){
            if(nums[iter]>0){
                result.add(iter+1);
            }
        }
        return result;
    }
}