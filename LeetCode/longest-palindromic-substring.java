class Solution {
    public String longestPalindrome(String s) {
        if(s.length() == 0) return "";
        int left = 0, right = 0;
        int size =s.length();
        int[] lps = new int[s.length()];
        Arrays.fill(lps,1);
        for(int index = 0;index < s.length(); index++){
            left = index-1;
            right = index+1;
            while(left>=0 && right < size && s.charAt(left) == s.charAt(right)){
                left--;
                right++;
            }
            if(left == -1){
                lps[index] = right;
            }else if(right == size){
                lps[index] = right-left-1;
            }else{
                lps[index] = right-left-1;
            }
        }
        for(int index = 0; index < size; index++){
            left = index-1;
            right = index;
            while(left>=0 && right < size && s.charAt(left) == s.charAt(right)){
                left--;
                right++;
            }
            if(left == -1){
                if(lps[index] < right){
                    lps[index] = right;
                }
            }else if(right == size){
                if(lps[index] < right-left-1){
                    lps[index] = right-left-1;
                }
            }
            else{
                if(lps[index] < right-left-1){
                    lps[index] = right-left-1;
                }
            }
        }
        for(int iter =0;iter< size;iter++){
        }
        int maximum = lps[0];
        int position = 0;
        for(int iter = 0;iter< size;iter++){
            if(lps[position] <= lps[iter]){
                position = iter;
                maximum = lps[position];
            }
        }
        return s.substring(position-(maximum/2), position + ((maximum+1)/2));
    }
}