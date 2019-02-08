class Solution {
    public boolean isAnagram(String s, String t) {
        HashMap<Character, Integer> h = new HashMap<Character, Integer>();
        
        int value;
        for(char c: s.toCharArray()){
            value = h.getOrDefault(c,-1);
            //System.out.println(value);
            if(value == -1){
                h.put(c,1);
            }else{
                h.put(c,(value+1));
            }
        }
        for(char c: t.toCharArray()){
            value = h.getOrDefault(c,-1);
            if(value == -1){
                return false;
            }else{
                h.put(c,(value-1));
            }
        }
        for(char i: h.keySet()){
            if(h.get(i) != 0){
                return false;
            }
        }
        return true;
    }
}