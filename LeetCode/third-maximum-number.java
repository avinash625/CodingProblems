class Solution {
    public int thirdMax(int[] nums) {
        HashSet<Integer> set = new HashSet<Integer>();
        for(int val: nums){
            set.add(val);
        }
        if(set.size() < 3){
            int maximum = Integer.MIN_VALUE;
            int value;
            Iterator iter = set.iterator();
            while(iter.hasNext()){
                value = (Integer)(iter.next());
                if(maximum < value){
                    maximum = value;
                }
            }
            return maximum;
        }
        else{
            int[] array = set.stream().mapToInt(Number::intValue).toArray();
            Arrays.sort(array);
            return array[array.length-3];
        }
    }
}