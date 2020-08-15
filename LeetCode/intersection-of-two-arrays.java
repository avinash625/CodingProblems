class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        Set<Integer> set = new HashSet<Integer>();
        ArrayList<Integer> result = new ArrayList<Integer>();
        for(int i1 = 0, i2 = 0; i1< nums1.length && i2 < nums2.length;){
            if(nums1[i1] == nums2[i2]){
                if(!set.contains(nums1[i1])){
                    set.add(nums1[i1]);
                    result.add(nums1[i1]);
                }
                i1++;
                i2++;

            }else if(nums1[i1] > nums2[i2]){
                i2++;
            }else if(nums1[i1] < nums2[i2]){
                i1++;
            }
        }
        return result.stream().mapToInt(i -> i).toArray();
    }
}