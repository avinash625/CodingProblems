#Problem Link:
#https://leetcode.com/problems/reverse-string/description/

class Solution(object):
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        return "".join(list(reversed(s)))
        
