class Solution {
    public boolean isPalindrome(String s) {
        int start = 0;
        int end = s.length()-1;
        char[]  c = s.toLowerCase().toCharArray();
        
        while(start <= end){
            while(start <= end && !((c[start] >= 'a' && c[start] <= 'z') || (c[start] >= '0' && c[start] <= '9')) ){
                //System.out.println("moving from " + c[start]);
                start++;
            }
            while(start <= end && !((c[end] >= 'a' && c[end] <= 'z') || (c[end] >= '0' && c[end] <= '9')) ){
                //System.out.println("moving from " + c[end]);
                end--;
            }
            if(start > end){
                return true;
            }
            if(c[start] != c[end]){
                //System.out.println(c[start] + "  !=  " + c[end]);
                return false;
            }
            else{
                //System.out.println(c[start] + "  ==  " + c[end]);
                start++;
                end--;
            }
        }
        return true;
    }
}