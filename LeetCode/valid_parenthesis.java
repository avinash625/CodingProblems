class Solution {
public  boolean isValid(String s) {
        Stack<Character> st = new Stack<Character>();
        for(int iter = 0;iter<s.length(); iter++){
            char ch = s.charAt(iter);
            if(ch == '(' || ch == '['|| ch == '{'){
                st.push(ch);
            }else if(ch == ')' && !st.isEmpty() && st.peek() == '('){
                st.pop();
            }else if(ch == ']' && !st.isEmpty() && st.peek() == '['){
                st.pop();
            }else if(ch == '}' && !st.isEmpty() && st.peek() == '{'){
                st.pop();
            }else{
                return false;
            }
        }
        if(st.isEmpty()){
            return true;
        }
        return false;
    }
};