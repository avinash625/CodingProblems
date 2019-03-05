class Solution {
    public void log(String s){
        System.out.println(s);
    }
    public char findTheDifference(String s, String t) {
        if(s.length() == 0) return t.charAt(0);
        else{
            char ch;
            HashMap<Character, Integer> first = new HashMap<Character, Integer>();
            for(int iter = 0;iter< s.length(); iter++){
                ch = s.charAt(iter);
                if(first.get(ch) == null){
                    //log("adding " + ch );
                    first.put(ch, 1);
                }else{
                    first.put(ch, first.get(ch)+1);
                    //log("modified " + ch + " value to " + first.get(ch));
                }
            }
            for(int iter = 0;iter< t.length(); iter++){
                ch = t.charAt(iter);
                if(first.get(ch) == null){
                    //log("adding " + ch );
                    first.put(ch, 1);
                }else{
                    first.put(ch, first.get(ch)-1);
                    //log("modified " + ch + " value to " + first.get(ch));
                    if(first.get(ch) == 0){
                        first.remove(ch);
                        //log("removing " + ch);
                    }
                }
            }
            return first.keySet().iterator().next();
        }
    }
}