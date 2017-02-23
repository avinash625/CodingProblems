/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

#include<map>
#include<vector>
void customInorder(Node *root,int curr, map<int,vector<int>> &mapping){
    if(!root){
        return;
    }
    else{
        mapping[curr].push_back(root->data);
        customInorder(root->left,curr+1,mapping);
        customInorder(root->right,curr,mapping);
    }
}


void diagonalPrint(Node *root)
{
   map<int,vector<int>> mapping;
   customInorder(root,0,mapping);
   for(map<int,vector<int>>::iterator it = mapping.begin(); it != mapping.end(); it++){
       for(vector<int>::iterator vt = it->second.begin(); vt != it->second.end(); vt++){
           cout<<*vt<<" ";
       }
   }
}
