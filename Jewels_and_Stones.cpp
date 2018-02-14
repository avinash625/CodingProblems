class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char, bool> mapping;
        for(int iter= 0;J[iter];iter++){
            mapping[J[iter]] = true;
        }
        int count = 0;
        for(int iter =0;S[iter];iter++){
            if(mapping[S[iter]])
                count++;
        }
        return count;
    }
};
