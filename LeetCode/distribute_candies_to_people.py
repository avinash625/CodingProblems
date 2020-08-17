class Solution(object):
    def distributeCandies(self, candies, num_people):
        """
        :type candies: int
        :type num_people: int
        :rtype: List[int]
        """
        candiesCount = [0 for x in range(0, num_people)]

        candiesSum = 0
        candy = 1
        person = 0

        while (candiesSum + candy <= candies):
            candiesCount[person] += candy
            candiesSum += candy
            candy += 1
            person = (person + 1) % num_people

        candiesCount[person] += candies - candiesSum

        return candiesCount
