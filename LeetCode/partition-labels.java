class Solution {
    public List<Integer> partitionLabels(String S) {
        ArrayList<Integer> result = new ArrayList<Integer>();
        int starting = 0;
        int length = S.length();
        if(length == 0) return result;
        HashMap<Character,Integer> actualHashMap = new HashMap<Character,Integer>();
        HashMap<Character,Integer> currentHashMap = new HashMap<Character,Integer>();
        for(int index = 0; index < length; index++){
            if(actualHashMap.get(S.charAt(index)) == null){
                actualHashMap.put(S.charAt(index), 1);
            }else{
                actualHashMap.put(S.charAt(index), actualHashMap.get(S.charAt(index)) + 1);
            }
        }
        int position = 0;
        while(position < length){
            char ch = S.charAt(position);
            if(currentHashMap.get(ch) == null){
                currentHashMap.put(ch, 1);
            }else{
                currentHashMap.put(ch, currentHashMap.get(ch) + 1);
            }
            if( actualHashMap.get(ch) - currentHashMap.get(ch) == 0){
                currentHashMap.remove(ch);
                if(currentHashMap.size() == 0){
                    result.add(position - starting + 1);
                    starting = position +1;
                }
            }
            position++;
        }
        return result;
    }
}