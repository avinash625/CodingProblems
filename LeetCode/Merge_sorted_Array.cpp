class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int writeIter = (m+n)-1;
        int secondIter = n;
        int firstIter = m;
        secondIter--;
        firstIter--;
        while(firstIter>=0 &&secondIter>=0){
            if(nums1[firstIter] > nums2[secondIter]){
                //cout<<" writing "<<nums1[firstIter]<<" into the finalArray"<<endl;
                nums1[writeIter] = nums1[firstIter];
                firstIter--;
                writeIter--;
            }
            else{
                //cout<<" writing "<<nums2[secondIter]<<" into the finalArray"<<endl;
                nums1[writeIter] = nums2[secondIter];
                secondIter--;
                writeIter--;
            }
        }
        if(firstIter < 0){
            while(secondIter>=0){
                //cout<<" writing "<<nums2[secondIter]<<" into the finalArray"<<endl;
                nums1[secondIter] = nums2[secondIter];
                secondIter--;
            }
        }
    }
};
