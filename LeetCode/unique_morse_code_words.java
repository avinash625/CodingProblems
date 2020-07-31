class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        HashMap<String, Boolean> map = new HashMap<String, Boolean>();
        String[] mapping = new String[]{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        for(String word : words){
            StringBuffer sb = new StringBuffer();
            for(char ch : word.toCharArray()){
                sb.append(mapping[ch-'a']);
            }
            if(map.containsKey(sb.toString()) == false){
                map.put(sb.toString(), true);
            }
        }
        return map.size();
    }
}