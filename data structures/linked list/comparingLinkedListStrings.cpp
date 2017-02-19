/* Linked list Node structure
struct Node
{
    char c;
    Node *next;
}; */

int compare(Node *list1, Node *list2) 
{
     if(!list1  && !list2)
        return 0 ;
    else if(!list1)
        return -1;
    else if(!list2)
        return 1;
    else{
        Node *iter1 = list1;
        Node *iter2 = list2;
        while(iter1 && iter2){
            if(iter1->c == iter2->c){
                iter1 = iter1->next;
                iter2 = iter2->next;
            }
            else if(iter1->c > iter2->c)
                return 1;
            else if(iter2->c > iter1->c)
                return -1;
        }
        return 0;
    }
}