class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    stack<int> minSt;
    
    MinStack() {
        
    }
    
    void push(int x) {
        if(st.empty() || minSt.top() >= x){
            st.push(x);
            minSt.push(x);
        }
        else{
            st.push(x);
        }
        
    }
    
    void pop() {
        if(st.empty() || minSt.empty()){
            return;
        }
        else if(st.top() == minSt.top()){
            st.pop();
            minSt.pop();
        }
        else{
            st.pop();
        }
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }
        else
            return st.top();
    }
    
    int getMin() {
        if(minSt.empty()){
            return -1;
        }
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
