class Solution {
    public int lengthOfLongestSubstring(String s) {
        int maximumLength = 0;
        int repeatingCharacters = 0;
        int windowLength = 0;
        int windowStartingPoint = 0;
        Map<Character,Integer> window = new HashMap<Character, Integer>();
        
        for(char c : s.toCharArray()){
            if(window.get(c) == null){
                window.put(c,1);
                windowLength++;
                //System.out.println("added new key : "+ c + " with value of 1");
            }else{
                if(window.get(c) == 1)
                    repeatingCharacters++;
                window.put(c, window.get(c)+1);
                //System.out.println("updated value of "+ c + " with value : "  + window.get(c));
                windowLength++;
                //System.out.println("repeatinCharacters : " + repeatingCharacters + "\n windowLength : " + windowLength);
            }
            if(repeatingCharacters == 0){
                if(windowLength > maximumLength){
                    maximumLength = windowLength;
                }
            }else{
                while(repeatingCharacters > 0){
                    char ch = s.charAt(windowStartingPoint);
                    if(window.get(ch)>1){
                        windowStartingPoint++;
                        window.put(ch, window.get(ch) -1);
                        //System.out.println("updated value of "+ ch + " with value : " + window.get(ch));
                        if(window.get(ch) == 1)
                            repeatingCharacters--;
                        windowLength--;
                    }else{
                        windowLength--;
                        windowStartingPoint++;
                        window.put(ch,0);
                        //System.out.println("the value of " + s.charAt(windowStartingPoint) + " is "+ window.get(ch));
                    }
                    //System.out.println("repeatinCharacters : " + repeatingCharacters + "\n windowLength : " + windowLength);
                }
            }
        }
        return maximumLength;
    }
}