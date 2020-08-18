# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def middleNode(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """

        slowIter = head
        fastIter = head

        while (fastIter != None and fastIter.next != None):
            fastIter = fastIter.next.next
            slowIter = slowIter.next

        return slowIter