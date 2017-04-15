#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,seaLevel = 0,valleyCount = 0;
    cin>>n;
    char step;
    for(int iter = 0;iter<n;iter++){
        cin>>step;
        
        if(step == 'U'){
            if(seaLevel == -1){
                valleyCount++;
            }
            seaLevel++;
        }
        else if(step == 'D'){
            seaLevel--;
        }
    }
    cout<<valleyCount<<endl;
    return 0;
}
