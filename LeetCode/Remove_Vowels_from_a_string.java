class Solution {
    public String removeVowels(String S) {
        StringBuffer sb = new StringBuffer();
        int readIndex = 0;
        while(readIndex < S.length()){
            char currentChar = S.charAt(readIndex);
            if(currentChar == 'a' || currentChar == 'e' || currentChar == 'i' || currentChar == 'o' || currentChar == 'u'){
                readIndex = readIndex + 1;
            }else{
                sb.append(S.charAt(readIndex));
                readIndex = readIndex +1;
            }
        }
        return sb.toString();
    }
}