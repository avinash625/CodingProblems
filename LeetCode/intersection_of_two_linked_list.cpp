/*
ProblemLink:
https://leetcode.com/problems/intersection-of-two-linked-lists/description/
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int absolutea(int a){
        if( a < 0 )
            return a*-1;
        return a;
}
    int getLength(ListNode *head){
        int count  = 0;
        ListNode*temp = head;
        while(temp){
            temp = temp->next;
            count++;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = getLength(headA);
        int l2 = getLength(headB);
        
        int diff = absolutea(l1-l2);
        //cout<<"diff = "<<diff<<endl;
        ListNode *iter1 = headA , *iter2 = headB;
        if(!headA && headB) return NULL;
        if(!headB && headA) return NULL;
        if(!headA && !headB) return NULL;
        if(l1>l2){
            iter1 = headA;
            int count = 0;
            while(count<diff){
                iter1 = iter1->next;
                count++;
            }
        }
        else if(l2>l1){
            iter2 = headB;
            int count = 0;
            while(count<diff){
                iter2 = iter2->next;
                count++;
            }
        }
        while(iter1 != iter2){
            iter1 = iter1->next;
            iter2 = iter2->next;
        }
        if(iter1 == iter2 && iter1 != NULL){
            return iter1;
        }
        else
            return NULL;
    }
};
