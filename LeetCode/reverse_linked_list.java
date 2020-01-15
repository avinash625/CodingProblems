/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        if(head == null) return head;
        ListNode nextNode = head.next;
        ListNode newHead = head;
        ListNode currentNode = head.next;
        newHead.next = null;
        while(nextNode != null){
            nextNode = currentNode.next;
            currentNode.next = newHead;
            newHead = currentNode;
            currentNode = nextNode;
        }
        return newHead;
    }
}