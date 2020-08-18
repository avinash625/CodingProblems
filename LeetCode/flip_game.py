class Solution(object):
    def generatePossibleNextMoves(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        result = []
        for index in range(1, len(s)):
            # print(s[index-1:index+1])
            if (s[index - 1:index + 1] == "++"):
                result.append(s[:index - 1] + "--" + s[index + 1:])
        return result
