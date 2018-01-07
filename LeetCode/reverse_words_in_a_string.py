class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        words = s.split(" ")
        reversewords = []
        for word in words:
            w = list(word)
            w.reverse()
            reversewords.insert(len(reversewords) , "".join(w))
        return " ".join(reversewords)
        
