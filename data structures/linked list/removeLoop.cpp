/*The structure of linked list is the following
struct Node
{
int data;
Node* next; 
};*/

/*solution for the practice question on geeksforgeeks.org , certain part of it might be different to what it is required to remove the loop*/
void removeTheLoop(Node *node)
{
     Node *temp = node;
     Node *slow = node;
     Node *fast = node->next;
     while(fast && fast->next && fast != slow){
         fast = fast->next->next;
         slow = slow->next;
     }
     if(!fast ||  !(fast->next))
        return ;
     int count = 1;
     temp = slow->next;
     while(temp!=slow){
         count++;
         temp = temp->next;
     }
     temp = node;
     while(count){
         temp =temp->next;
         count--;
     }
     fast = node;
     while(fast!=temp){
         fast = fast->next;
         temp = temp->next;
     }
     temp = fast->next;
     while(temp->next!= fast){
         temp = temp->next;
     }
     temp->next = NULL;
}
