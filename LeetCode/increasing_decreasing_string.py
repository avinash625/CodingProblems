class Solution(object):
    def sortString(self, s):
        """
        :type s: str
        :rtype: str
        """
        d = {}
        characterCount = 0
        for x in s:
            characterCount += 1
            if x not in d.keys():
                d.update({x: 1})
            else:
                d.update({x: d.get(x) + 1})

        result = ""
        charSet = "abcdefghijklmnopqrstuvwxyz"
        while characterCount > 0:
            for character in charSet:
                if d.get(character) > 0:
                    result += character
                    d.update({character: d.get(character) - 1})
                    characterCount -= 1
                else:
                    continue
            reverse = list(charSet)
            reverse.reverse()

            for character in reverse:
                if d.get(character) > 0:
                    result += character
                    d.update({character: d.get(character) - 1})
                    characterCount -= 1
                else:
                    continue

        return result

