# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
import collections


class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: None Do not return anything, modify head in-place instead.
        """
        if head == None:
            return []
        de = collections.deque([])

        iterator = head

        while iterator != None:
            de.append(iterator)
            iterator = iterator.next

        newHead = de.popleft()
        iterator = newHead

        while len(de) != 0:
            iterator.next = de.pop()

            iterator = iterator.next
            iterator.next = None

            if len(de) != 0:
                iterator.next = de.popleft()
                iterator = iterator.next
                iterator.next = None

        return newHead