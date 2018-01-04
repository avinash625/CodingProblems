class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int single = false;
        if(bits.back() == 1)
            return false;
        else{
            int iter = 0;
            for(int iter = 0;iter<bits.size();){
                if(bits[iter] == 1){
                    iter += 2;
                    single = false;
                }
                else{
                    iter = iter+= 1;
                    single = true;
                }
            }
        }
        return single;
    }
};
