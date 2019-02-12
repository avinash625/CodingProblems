/**
 * Definition for singly-linked list with a random pointer.
 * class RandomListNode {
 *     int label;
 *     RandomListNode next, random;
 *     RandomListNode(int x) { this.label = x; }
 * };
 */
public class Solution {
    public RandomListNode copyRandomList(RandomListNode head) {
        if(head == null)
            return head;
        RandomListNode currentNode = head;
        while(currentNode != null){
            RandomListNode node = new RandomListNode(currentNode.label);
            node.next = currentNode.next;
            currentNode.next = node;
            currentNode = node.next;
        }
        
        RandomListNode newHead = head.next;
        RandomListNode newNodeIter = head.next;
        currentNode = head;
        
        while(newNodeIter != null){
            if(currentNode.random != null){
                newNodeIter.random = currentNode.random.next;
            }
            currentNode = newNodeIter.next;
            if(currentNode != null)
                newNodeIter = currentNode.next;
            else
                newNodeIter = null;
        }
        
        newHead = head.next;
        newNodeIter = head.next;
            
        currentNode = head;
        
        while(newNodeIter.next != null){
            currentNode.next = newNodeIter.next;
            currentNode = currentNode.next;
            newNodeIter.next = currentNode.next;
            newNodeIter = newNodeIter.next;
        }
        
        currentNode.next = null;
        newNodeIter.next = null;
        return newHead;
    }
}