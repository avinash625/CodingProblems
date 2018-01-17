class Solution {
public:
    bool isPowerOf2(int n){
        if((n&(n-1)) == 0)
            return true;
        return false;
    }
    bool hasAlternatingBits(int n) {
        return isPowerOf2(((n>>1)^n)+1);
    }
};
