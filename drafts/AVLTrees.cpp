/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */
int maximum(int a, int b){
    if(a>b)
        return a;
    return b;
}
node *constructNode(int value){
    node *Node = (node *)malloc(sizeof(node));
    Node->val=value;
    Node->left = NULL;
    Node->right = NULL;
    Node->ht = 0;
    return Node;
}
int height(node *root){
    if(!root)
        return -1;
    return root->ht;
}
node *rotateLeft(node *root){
    node *Node;
    Node = root->left;
    root->left = Node->right;
    Node->right = root;
    
    root->ht = maximum(height(root->left),height(root->right))+1;
    Node->ht = maximum(height(root->left), height(root->right))+1;
    return Node;
}
node *rotateRight(node *root){
    node *Node;
    Node = root->right;
    root->right = Node->left;
    Node->left = root;
    
    root->ht = maximum(height(root->left),height(root->right))+1;
    Node->ht = maximum(height(root->left),height(root->right))+1;
    return Node;
}
node *doubleRotateLeft(node* root){
    root->left = rotateRight(root->left);
    return rotateLeft(root);
}
node *doubleRotateRight(node *root){
    root->right = rotateLeft(root->right);
    return rotateRight(root);
}
node * insert(node * root,int val)
{
   if(!root){
       root = constructNode(val);
       return root;
   }
   else if(root->val > val){
       root->left = insert(root->left,val);
       if((height(root->left)-height(root->right)) == 2){
           if(val<root->left->val)
               root = rotateLeft(root);
           else
               root = doubleRotateLeft(root);
       }
   }
    else if(root->val < val){
        root->right = insert(root->right, val);
        if((height(root->right)-height(root->left))==2){
            if(val> root->right->val)
                root = rotateRight(root);
            else
                root = doubleRotateRight(root);
        }
    }
    root->ht = maximum(height(root->left), height(root->right))+1;
    return root;
}
