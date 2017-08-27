"""
Problem Link:
https://www.hackerrank.com/challenges/recursive-digit-sum/problem
"""


def getSum(number):
    if number<10:
        return number
    else:
        tempsum = 0
        while number > 0:
            tempsum = tempsum + number%10
            number = number/10
    return getSum(tempsum)



values = raw_input().split(' ')
result = 0
for x in values[0]:
    result = result + int(x)
print getSum(result*int(values[1]))
