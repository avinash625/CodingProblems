class Solution(object):
    def shortestToChar(self, S, C):
        """
        :type S: str
        :type C: str
        :rtype: List[int]
        """
        result = [float("inf") for x in range(0, len(S))]
        lastPosition = float("inf")

        for index in range(0, len(S)):
            if S[index] == C:
                result[index] = 0
                lastPosition = index
            else:
                if result[index] > index - lastPosition:
                    result[index] = abs(index - lastPosition)

        lastPosition = float("inf")
        for index in range(len(S) - 1, -1, -1):
            if S[index] == C:
                result[index] = 0
                lastPosition = index
            else:
                if result[index] > lastPosition - index:
                    result[index] = abs(lastPosition - index)
        return result

