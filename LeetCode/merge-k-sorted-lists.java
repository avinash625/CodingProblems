/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode newHead;
        if(lists.length == 0) return null;
        if(lists.length == 1) return lists[0];
        else{
            newHead = mergeLists(lists[0],lists[1]);
            for(int listIndex = 2; listIndex < lists.length; listIndex++){
                newHead = mergeLists(newHead,lists[listIndex]);
            }
        }
        return newHead;
    }
    
    public ListNode mergeLists(ListNode list1, ListNode list2){
        if(list1 == null) return list2;
        if(list2 == null) return list1;
        
        ListNode newHead = null;
        ListNode iter1 = list1;
        ListNode iter2 = list2;
        
        if(iter1.val < iter2.val){
            newHead = iter1;
            iter1 = iter1.next;
        }else{
            newHead = iter2;
            iter2 = iter2.next;
        }
        
        ListNode writeIter = newHead;
        
        while(iter1 != null && iter2 != null){
            if(iter1.val < iter2.val){
                writeIter.next = iter1;
                writeIter = writeIter.next;
                iter1 = iter1.next;
            }else{
                writeIter.next = iter2;
                writeIter = writeIter.next;
                iter2 = iter2.next;
            }
        }
        
        if(iter1 != null){
            writeIter.next = iter1;
        }
        else if(iter2 != null){
            writeIter.next = iter2;
        }
        
        return newHead;
    }
}