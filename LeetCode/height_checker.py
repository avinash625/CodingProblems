class Solution(object):
    def heightChecker(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        heights1 = heights[:]
        heights1 = sorted(heights1)
        # print(heights1)

        count = 0
        for index in range(0, len(heights)):
            if heights1[index] != heights[index]:
                count += 1
        return count
