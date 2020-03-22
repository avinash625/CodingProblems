/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public int getDecimalValue(ListNode head) {
        int value = 0;
        ListNode iter = head;
        while(iter != null){
            value = ((value<<1) | iter.val);
            iter = iter.next;
        }
        return value;
    }
}