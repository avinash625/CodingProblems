#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    int maximum = 0, freq = 0;
    int *values = (int *)malloc(sizeof(int)*n);
    for(int iter = 0;iter<n;iter++){
        cin>>values[iter];
        if(values[iter] > maximum){
            maximum = values[iter];
            freq = 1;
        }
        else if(values[iter] == maximum)
            freq++;
            
    }
    cout<<freq<<endl;
    return 0;
}
