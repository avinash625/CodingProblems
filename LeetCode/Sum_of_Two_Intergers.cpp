class Solution {
public:
    int getSum(int a, int b) {
        return (((a&b) << 1)+ (a^b));
    }
};
