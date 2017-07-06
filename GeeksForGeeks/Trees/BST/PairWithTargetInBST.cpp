/*Complete the function below
Node is as follows
struct node
{
    int val;
    struct node *left, *right;
};
*/
int sizeofBST(struct node *root){
    if(!root)
        return 0;
    return (sizeofBST(root->left)+sizeofBST(root->right)+1);
}
void customInorder(struct node *root,int *values, int n, int *currentIndex){
    if(!root)
    return ;
    else{
        customInorder(root->left,values,n,currentIndex);
        values[*currentIndex] = root->val;
        *currentIndex = *currentIndex + 1;
        customInorder(root->right,values,n,currentIndex);
    }
}
bool isPairPresent(struct node *root, int target)
{
    int BSTsize = sizeofBST(root);
    int *values = (int *)malloc(sizeof(int)*BSTsize);
    int currentIndex = 0;
    customInorder(root,values,BSTsize,&currentIndex);
    // for(int iter = 0;iter< BSTsize;iter++)
    //     cout<<values[iter]<<" ";
    int starting = 0;
    int ending = BSTsize-1;
    while(starting < ending){
        if((values[starting] + values[ending]) == target)
            return true;
        else if((values[starting]+ values[ending]) < target)
            starting++;
        else if((values[starting] + values[ending]) > target)
            ending--;
    }
    return false;
}