class Solution {
    public int[] anagramMappings(int[] A, int[] B) {
        Map<Integer, Integer> mapping = new HashMap<Integer, Integer>();
        for(int iter = 0; iter< B.length; iter++){
            mapping.put(B[iter], iter);
        }
        int[] result = new int[A.length];
        for(int iter = 0; iter< A.length; iter++){
            result[iter] = mapping.get(A[iter]);
        }
        return result;
    }
}