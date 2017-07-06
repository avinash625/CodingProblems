/*The node structure
struct Node {
int data;
Node * right, * left;
};*/

/*The function should return the root of the modified tree*/
Node* deleteNode(Node* root, int key)
{
    if(!root)
        return NULL;
    else if(root->data == key){
        return root->left;
    }
    else if(root->data < key){
        root->right = deleteNode(root->right,key);
    }
    else if(root->data > key){
        root = root->left;
        root = deleteNode(root,key);
    }
    return root;
}
