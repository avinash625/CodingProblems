class Solution(object):
    def bitwiseComplement(self, N):
        """
        :type N: int
        :rtype: int
        """
        num = N
        numInBinary = bin(num)
        result = ""
        for x in numInBinary[2:]:
            if x == "0":
                result = result + "1"
            elif x == '1':
                result = result + "0"
        return (int(result, 2))


