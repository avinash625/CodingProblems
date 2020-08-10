class Solution {
    public int maximum69Number (int num) {
        String s = Integer.toString(num);;
        StringBuffer sb = new StringBuffer(s);
        int index = sb.indexOf("6");
        if(index >= 0)
            sb.replace(sb.indexOf("6"), sb.indexOf("6")+1, "9");
        return Integer.parseInt(sb.toString());
    }
}