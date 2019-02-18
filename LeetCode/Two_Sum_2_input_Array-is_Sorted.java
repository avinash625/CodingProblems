class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        vector<int> result(2);
        int end = numbers.size()-1;
        while(start < end){
            if((numbers[start] + numbers[end]) == target){
                result[0] = start+1;
                result[1] = end+1;
                break;
            }else if(numbers[start] +numbers[end] > target){
                end--;
            }else if(numbers[start]+numbers[start] < target){
                start++;
            }
        }
        return result;
    }
};
