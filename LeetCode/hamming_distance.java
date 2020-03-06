class Solution {
    public int hammingDistance(int x, int y) {
        int value = (x^y);
        int count = 0;
        while(value > 0){
            count += (value & 1);
            value = value/2;
        }
        return count;
    }
}