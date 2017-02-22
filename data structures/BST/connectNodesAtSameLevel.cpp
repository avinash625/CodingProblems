/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */

// Should set the nextRight for all nodes
void customInorder(Node *root,int curr, map<int,vector<Node *>> &mapping){
    if(!root){
        return;
    }
    else{
        mapping[curr].push_back(root);
        customInorder(root->left,curr+1,mapping);
        customInorder(root->right,curr+1,mapping);
    }
}
void connect(Node *p)
{
    map<int,vector<Node *>> mapping;
    customInorder(p,0,mapping);
    for(map<int,vector<Node *>>::iterator it = mapping.begin(); it != mapping.end() ; it++){
        int vt;
        for( vt = 0;vt < (it->second).size()-1;vt++){
            (it->second)[vt]->nextRight = (it->second)[vt+1];
        }
        (it->second)[vt]->nextRight = NULL;
    }
}

