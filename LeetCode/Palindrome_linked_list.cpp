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
    
    ListNode * reverseList(ListNode *head){
        ListNode *newHead = NULL, *next ;
        if(!head) return head;
        else{
            newHead = head;
            ListNode *iter = head->next;
            newHead->next = NULL;
            while(iter != NULL){
                next = iter->next;
                iter->next = newHead;
                newHead = iter;
                iter = next;
            }
        }
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode *slow  = head , *fast = head , *secondHalf ;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast && fast->next == NULL){
            secondHalf = reverseList(slow->next);
        }
        else if(fast == NULL){
            secondHalf = reverseList(slow);
        }
        ListNode *iter1 = head;
        ListNode *iter2 = secondHalf;
        while(iter1 && iter2){
            if(iter1->val != iter2->val){
                return false;
            }
            iter1 = iter1->next;
            iter2 = iter2->next;
        }
        return true;
    }
};
