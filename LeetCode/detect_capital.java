class Solution {
    public boolean detectCapitalUse(String word) {
        if(word.length() == 1) return true;
        if(word.charAt(0) >='A' && word.charAt(0) <='Z'){
            return checklowercase(word.substring(1)) || checkuppercase(word.substring(1));
        }else{
            return checklowercase(word.substring(1));
        }
    }
    
    public boolean checklowercase(String word){
        // System.out.println(word);
        return word.equals(word.toLowerCase());
    }
    
    public boolean checkuppercase(String word){
        // System.out.println(word);
        return word.equals(word.toUpperCase());
    }
}