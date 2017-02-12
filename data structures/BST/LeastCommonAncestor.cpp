/*The structure of a BST Node is as follows:
struct Node {
    int data;
    Node * right, * left;
};*/

Node* LCA(Node *root, int n1, int n2)
{
   if(!root)
    return NULL;
    if(root->data == n1 || root->data == n2){
        return root;
    }
    if(root->data > n1 && root->data > n2){
        return LCA(root->left,n1,n2);
    }
    else if(root->data < n1 && root->data < n2){
        return LCA(root->right,n1,n2);
    }
    return root;
}