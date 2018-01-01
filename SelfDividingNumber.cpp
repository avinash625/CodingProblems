class Solution {
public:
    bool isSelfDividingNumber(int num){
        int temp = num;
        int d;
        while(temp>9){
            d = temp%10;
            if(d == 0)
                return false;
            else if(num%d != 0)
                return false;
            else{
                temp = temp/10;
            }
        }
        if(temp == 0 || num%temp!=0){
            return false;
        }
        return true;
    }
    
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for(int iter = left; iter<= right; iter++){
            if(isSelfDividingNumber(iter)){
                result.push_back(iter);
            }
        }
        return result;
    }
};
