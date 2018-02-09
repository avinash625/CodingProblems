class Solution {
public:
    void printVector(vector<int>& result){
        for(vector<int>::iterator it = result.begin(); it!= result.end(); it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        st.push(0);
        vector<int> result(temperatures.size());
        if(temperatures.size() == 0)
            return result;
        else{
            int inputSize = temperatures.size();
            for(int iter = 1;iter<inputSize;iter++){
                if(st.empty() || (temperatures[st.top()] > temperatures[iter])){
                    //cout<<"adding "<<temperatures[iter] << " to the stack"<<endl;
                    st.push(iter);
                }
                else{
                    while(!(st.empty()) && (temperatures[st.top()] < temperatures[iter])){
                        int pos = st.top();
                        //cout<<"removing "<<temperatures[pos]<<" form the  stack"<<endl;
                        st.pop();
                        result[pos] = iter-pos;
                        //cout<<"making  value at "<<pos<<" as "<<result[pos]<<endl;
                    }
                    //cout<<"adding "<<temperatures[iter] <<" to the stack"<<endl;
                    st.push(iter);
                }
            }
        }
        while(!st.empty()){
            result[st.top()] = 0;
            st.pop();
        }
        //printVector(result);
        return result;
    }
};
