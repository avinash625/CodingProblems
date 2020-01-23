/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if(head == null) return false;
        ListNode slowIter = head;
        ListNode fastIter = head.next;
        
        while(slowIter != fastIter){
            if(fastIter != null && fastIter.next != null && fastIter.next.next != null){
                fastIter = fastIter.next.next;
                slowIter = slowIter.next;
            }else{
                return false;
            }
        }
        
        if(slowIter == fastIter) return true;
        else return false;
    }
}