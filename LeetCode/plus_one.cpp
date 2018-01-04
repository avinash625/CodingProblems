class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int arraySize = digits.size();
        int iter = arraySize-1;
        
        while(iter >= 0 && carry){
            
            digits[iter] = digits[iter]+ carry;
            carry = (digits[iter])/10;
            digits[iter] = digits[iter]%10;
            iter--;
        }
        if(carry == 1){
            digits.insert(digits.begin(),carry);
        }
        return digits;
    }
};
