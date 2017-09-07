/*
Problem Link:
https://leetcode.com/problems/reverse-linked-list/description/
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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode *tempHead = NULL;
        ListNode *temp = head;
        while(head){
            if(!tempHead){
                tempHead = head;
                head = head->next;
                tempHead->next =NULL;
                temp = head;
            }
            else{
                temp = temp->next;
                head->next = tempHead;
                tempHead= head;
                head = temp;
            }
        }
        return tempHead;
    }
};
