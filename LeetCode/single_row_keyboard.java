class Solution {
    public int calculateTime(String keyboard, String word) {
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();
        for(int index =0; index < keyboard.length(); index++){
            map.put(keyboard.charAt(index), index);
        }
        
        int cost = 0;
        int previousPosition = 0;
        for(int iter =0; iter< word.length(); iter++){
            cost += Math.abs(previousPosition - map.get(word.charAt(iter)));
            previousPosition = map.get(word.charAt(iter));
        }
        return cost;
    }
}