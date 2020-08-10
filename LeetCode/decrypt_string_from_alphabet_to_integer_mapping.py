class Solution(object):
    def freqAlphabets(self, s):
        """
        :type s: str
        :rtype: str
        """
        d = {}
        value = 1
        for char in "abcdefghi":
            d.update({str(value): char})
            value = value + 1
        for char in "jklmnopqrstuvwxyz":
            d.update({str(value): char})
            value = value + 1

        print d

        result = ""
        tokens = s.split("#")
        a = []
        for token in tokens:
            if token.strip() == "":
                pass
            else:
                a.append(token)
        tokens = a
        print tokens
        for token in tokens[:-1]:
            print "working"
            if len(token) > 2:
                for char in token[:-2]:
                    result = result + d.get(char)
                result = result + d.get(token[-2:])
            elif len(token) == 2:
                print token
                result = result + d.get(token)
            else:
                result = result + d.get(token)

        if s[-1] == '#':
            token = tokens[-1]
            if len(token) >= 2:
                for char in token[:-2]:
                    result = result + d.get(char)
                result = result + d.get(token[-2:])
                print(result)
        else:
            token = tokens[-1]
            for char in token:
                result = result + d.get(char)
        return result
