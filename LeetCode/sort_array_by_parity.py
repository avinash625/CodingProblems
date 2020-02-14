class Solution(object):
    def sortArrayByParity(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        B = sorted(A, key = lambda x: (x)%2)
        return B
        