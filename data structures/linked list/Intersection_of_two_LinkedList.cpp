/* Link list Node 
struct Node {
    int data;
    struct Node* next;
}; */


//returns the length of the linked list .
   int getLength(Node *head){
       Node *temp = head;
       int count = 0 ;
       while(temp){
           count++;
           temp = temp->next;
       }
       return count;
   }
   
   
   /* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node* head1, Node* head2)
{
    int l1 = getLength(head1);
    int l2 = getLength(head2);
    
    Node *temp1 = head1;
    Node *temp2 = head2;
    
    if(l1>l2){
        for(int iter =0 ;iter<(l1-l2);iter++){
            temp1 = temp1->next; 
        }
    }
    else if((l2>l1)){
        for(int iter = 0 ;iter< (l2-l1);iter++){
            temp2 = temp2->next;
        }
    }
    
    while(temp1 != temp2){
        temp1= temp1->next;
        temp2 = temp2->next;
    }
    if(temp1)
        return temp1->data;
    else
        return -1;
}
