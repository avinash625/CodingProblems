class Solution {
    public int trap(int[] height) {
         Stack<Integer> st = new Stack<Integer>();
        if(height.length == 0) return 0;
        for(int iter = 0; iter< height.length; iter++){
            if(st.isEmpty()){
                st.push(iter);
                //System.out.println("added value "+ iter+ " to stack");
            }else if(height[st.peek()] < height[iter]){
                st.push(iter);
                //System.out.println("added value "+ iter+ " to stack");
            }
        }
        
        int total = 0, right = height[height.length-1];
        for(int iter =height.length-1; iter>=0 ; iter--){
            if(iter == st.peek()){
                //System.out.println("iter is equal to stack top ");
                right = height[st.peek()];
                //System.out.println(" right is updated to "+ right);
                st.pop();
            }else{
                if(right < height[iter]){
                    right = height[iter];
                    //System.out.println("right is udpated to " + right);
                }
                if(Math.min(height[st.peek()] , right) > height[iter]){
                    total += (Math.min(height[st.peek()], right) - height[iter]);
                    //System.out.println(" total is updated to "+ total );
                    //System.out.println(" " + Math.min(height[st.peek()], right) + " - " + height[iter] + " = " + (Math.min(height[st.peek()], right) - height[iter]));
                }
                    
            }
        }
        return total;
    }
}