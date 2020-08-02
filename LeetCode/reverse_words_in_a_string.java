import java.util.StringTokenizer;
class Solution {
    public String reverseWords(String s) {
        StringTokenizer st = new StringTokenizer(s);
        StringBuffer sb = new StringBuffer();
        while(st.hasMoreTokens()){
            String word = st.nextToken();
            for(int iter = word.length()-1; iter>= 0; iter--){
                sb.append(word.charAt(iter));
            }
            if(st.hasMoreTokens()){
                sb.append(" ");
            }
        }
        return sb.toString();
    }
}