class Solution {
    public int countPrimeSetBits(int L, int R) {
        boolean[] primes = new boolean[25];
        primes[0] = false;
        primes[1] = false;
        constructPrimes(primes,25);
        // for(int iter = 0;iter< 25; iter++){
        //     if(primes[iter])
        //         System.out.println(iter);
        // }
        int count = 0;
        for(int iter = L; iter<= R; iter++){
            if(primes[Integer.bitCount(iter)]  == true){
                count++;
            }
        }
        return count;
    }
    
    public void constructPrimes(boolean[] primes, int count){
        for(int iter = 2; iter< count; iter++){
            if(isPrime(iter) == true){
                primes[iter] = true;
            }else{
                primes[iter] = false;
            }
        }
    }
    
    public boolean isPrime(int n){
        int count = 0;
        for(int iter = 2; iter<= Math.sqrt(n); iter++){
            if(n%iter == 0) return false;
        }
        return true;
    }
    
    
}