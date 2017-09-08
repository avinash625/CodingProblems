
/*
Problem Link:
https://leetcode.com/problems/add-two-numbers/description/
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
    ListNode* getNode(int val){
        ListNode * node = (ListNode *)malloc(sizeof(ListNode));
        node->val = val;
        node->next = NULL;
        return node;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *newHead = NULL;
        ListNode *writeIter = NULL;
        int carry = 0;
        ListNode *iter1 = l1,*iter2 = l2;
        if(!l1) return l2;
        else if(!l2) return l1;
        while(iter1 && iter2){
            if(!newHead){
                newHead = writeIter = getNode((iter1->val + iter2->val)%10);
                carry = (iter1->val + iter2->val)/10;
            }
            else{
                writeIter->next = getNode((iter1->val+iter2->val + carry)%10);
                carry = (iter1->val + iter2->val+carry)/10;
                writeIter = writeIter->next;
            }
            iter1 = iter1->next;
            iter2 = iter2->next;
        }
        if(iter1){
            while(iter1){
                writeIter->next = getNode((iter1->val+carry)%10);
                carry= (iter1->val+carry)/10;
                iter1 = iter1->next;
                writeIter = writeIter->next;
            }
        }
        else if(iter2){
            while(iter2){
                writeIter->next = getNode((iter2->val+carry)%10);
                carry = (iter2->val+carry)/10;
                iter2 = iter2->next;
                writeIter = writeIter->next;
            }
        }
        if(carry){
            writeIter->next = getNode(carry);
        }
        return newHead;
    }
};
