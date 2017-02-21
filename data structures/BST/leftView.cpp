/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// A wrapper over leftViewUtil()
int getHeight(Node *root){
    if(!root)
        return 0 ;
    else 
        return max(getHeight(root->left), getHeight(root->right))+1;
}
void treeTraversal(Node *root, int curr ,map<int, int > &mapping){
    if(!root)
        return ;
    else if(mapping[curr] == -1){
        mapping[curr] = root->data;
    }
    treeTraversal(root->left, curr+1,mapping);
    treeTraversal(root->right,curr+1,mapping);
}
void leftView(Node *root)
{
   int ht =  getHeight(root);
   map<int, int> mapping;
   for(int iter = 0 ;iter< ht;iter++){
       mapping[iter] = -1;
   }
   treeTraversal(root,0,mapping);
   for(map<int, int >::iterator it = mapping.begin() ; it != mapping.end() ;it++){
       cout<<it->second<<" ";
   }
}
