class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        ArrayList<String> result = new ArrayList<String>();
        for(String word: words){
            
            if(findAndReplacePatternUtil(word,pattern) == true){
                result.add(word);
            }
        }
        return result;
    }
    
    private boolean findAndReplacePatternUtil(String word, String pattern){
        if(word.length() != pattern.length()){
            return false;
        }
        HashMap<Character, Character> h = new HashMap<Character, Character>();
            char[] c = pattern.toCharArray();
            char[] w = word.toCharArray();
            boolean isValid = true;
            for(int iter = 0;iter< pattern.length();iter++){
                if(h.get(c[iter]) == null){
                    h.put(c[iter], w[iter]);
                }else{
                    if(h.get(c[iter]) != w[iter]){
                        isValid = false;
                        break;
                    }
                }
            }
        h.clear();
            for(int iter = 0;iter< word.length();iter++){
                if(h.get(w[iter]) == null){
                    h.put(w[iter], c[iter]);
                }else{
                    if(h.get(w[iter]) != c[iter]){
                        isValid = false;
                        break;
                    }
                }
            }
            return isValid;
    }
}