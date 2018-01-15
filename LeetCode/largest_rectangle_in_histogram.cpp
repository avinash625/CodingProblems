class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0,top;
        int area;
        if(heights.size() == 0 ){
            return 0;
        }
        else{
            for(int iter =0 , n = heights.size();iter<n; iter++){
                if(st.empty() || (heights[st.top()] < heights[iter])){
                    //cout<<"pushing "<<iter<<" into the stack and value "<<heights[iter]<<endl;
                    st.push(iter);
                }
                else{
                    while(!st.empty() && heights[iter] < heights[st.top()]){
                        top = st.top();
                        st.pop();
                        if(st.empty()){
                            area = iter*heights[top];
                        }
                        else{
                            area = (iter-st.top()-1) * (heights[top]);
                        }
                        //cout<<"area ("<<area<<") is calculated "<<endl;
                        if(area > maxArea)
                            maxArea = area;
                    }
                    //cout<<"pushing "<<iter<<" into the stack and value "<<heights[iter]<<endl;
                    st.push(iter);
                }
            }
            while(!st.empty() /*&& st.size() > 1*/){
                top = st.top();
                st.pop();
                if(st.empty())
                    area = heights.size()*heights[top];
                else
                    area = (heights.size() - st.top()-1) * heights[top];
                
                //cout<<" area  ("<<area<<") is calculated "<<endl;
                if(maxArea < area){
                    maxArea = area;
                }
            }
            // if(st.size() == 1){
            //     area  = st.top() * heights.size();
            //     if(area > maxArea )
            //         maxArea = area;
            //     st.pop();
            // }
        }
        return maxArea;
    }
};
