/* Link list Node 
struct Node
{
    int data;
    Node* next;
};*/
Node* deleteAllOccurances(Node *head,int x)
{
    Node *temp = head;
    while(temp){
        if(temp->next && temp->next->data == x){
            temp->next = temp->next->next;
        }
        else{
            temp = temp->next;
        }
    }
    if(head->data == x)
        head = head->next;
    return head;
}
