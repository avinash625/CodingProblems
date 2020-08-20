# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isUnivalTree(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if (root != None):
            if (root.left != None and root.left.val != root.val):
                return False
            if (root.right != None and root.right.val != root.val):
                return False
            return (self.isUnivalTree(root.left) and self.isUnivalTree(root.right))
        else:
            return True
