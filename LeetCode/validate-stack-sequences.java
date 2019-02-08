class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer> st = new Stack<Integer>();
        if(pushed.length != popped.length){
            return false;
        }
        int pushedIter = 0;
        int poppedIter = 0;
        
        while(pushedIter < pushed.length){
            if(pushed[pushedIter] == popped[poppedIter]){
                //System.out.println("passing on value " + pushed[pushedIter]);
                pushedIter++;
                poppedIter++;
                while(!st.empty() && st.peek() == popped[poppedIter] && poppedIter< popped.length){
                        //System.out.println("popping "+ popped[poppedIter] + " from stack");
                        st.pop();
                        poppedIter++;
                    }
            }else{
                while(pushedIter < pushed.length && pushed[pushedIter] != popped[poppedIter]){
                    //System.out.println("pushing "+ pushed[pushedIter] + " into stack");
                    st.push(pushed[pushedIter]);
                    pushedIter++;
                }
                if(st.peek() == popped[poppedIter]){
                    while(!st.empty() && st.peek() == popped[poppedIter] && poppedIter< popped.length){
                        //System.out.println("popping "+ popped[poppedIter] + " from stack");
                        st.pop();
                        poppedIter++;
                    }
                }
            }
        }
        if(poppedIter < popped.length){
            while(!st.empty() && st.peek() == popped[poppedIter]  && poppedIter< popped.length){
                //System.out.println("popping "+ popped[poppedIter] + " from stack");
                st.pop();
                poppedIter++;
            }
        }
        if(st.empty())
            return true;
        return false;
    }
}