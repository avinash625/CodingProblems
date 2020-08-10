class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        firstRow = "qwertyuiop"
        secondRow = "asdfghjkl"
        thirdRow = "zxcvbnm"

        d = {}
        for c in firstRow:
            d.update({c: 1})
        for c in secondRow:
            d.update({c: 2})
        for c in thirdRow:
            d.update({c: 3})

        result = []

        for wordValue in words:
            word = wordValue.lower()
            homeRow = d.get(word[0])
            valid = True
            for c in word:
                if homeRow != d.get(c):
                    print word + " is not in same row"
                    valid = False
                    break
            if valid:
                result.append(wordValue)

        return result
