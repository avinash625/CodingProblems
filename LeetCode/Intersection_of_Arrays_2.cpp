class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> result;
        
        int iter1 = 0;
        int iter2 = 0;
        
        int inputSize1 = nums1.size(), inputSize2 = nums2.size();
        for(;iter1<inputSize1 && iter2 < inputSize2;){
            if(nums1[iter1] == nums2[iter2]){
                result.push_back(nums1[iter1]);
                iter1++;
                iter2++;
            }
            else if(nums1[iter1] < nums2[iter2]){
                iter1++;
            }
            else if(nums1[iter1] > nums2[iter2]){
                iter2++;
            }
        }
        return result;
    }
};
