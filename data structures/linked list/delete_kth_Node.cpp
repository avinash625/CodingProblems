/* Link list Node 
struct Node
{
    int data;
    Node* next;
};*/

Node* deleteNode(Node *head,int x)
{
    Node *temp = head;
    int count = 1 ;
    if(x == 1){
        head=  head->next;
        return head;
    }
    while(temp){
        if(count == x-1){
            break;
        }
        count++;
        temp = temp->next;
    }
    if(head != temp)
        temp->next = temp->next->next;
    else
        head->next = head->next->next;
    return head;
}
