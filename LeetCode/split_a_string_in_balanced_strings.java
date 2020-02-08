class Solution {
    public int balancedStringSplit(String s) {
        Stack<Character> st = new Stack<Character>();
        int balancedStrings = 0;
        for(int iter =0; iter< s.length(); iter++){
            if(s.charAt(iter) == 'R'){
                if(!st.empty() && st.peek() == 'L')
                    st.pop();
                else
                    st.push('R');
            }else if(s.charAt(iter) == 'L'){
                if(!st.empty() && st.peek() == 'R')
                    st.pop();
                else
                    st.push('L');
            }
            if(st.empty() == true)
                balancedStrings++;
        }
        return balancedStrings;
    }
}