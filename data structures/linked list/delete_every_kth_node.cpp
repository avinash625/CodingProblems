/* Link list Node 
struct Node
{
    int data;
    struct Node* next;
};*/

Node * deleteK(Node *head,int k)
{
  if(k == 1)
    return NULL;
    else{
        int count = 1 ;
        Node *temp = head;
        while(temp){
            if(temp->next && count == k-1){
                temp->next = temp->next->next;
                count = 0;
            }
            else{
                temp = temp->next;
                count++;
            }
        }
    }
    return head;
}
