/*
Structure of the node of the binary search tree is as
struct node 
{
	int data;
	struct node* left;
	struct node* right;
};
*/
// your task is to complete the below function
int minValue(struct node* root)
{
    struct node *temp = root;
    while(temp->left){
        temp = temp->left;
    }
    return temp->data;
}