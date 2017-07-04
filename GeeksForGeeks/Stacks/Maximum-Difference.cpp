/*You are required to complete this method */
#include<stack>
#include<vector>
#include<math.h>
#include<limits.h>
int findMaxDiff(int values[], int n)
{
  stack<int> st;
  st.push(values[0]);
  vector<int> ls(n),rs(n);
  ls[0] = 0;
  rs[n-1] = 0;
  for(int iter = 1;iter<n;iter++){
      while(!st.empty() && values[iter] <= st.top()){
          st.pop();
      }
      if(st.empty()){
          st.push(values[iter]);
          ls[iter] = 0;
      }
      else{
          ls[iter] = st.top();
          st.push(values[iter]);
      }
  }
  while(!st.empty()) st.pop();
  st.push(values[n-1]);
  for(int iter = n-2;iter>=0 ; iter--){
      while(!st.empty() && values[iter] <= st.top()){
          st.pop();
      }
      if(st.empty()){
          st.push(values[iter]);
          rs[iter] = 0;
      }
      else{
          rs[iter] = st.top();
          st.push(values[iter]);
      }
  }
  int maximum = INT_MIN;
  for(int iter = 0;iter<n;iter++){
      if(abs(ls[iter] - rs[iter]) > maximum)
        maximum = abs(ls[iter] - rs[iter]);
        //cout<<abs(ls[iter]-rs[iter])<<" ";
  }
  return maximum;
}
