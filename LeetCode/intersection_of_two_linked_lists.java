/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if(headA == null || headB == null) return null;
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        
        ListNode iterA = headA;
        ListNode iterB = headB;
        
        //System.out.println("" + lenA +", "+ lenB);
        int diff = Math.abs(lenA-lenB);
        //System.out.println(diff);
        if(lenA > lenB){
            while(diff > 0){
                iterA = iterA.next;
                diff--;
            }
        }else if(lenB > lenA){
            while(diff > 0){
                iterB = iterB.next;
                diff--;
            }
        }
        while(iterA != iterB){
                iterA = iterA.next;
                iterB = iterB.next;
        }
        if(iterA == null || iterB == null) return null;
        else return iterA;
    }
    
    public int getLength(ListNode head){
        if(head == null) return 0;
        else{
            int len = 0;
            while(head != null){
                len += 1;
                head = head.next;
            }
            return len;
        }
    }
}