class Solution {
    public int countLetters(String S) {
        int startIndex = 0;
        int endIndex, result = 0;
        char ch;
        if(S.length() == 0) return 0;
        else{
            ch = S.charAt(0);
            for(int iter = 1; iter< S.length(); iter++){
                if(S.charAt(iter) != ch){
                    System.out.println("start: "+ startIndex + " iter: "+ iter + " with value " + ((iter-startIndex)*(iter-startIndex+1))/2);
                    result += ((iter-startIndex)*(iter-startIndex+1))/2;
                    startIndex = iter;
                    ch = S.charAt(iter);
                }
            }
            result += ((S.length() - startIndex) * (S.length()-startIndex+1)) /2;
        }
        return result;
    }
}