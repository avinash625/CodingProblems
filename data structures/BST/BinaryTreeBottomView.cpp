/* Tree node class
struct Node
{
    int data; 
    Node *left, *right; 
}; */

void customTraversal(Node *root, int curr, map<int,int> &mapping){
    if(!root)
        return;
    else{
        mapping[curr] = root->data;
        customTraversal(root->left,curr-1,mapping);
        customTraversal(root->right,curr+1,mapping);
    }
}
void bottomView(Node *root)
{
   map<int,int> mapping;
   customTraversal(root,0,mapping);
   for(map<int,int>::iterator it = mapping.begin(); it != mapping.end(); it++){
       cout<<it->second<<" ";
   }
}

