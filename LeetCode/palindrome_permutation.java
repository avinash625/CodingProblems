class Solution {
    public boolean canPermutePalindrome(String s) {
        int oddValues = 0;
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();
        for(char ch: s.toCharArray()){
            if(map.containsKey(ch)){
                if(map.get(ch)%2 == 1){
                    oddValues -= 1;
                }else{
                    oddValues += 1;
                }
                map.put(ch, map.get(ch) + 1);
            }else{
                map.put(ch,1);
                oddValues += 1;
            }
        }
        if(oddValues >=2) return false;
        return true;
    }
}