class Solution {
public:
    void printVector(vector<int> &v){
        cout<<"the input size is "<<v.size()<<endl;
        for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
            cout<<*it<<" ";
        }
        cout<<"vector Ends Here"<<endl;
    }
    int trap(vector<int>& height) {
        int inputSize = height.size();
        if(inputSize == 0){
            return 0;
        }
        
        vector<int> leftHeights(inputSize);
        vector<int> rightHeights(inputSize);
        
        leftHeights[0]= height[0];
        for(int iter = 1,n = height.size(); iter<n;iter++){
            if(leftHeights[iter-1] < height[iter]){
                leftHeights[iter] = height[iter];
            }
            else{
                leftHeights[iter] = leftHeights[iter-1];
            }
        }
        //printVector(leftHeights);
        rightHeights[height.size()-1] = height.back();
        for(int iter = height.size()-2; iter>=0;iter--){
            if(height[iter] > rightHeights[iter+1]){
                rightHeights[iter] = height[iter];
            }
            else{
                rightHeights[iter] = rightHeights[iter+1];
            }
        }
        //printVector(rightHeights);
        int answer = 0;
        for(int iter = 0;iter<inputSize;iter++){
            if(min(leftHeights[iter],rightHeights[iter]) - height[iter] > 0){
                answer = answer+ min(leftHeights[iter],rightHeights[iter]) - height[iter];
            }
        }
        return answer;
    }
};
