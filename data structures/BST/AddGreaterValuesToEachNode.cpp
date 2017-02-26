/* BST Node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

/
void modifyUtil(Node *root, int *sum){
    if(!root)
        return;
    else{
        modifyUtil(root->right,sum);
        *sum = *sum + root->data;
        root->data = *sum;
        modifyUtil(root->left,sum);
    }
}
void modify(Node **root)
{
    int sum = 0 ;
    modifyUtil(*root,&sum);
}