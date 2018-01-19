class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int> mapping;
        for(int iter = 0;s[iter];iter++){
            mapping[s[iter]] = mapping[s[iter]] +1; 
        }
        for(int iter =0; s[iter];iter++){
            if(mapping[s[iter]] == 1){
                return iter;
            }
        }
        return -1;
    }
};
