/* The structure of a BST Node is as follows:
struct Node {
  int data;
  Node * right, * left;
}; */
Node * deleteNode(Node *root,  int x)
{
    if(!root)
        return NULL;
    else if(root->data > x){
        root->left = deleteNode(root->left,x);
        return root;
    }
    else if(root->data < x){
        root->right = deleteNode(root->right,x);
        return root;
    }
    else if(root->data == x){
        if(!root->left){
            root = root->right;
        }
        else if(!root->right){
            root = root->left;
        }
        else{
            Node *temp = root->right;
            while(temp->left){
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = deleteNode(root->right,temp->data);
        }
        return root;
    }
    
}
