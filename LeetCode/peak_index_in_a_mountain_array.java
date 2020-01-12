class Solution {
    public int peakIndexInMountainArray(int[] A) {
        int highest = -1;
        int highestIndex = -1;
        for(int iter = 0;iter< A.length; iter++){
            if(A[iter] > highest){
                highestIndex = iter;
                highest = A[iter];
            }
        }
        return highestIndex;
    }
}