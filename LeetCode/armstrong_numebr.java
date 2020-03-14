class Solution {
    public boolean isArmstrong(int N) {
        int total = 0;
        int number = N;
        int length = (Integer.toString(N)).length();
        //System.out.println("length is "+ length);
        while(N>0){
            total += Math.pow(N%10 , length);
            //System.out.println("value updated to "+ total);
            N = N/10;
        }
        //System.out.println("value is "+ total + " with number as "+ number);
        return (number == total);
    }
}