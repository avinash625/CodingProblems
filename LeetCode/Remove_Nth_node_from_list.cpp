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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode *iter = head;
        while(iter){
            length++;
            iter = iter->next;
        }
        iter = head;
        if(length == n){
            head = head->next;
            return head;
        }
        else{
            length = length - n-1;
            while(length){
                iter = iter->next;
                length--;
            }
            iter->next = iter->next->next;
        }
        return head;
    }
    
};
