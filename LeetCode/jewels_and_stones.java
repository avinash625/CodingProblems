class Solution {
    public int numJewelsInStones(String J, String S) {
        HashMap<Character,Integer> map = new HashMap<Character, Integer>();
        for( int index = 0; index < S.length(); index++){
            if(map.containsKey(S.charAt(index)) == true){
                map.put(S.charAt(index) ,map.get(S.charAt(index)) + 1);
            }else{
                map.put(S.charAt(index),1);
            }
        }
        int jewels = 0;
        for(int index = 0; index < J.length(); index++){
            if(map.containsKey(J.charAt(index)))
                jewels = jewels + map.get(J.charAt(index));
        }
        return jewels;
    }

    public int numJewelsInStones_1(String J, String S) {
        HashMap<Character, Boolean> map = new HashMap<Character, Boolean>();
        for(char ch : J.toCharArray()){
            map.put(ch,true);
        }
        int jewels = 0;
        for(char ch: S.toCharArray()){
            if(map.containsKey(ch)){
                jewels = jewels +1;
            }
        }
        return jewels;
    }
}