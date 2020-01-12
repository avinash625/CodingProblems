class Solution {
    public String defangIPaddr(String address) {
        StringBuffer finalIpv4 = new StringBuffer();
        for(Integer i = 0; i < address.length(); i++){
            if(address.charAt(i) == '.'){
                finalIpv4.append("[.]");
            }else{
                finalIpv4.append(address.charAt(i));
            }
        }
        return finalIpv4.toString();
    }
}