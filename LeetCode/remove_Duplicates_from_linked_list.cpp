/*
Problem Link:
https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode *temp = head->next ,*writeList = head;
        while(temp){
            if((writeList->val) == (temp->val)){
                //cout<<"comparing "<<writeList->val <<" with "<< temp->val<<endl; 
                temp = temp->next;
            }
            else{
                //cout<<"comparing "<<writeList->val <<" with "<< temp->val<<endl;
                writeList->next = temp;
                writeList = writeList->next;
                temp = temp->next;
            }
        }
        writeList->next = NULL;
        return head;
    }
};
