class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        ArrayList<Boolean> result = new ArrayList<Boolean>();
        int maximum = Integer.MIN_VALUE;
        for(int candy: candies){
            if(candy > maximum){
                maximum = candy;
            }
        }
        for(int candy: candies){
            if(candy + extraCandies >= maximum){
                result.add(true);
            }else{
                result.add(false);
            }
        }
        return result;
    }
}