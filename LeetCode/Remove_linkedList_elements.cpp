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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *iter = head;
        while(iter){
            if(iter->next && iter->next->val == val){
                iter->next = iter->next->next;
            }
            else
                iter = iter->next;
        }
        if(head && head->val == val){
            head = head->next;
        }
        return head;
    }
    
};
