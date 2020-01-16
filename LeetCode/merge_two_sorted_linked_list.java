/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode newHead = null, nextNode = null, currentNode = null;
        if(l1 == null) return l2;
        if(l2 == null) return l1;
        if(l1.val > l2.val){
            newHead = l2;
            l2 = l2.next;
            currentNode = newHead;
        }else{
            newHead = l1;
            l1 = l1.next;
            currentNode = newHead;
        }
        while(l1 != null && l2 != null){
            if(l1.val > l2.val){
                nextNode = l2.next;
                currentNode.next = l2;
                l2 = l2.next;
                currentNode = currentNode.next;
            }else{
                nextNode = l1.next;
                currentNode.next = l1;
                l1 = l1.next;
                currentNode = currentNode.next;
            }
        }
        if(l1 == null){
            currentNode.next = l2;
        }else if(l2 == null){
            currentNode.next = l1;
        }else{
            currentNode.next = null;
        }
        return newHead;
    }
}