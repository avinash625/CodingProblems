/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }3, 2, 0, -4
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head == null) return null;
        ListNode slowIter = head, fastIter = head;
        
        while(true){
            if(fastIter != null && fastIter.next != null){
                fastIter = fastIter.next.next;
                slowIter = slowIter.next;
            }else{
                break;
            }
            
            if(slowIter == fastIter) break;
        }
        
        if(fastIter == null || fastIter.next == null) return null;
        
        slowIter = head;
        while(slowIter != fastIter){
            fastIter = fastIter.next;
            slowIter = slowIter.next;
        }
        return fastIter;
    }
}