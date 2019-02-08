class Solution {
    public int repeatedNTimes(int[] A) {
        int a =-1;
        int b = -1;
        int c = -1;
        
        for(int val: A){
            if(a == val) return a;
            if(b == val) return b;
            if(c == val) return c;
            
            a = b;
            b = c;
            c = val;
        }
        return 0;
    }
}