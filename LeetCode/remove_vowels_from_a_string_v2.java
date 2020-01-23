class Solution {
    public String removeVowels(String S) {
        StringBuffer sb = new StringBuffer();
        for(int iter = 0;iter< S.length(); iter++){
            char currentChar = S.charAt(iter);
            if(!(currentChar == 'a' || currentChar == 'e' || currentChar == 'i' || currentChar == 'o' || currentChar == 'u')){
                sb.append(currentChar);
            }
        }
        return sb.toString();
    }
}