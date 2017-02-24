/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */


/* Should print vertical order such that each vertical line
   is separated by $ */
   
void customInorder(Node *root, int curr, map<int,vector<int>> &mapping){
    if(!root)
        return;
    else{
        mapping[curr].push_back(root->data);
        customInorder(root->left,curr-1,mapping);
        customInorder(root->right,curr+1,mapping);
    }
}
void verticalOrder(Node *root)
{
    map<int,vector<int>> mapping;
    customInorder(root,0,mapping);
    for(map<int,vector<int>>::iterator it = mapping.begin(); it != mapping.end(); it++){
        for(vector<int>::iterator vt = (it->second).begin(); vt != (it->second).end(); vt++){
            cout<<*vt<<" ";
        }
        cout<<"$";
    }
}
