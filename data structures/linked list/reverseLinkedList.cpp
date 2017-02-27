/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
  }
*/

// Should reverse list and return new head.
Node* reverse(Node *head)
{
    Node *temp = head;
    Node *newNode = NULL;
    Node *t;
    while(temp){
        if(!newNode){
            newNode = temp;
            temp = temp->next;
            newNode->next = NULL;
        }
        else{
            t = temp;
            temp = temp->next;
            t->next = newNode;
            newNode = t;
        }
    }
    return newNode;
}
