class Solution {
public:
    int climbStairs(int n) {
        vector<int> result(n+2);
        result[0] = 1;
        result[1] = 1;
        result[2] = 2;
        for(int iter = 3;iter<=n;iter++){
            result[iter] = result[iter-1]+result[iter-2];
        }
        return result[n];
    }
};
