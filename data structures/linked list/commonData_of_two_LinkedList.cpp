/* The structure of the Linked list Node is as follows:
struct Node {
    int val;
    struct Node* next;
}; */

void intersection(Node **head1, Node **head2,Node **head3)
{
    struct Node *iter1 = *head1;
    struct Node *iter2 = *head2;
    struct Node *iter3 = *head3;
    while(iter1 && iter2){
        if(iter1->val == iter2->val){
            if(iter3){
                iter3->next = (struct Node *)malloc(sizeof(struct Node));
                iter3->next->val = iter1->val;
                iter3->next->next = NULL;
                iter3 = iter3->next;
                iter1 = iter1->next;
                iter2 = iter2->next;
            }
            else{
                *head3 = iter3 = (struct Node *)malloc(sizeof(struct Node));
                iter3->val = iter1->val;
                iter3->next = NULL;
                iter1 = iter1->next;
                iter2 = iter2->next;
            }
        }
        else if(iter1->val < iter2->val){
            iter1 = iter1->next;
        }
        else if(iter1->val > iter2->val){
            iter2 = iter2->next;
        }
    }
}