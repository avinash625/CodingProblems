class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        d = {}
        value = 1
        alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        for a in alpha:
            d.update({a: value})
            value = value + 1
        length = len(s)
        result = 0
        for rLength in xrange(1, length):
            result = result + math.pow(26, rLength)
            # print result

        for index in xrange(0, len(s)):
            result = result + ((d.get(s[index]) - 1) * math.pow(26, len(s) - index - 1))

        return int(result) + 1

