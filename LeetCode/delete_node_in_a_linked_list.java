/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void deleteNode(ListNode node) {
        ListNode iter = node;
        while(iter.next.next != null){
            iter.val = iter.next.val;
            iter = iter.next;
        }
        iter.val = iter.next.val;
        iter.next = null;
    }
}