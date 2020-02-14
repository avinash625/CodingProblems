class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int writeIter = m+n-1;
        
        int read1 = m-1;
        int read2 = n-1;
        
        while(read1 >=0 && read2 >= 0){
            if(nums1[read1] > nums2[read2]){
                nums1[writeIter] = nums1[read1];
                read1--;
            }else{
                nums1[writeIter] = nums2[read2];
                read2--;
            }
            writeIter--;
        }
        
        while(read1 >= 0){
            nums1[writeIter] = nums1[read1];
            writeIter--;
            read1--;
        }
        while(read2 >=0){
            nums1[writeIter] = nums2[read2];
            writeIter--;
            read2--;
        }
    }
}