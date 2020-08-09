class Solution {
    public int[] diStringMatch(String S) {
        int maxNumber = S.length();
        int increment = 0;
        int[] result = new int[S.length()+1];
        int writeIter = 0;
        for(char ch: S.toCharArray()){
            if(ch == 'I'){
                result[writeIter] = increment;
                increment++;
                writeIter++;
            }else{
                result[writeIter] = maxNumber;
                maxNumber--;
                writeIter++;
            }
        }
        if(S.charAt(S.length()-1) == 'I'){
            result[S.length()] = increment;
        }else
            result[S.length()] = maxNumber;
        return result;
    }
}