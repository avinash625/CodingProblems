class Solution {
    public String removeOuterParentheses(String S) {
        StringBuffer sb = new StringBuffer();
        Stack<Character> st = new Stack<Character>();
        for(char ch: S.toCharArray()){
            if(ch == '('){
                if(!st.isEmpty() && st.peek() == '(')
                    sb.append("(");
                st.push('(');
                
            }else if(ch == ')'){
                if(st.size() == 1 && st.peek() == '('){
                    st.pop();
                }else{
                    st.pop();
                    sb.append(")");
                }
            }
        }
        return sb.toString();
    }
}