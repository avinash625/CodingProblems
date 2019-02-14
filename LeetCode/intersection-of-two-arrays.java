class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        int index;
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        ArrayList<Integer> result = new ArrayList<Integer>();
        for(int val: nums1){
            index = Arrays.binarySearch(nums2,val);
            //System.out.println("searching for "+ val + " in nums2 "+ " found at "+ index);
            if(index >= 0){
                Object[] resultarray = result.toArray();
                Arrays.sort(resultarray);
                index = Arrays.binarySearch(resultarray,val);
                //System.out.println("searching for "+ val + " in result "+ " found at "+ index);
                if(index < 0){
                    result.add(val);
                    //System.out.println("adding "+ val + " to result ");
                }
            }
        }
        return result.stream().filter(t -> t != null).mapToInt(t -> t).toArray();
    }
}