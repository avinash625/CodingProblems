/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

void customInorder(Node *root, int curr, map<int,vector<int>> &mapping){
    if(!root){
        return;
    }
    mapping[curr].push_back(root->data);
    customInorder(root->left,curr+1,mapping);
    customInorder(root->right,curr+1,mapping);
}
void printSpiral(Node *root)
{
     map<int,vector<int>> mapping;
     customInorder(root,0,mapping);
     int flag = 1;
     for(map<int,vector<int>>::iterator it = mapping.begin(); it != mapping.end(); it++){
         if(flag&1){
             for(vector<int>::reverse_iterator  vt = (it->second).rbegin() ; vt != (it->second).rend() ; ++vt){
                 cout<<*vt<<" ";
             }
             flag = 0;
         }
         else{
             for(vector<int>::iterator vt = (it->second).begin() ; vt != (it->second).end() ; vt++){
                 cout<<*vt<<" ";
             }
             flag = 1;
         }
     }
}
