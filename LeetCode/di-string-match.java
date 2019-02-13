class Solution {
    public int[] diStringMatch(String S) {
        int writeCount = 0;
        int length = S.length();
        int[] result = new int[S.length()+1];
        char[] c = S.toCharArray();
        for(int iter = 0;iter< length;iter++){
            if(c[iter] == 'I'){
                result[iter] = writeCount++;
            }
        }
        result[length] = writeCount++;
        for(int iter = length -1;iter>= 0;iter--){
            if(c[iter] == 'D'){
                result[iter] = writeCount++;
            }
        }
        return result;
    }
}