/*The Node structure is defined as
struct Node
{
    int key;
    Node *left, *right;
}; */

int size(Node *root){
    if(!root)
        return 0;
    return size(root->right)+size(root->left)+1;
}
void kthLargest(Node *root, int k)
{
    if(!root)
        return;
    int rightSize = size(root->right);
    if(rightSize == k-1)
        cout<<root->key<<endl;
    else if(rightSize >= k){
         kthLargest(root->right,k);
    }
    else if(rightSize <  k){
         kthLargest(root->left,k-rightSize-1);
    }
}