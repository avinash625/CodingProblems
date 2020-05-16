import java.text.*;

class Solution {
    public boolean isAnagram(String s, String t) {
        HashMap<Character, Integer> map = new HashMap<Character, Integer>(); 
        CharacterIterator it = new StringCharacterIterator(s);
        while(it.current() != CharacterIterator.DONE){
            if(map.containsKey(it.current())){
                map.put(it.current(), map.get(it.current())+1);
            }else{
                map.put(it.current(), 1);
            }
            it.next();
        }
        it = new StringCharacterIterator(t);
        while(it.current() != CharacterIterator.DONE){
            if(map.containsKey(it.current())){
                map.put(it.current(), map.get(it.current())-1);
                if(map.get(it.current()) == 0){
                    map.remove(it.current());
                }
            }else{
                return false;
            }
            it.next();
        }
        if(map.size() == 0){
            return true;
        }
        return false;
    }
}