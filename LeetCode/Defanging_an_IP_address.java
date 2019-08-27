class Solution {
    public String defangIPaddr(String address) {
        StringBuffer sb = new StringBuffer();
        int readIndex = 0;
        while(readIndex < address.length()){
            if(address.charAt(readIndex) == '.'){
                sb.append("[.]");
                readIndex++;
            }
            else{
                sb.append(address.charAt(readIndex));
                readIndex++;
            }
        }
        return sb.toString();
    }
}