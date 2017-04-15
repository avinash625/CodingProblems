#include <cmath>
#include <cstdio>
#include<queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    int *values = (int *)malloc(sizeof(int)*n);
    for(int iter = 0 ;iter< n;iter++){
        cin>>values[iter];
    }
    int d,m;
    cin>>d>>m;
    vector<int> v;
    queue<int> q;
    int sum  = 0;
    for(int iter = 0;iter<m;iter++){
        sum+= values[iter];
        q.push(iter);
    }
    v.push_back(sum);
    for(int iter = m;iter<n;iter++){
        sum = sum - values[q.front()];
        q.pop();
        sum = sum+values[iter];
        q.push(iter);
        v.push_back(sum);
    }
    int count = 0;
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        if(*it == d){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}
