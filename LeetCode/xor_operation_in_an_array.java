class Solution {
    public int xorOperation(int n, int start) {
        int xor = 0;
        for(; n > 0; n--, start+=2){
            xor = xor ^ (start);
        }
        return xor;
    }
}