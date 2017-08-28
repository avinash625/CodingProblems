/*
Problem Link:
http://practice.geeksforgeeks.org/problems/count-element-occurences/1
*/

/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


// A structure to store an element and its current count
/* struct eleCount
{
    long long int e;  // Element
    long long int c;  // Count
};
*/
#include<map>
// Prints elements with more than n/k occurrences in arr[] of
// size n. If there are no such elements, then it prints nothing.
void moreThanNdK(long long int arr[], long long int n, long long int k)
{
    map<long long int,long long int> mapping;
    for(long long int iter = 0;iter<n;iter++){
        mapping[arr[iter]]= mapping[arr[iter]]+1;
    }
    long long int count = 0;
    long long int threshold = n/k;
    for(map<long long int,long long int>::iterator it = mapping.begin();it != mapping.end(); it++){
        if(it->second > threshold){
            count++;
        }
    }
    cout<<count<<endl;
}
