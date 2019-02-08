class Solution {
    public boolean backspaceCompare(String S, String T) {
        Stack<Character> s = new Stack<Character>();
        Stack<Character> t = new Stack<Character>();
        
        for(char c: S.toCharArray()){
            if(c != '#'){
                s.push(c);
            }else{
                if(!s.empty())
                    s.pop();
            }
        }
        
        for(char c: T.toCharArray()){
            if(c != '#'){
                t.push(c);
            }else{
                if(!t.empty())
                    t.pop();
            }
        }
        while(!s.empty() && !t.empty()){
            if(s.peek() != t.peek()){
                return false;
            }else{
                s.pop();
                t.pop();
            }
        }
        if( !s.empty() || !t.empty()){
            return false;
        }
        return true;
    }
}