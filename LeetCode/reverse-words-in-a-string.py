class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        s = s.strip()
        words = s.split(" ")
        finalWords = []
        for word in words:
            if word != "":
                finalWords.append(word)
        finalWords.reverse()
        return " ".join(finalWords)