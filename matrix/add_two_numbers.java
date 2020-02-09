/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = null;
        ListNode headiter = null;
        
        ListNode iter1 = l1;
        ListNode iter2 = l2;
        
        int carry = 0;
        
        while(l1 != null && l2 != null){
            ListNode currentNode = new ListNode((l1.val + l2.val + carry )%10);
            carry = (l1.val + l2.val + carry )/10;
            l1 = l1.next;
            l2 = l2.next;
            
            if(headiter == null){
                headiter = currentNode;
                head = currentNode;
            }else{
                headiter.next = currentNode;
                headiter = headiter.next;
            }
        }
        
        if(l1 != null){
            while(l1 != null){
                ListNode currentNode = new ListNode((l1.val + carry)%10);
                carry = (l1.val + carry) / 10;
                headiter.next = currentNode;
                headiter = headiter.next;
                l1 = l1.next;
            }
            
        }
        if(l2 != null){
            while(l2 != null){
                ListNode currentNode = new ListNode((l2.val + carry)%10);
                carry = (l2.val + carry) /10;
                headiter.next = currentNode;
                headiter = headiter.next;
                l2 = l2.next;
            }
            
        }
        
        if(carry == 1){
            ListNode currentNode = new ListNode(carry);
            headiter.next = currentNode;
            headiter = headiter.next;
        }
        return head;
    }
}