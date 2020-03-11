class Solution {
    public String shiftingLetters(String S, int[] shifts) {
        int charSize = 26;
        String str = "abcdefghijklmnopqrstuvwxyz";
        shifts[shifts.length-1] = shifts[shifts.length-1]%26;
        for(int iter = shifts.length-2; iter >= 0; iter--){
            shifts[iter] = (shifts[iter+1] + (shifts[iter])%charSize)%charSize;
            //System.out.println(iter + " position has " + shifts[iter]);
        }
        String sb = new String();
        
        for(int iter = 0; iter< shifts.length; iter++){
            sb = sb + (str.charAt((str.indexOf(S.charAt(iter)) + shifts[iter])%charSize));
        }
        return sb;
    }
}