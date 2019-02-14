class Solution {
    public boolean checkPerfectNumber(int num) {
        if(num <= 1) return false;
        long  sum = -1 * num;
        long  n = num;
        for(int iter = 1;iter<= Math.sqrt(num);iter++ ){
            if(n%iter == 0){
                //System.out.println("adding "+ n/iter);
                sum += n/iter;
                sum += n/(n/iter);
                //System.out.println("adding "+ n/(n/iter));
            }
        }
        //System.out.println("Sum is "+ sum);
        if(sum == n)
            return true;
        return false;
    }
}