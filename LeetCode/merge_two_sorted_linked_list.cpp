/*
Problem Link:
https://leetcode.com/problems/merge-two-sorted-lists/description/
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * newHead = NULL;
        ListNode *temp = NULL;
        if(!l1)
            return l2;
        else if(!l2)
            return l1;
        while(l1 && l2){
            if(l1->val < l2->val){
                if(!newHead){
                    newHead = l1;
                    l1 = l1->next;
                    temp = newHead;
                }
                else{
                    temp->next = l1;
                    l1 = l1->next;
                    temp = temp->next;
                }
            }
            else{
                if(!newHead){
                    newHead = l2;
                    l2 = l2->next;
                    temp = newHead;
                }
                else{
                    temp->next = l2;
                    l2 = l2->next;
                    temp = temp->next;
                }
            }
        }
        if(l1){
            temp->next = l1;
        }
        else if(l2){
            temp ->next = l2;
        }
        return newHead;
    }
};
