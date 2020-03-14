class Solution {
    public void reverseString(char[] s) {
        int start = 0, end = s.length-1;
        char ch;
        while(start < end){
            ch = s[start];
            s[start] = s[end];
            s[end] = ch;
            start++;
            end--;
        }
    }
}