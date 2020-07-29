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

    public String removeVowels_1(String S) {
        Set<Character> hashSet = new HashSet<Character>();
        hashSet.add('a');
        hashSet.add('e');
        hashSet.add('i');
        hashSet.add('o');
        hashSet.add('u');
        StringBuffer sb = new StringBuffer();
        for(char ch: S.toCharArray()){
            if(!hashSet.contains(ch)){
                sb.append(ch);
            }
        }
        return sb.toString();
    }
}