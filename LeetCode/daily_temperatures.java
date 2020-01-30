class Solution {
    public int[] dailyTemperatures(int[] T) {
        int[] result = new int[T.length];
        
        Stack<Integer> st = new Stack<Integer>();
        st.push(T.length-1);
        result[T.length-1] = 0;
        for(int iter = ( T.length-2); iter >= 0 ; iter--){
            if(st.isEmpty()){
                result[iter] = 0;
            }else if(T[iter] >= T[st.peek()]){
                int previousHigh = st.peek();
                
                while(!st.isEmpty() && T[iter] >= T[st.peek()]){
                    previousHigh = st.pop();
                }
                if(st.isEmpty()){
                    result[iter] = 0;
                }else{
                    
                    result[iter] = st.peek()-iter;
                }
            }else{
                result[iter] = 1;
            }
            st.push(iter);
        }
        return result;
    }
}