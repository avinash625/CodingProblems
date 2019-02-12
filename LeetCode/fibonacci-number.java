class Solution {
    public int fib(int N) {
        if(N == 0 || N == 1)
            return N;
        int a = 0;
        int b = 1;
        int c = 0 ;
        while(--N > 0){
            c = a+b;
            a = b;
            b = c;
        }
        return c;
    }
}