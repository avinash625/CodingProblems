class Solution {
    public int[] sortedSquares(int[] A) {
        int[] result = new int[A.length];
        for(int iter = 0; iter< A.length; iter++){
            result[iter] = A[iter] * A[iter];
        }
        Arrays.sort(result);
        return result;
    }
}