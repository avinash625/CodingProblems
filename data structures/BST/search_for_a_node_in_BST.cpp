/* Node structure 
struct node {
    int data;
   struct node * right, * left;
};*/


bool search(node* root, int x)
{
    if(!root)
        return false;
    else if(root->data == x)
        return true;
    else if(root->data > x)
        return search(root->left,x);
    else if(root->data < x)
        return search(root->right,x);
}

