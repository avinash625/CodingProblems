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
    bool detectCycle(ListNode *head) {
        if(!head) return false;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast)
                break;
        }
        if(!fast || !fast->next)
            return false;
        else{
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return true;
        }
    }
    
    bool hasCycle(ListNode *head) {
        return detectCycle(head);
    }
};




    
