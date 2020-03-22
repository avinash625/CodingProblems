class Solution {
    public int sumFourDivisors(int[] nums) {
        int sum = 0;
        for(int iter = 0; iter< nums.length; iter++){
            int count = 0;
            int localCount = 0;
            for(int i = 1; i< Math.sqrt(nums[iter]); i++){
                if(nums[iter] % i == 0){
                    count += 2;
                    localCount += (i + (nums[iter]/ i)) ;
                    //System.out.println(" " + i + " is a divisor, adding values " + i + " " + (nums[iter]/i));
                }
            }
            if(nums[iter]/ Math.sqrt(nums[iter]) == Math.ceil(Math.sqrt(nums[iter]))){
                count++;
                localCount += Math.sqrt(nums[iter]);
                //System.out.println(" sqrt is same so ");
                //System.out.println(" "  + nums[iter]/ Math.sqrt(nums[iter]) + " and value of " + Math.sqrt(nums[iter]));
            }
            //System.out.println(" count : " + count + " value : " + localCount  + " for " + nums[iter]);
            if(count == 4){
                sum += (localCount);
            }
        }
        return sum;
    }
}